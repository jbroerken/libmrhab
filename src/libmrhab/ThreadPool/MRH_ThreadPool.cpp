/**
 *  libmrhab
 *  Copyright (C) 2021 Jens Brörken
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty.  In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *
 *  2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *
 *  3. This notice may not be removed or altered from any source distribution.
 */

// C / C++
#include <string>

// External

// Project
#include "./MRH_ThreadPool.h"


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_ThreadPool::MRH_ThreadPool(size_t us_ThreadCount) : b_Update(true)
{
    if (us_ThreadCount == 0)
    {
        throw MRH_ABException("Invalid thread count for thread pool!");
    }
    
    try
    {
        while (us_ThreadCount > 0)
        {
            l_Thread.emplace_back(Update, this);
            --us_ThreadCount;
        }
    }
    catch (std::exception& e)
    {
        throw MRH_ABException(e.what());
    }
}

MRH_ThreadPool::~MRH_ThreadPool() noexcept
{
    b_Update = false;
    c_Condition.notify_all();
    
    for (auto& Thread : l_Thread)
    {
        Thread.join();
    }
}

//*************************************************************************************
// Add
//*************************************************************************************

void MRH_ThreadPool::AddJob(MRH_EVBase*& p_Event, std::shared_ptr<MRH_Module> p_Module)
{
    try
    {
        c_JobMutex.lock();
        l_Job.emplace_back(std::make_pair(p_Event, p_Module));
        c_JobMutex.unlock();
        
        p_Event = NULL;
        
        c_Condition.notify_one();
    }
    catch (std::exception& e)
    {
        throw MRH_ABException(e.what());
    }
}

//*************************************************************************************
// Update
//*************************************************************************************

void MRH_ThreadPool::Update(MRH_ThreadPool* p_Instance) noexcept
{
    JobList& l_Job = p_Instance->l_Job;
    
    MRH_EVBase* p_Event;
    std::shared_ptr<MRH_Module> p_Module;
    
    while (p_Instance->b_Update == true)
    {
        // Check for available jobs
        p_Instance->c_JobMutex.lock();
        
        if (l_Job.size() == 0)
        {
            p_Instance->c_JobMutex.unlock();
            
            std::unique_lock<std::mutex> c_UniqueLock(p_Instance->c_ConditionMutex);
            p_Instance->c_Condition.wait(c_UniqueLock);
        
            continue;
        }
        else
        {
            p_Event = l_Job.begin()->first;
            p_Module = l_Job.begin()->second;
            l_Job.pop_front();
            
            p_Instance->c_JobMutex.unlock();
        }
        
        // Job available, perform with module
        p_Module->HandleEvent(p_Event);
        
        // Event has been processed, clean up
        delete p_Event;
    }
}
