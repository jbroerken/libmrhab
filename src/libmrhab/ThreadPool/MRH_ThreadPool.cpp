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
#include <libmrhevdata.h>

// Project
#include "./MRH_ThreadPool.h"


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_ThreadPool::MRH_ThreadPool(size_t us_ThreadCount) : b_Update(true),
                                                        us_TotalCount(0),
                                                        us_AvailableCount(0)
{
    if (us_ThreadCount == 0)
    {
        throw MRH_ABException("Invalid thread count for thread pool!");
    }
    
    try
    {
        while (us_ThreadCount > 0)
        {
            dq_Thread.emplace_back(Update, this);
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
    
    c_JobCondition.notify_all();
    c_WaitCondition.notify_all();
    
    for (auto& Thread : dq_Thread)
    {
        Thread.join();
    }
}

MRH_ThreadPool::Job::Job(MRH_Event* p_Event,
                         std::shared_ptr<MRH_Module>& p_Module) noexcept : p_Event(p_Event),
                                                                           p_Module(p_Module)
{}

MRH_ThreadPool::Job::~Job() noexcept
{}

//*************************************************************************************
// Add
//*************************************************************************************

void MRH_ThreadPool::AddJob(const MRH_Event* p_Event, std::shared_ptr<MRH_Module>& p_Module)
{
    MRH_Event* p_Job = MRH_EVD_CopyEvent(p_Event);
    
    if (p_Job == NULL)
    {
        throw MRH_ABException("Failed to copy event for job!");
    }
    
    // First try to reuse a entry
    // @NOTE: Job deque never shrinks!
    for (size_t i = 0; i < us_TotalCount; ++i)
    {
        // Job free to be checked?
        if (dq_Job[i].c_Mutex.try_lock() == false)
        {
            continue;
        }
        
        // Job can be added here?
        if (dq_Job[i].p_Event == NULL)
        {
            dq_Job[i].p_Event = p_Job;
            dq_Job[i].p_Module = p_Module;
            
            dq_Job[i].c_Mutex.unlock();
            
            us_AvailableCount += 1;
            return;
        }
        else
        {
            dq_Job[i].c_Mutex.unlock();
        }
    }
    
    // No free entry, add a new one
    try
    {
        // Lock for multithreading
        std::lock_guard<std::mutex> c_Guard(c_JobMutex);
        
        dq_Job.emplace_back(p_Job,
                            p_Module);
        us_TotalCount += 1;
        us_AvailableCount += 1;
    }
    catch (std::exception& e)
    {
        throw MRH_ABException("Failed to add entry: " + std::string(e.what()));
    }
}

//*************************************************************************************
// Perform
//*************************************************************************************

void MRH_ThreadPool::PerformJobs() noexcept
{
    // Jobs exist?
    if (us_AvailableCount == 0)
    {
        return;
    }
    
    // Notify all worker threads
    c_JobCondition.notify_all();
    
    // Now wait for finish
    std::unique_lock<std::mutex> c_Lock(c_WaitMutex);
    c_WaitCondition.wait(c_Lock);
}

//*************************************************************************************
// Update
//*************************************************************************************

void MRH_ThreadPool::Update(MRH_ThreadPool* p_Instance) noexcept
{
    std::mutex& c_JobMutex = p_Instance->c_JobMutex;
    
    std::condition_variable& c_JobCondition = p_Instance->c_JobCondition;
    std::condition_variable& c_WaitCondition = p_Instance->c_WaitCondition;
    
    std::deque<Job>& dq_Job = p_Instance->dq_Job;
    std::atomic<size_t>& us_TotalCount = p_Instance->us_TotalCount;
    std::atomic<size_t>& us_AvailableCount = p_Instance->us_AvailableCount;
    
    while (p_Instance->b_Update == true)
    {
        // Work on all possible jobs
        for (size_t i = 0; i < us_TotalCount; ++i)
        {
            // Job usable?
            if (dq_Job[i].c_Mutex.try_lock() == false)
            {
                continue;
            }
            else if (dq_Job[i].p_Event == NULL)
            {
                dq_Job[i].c_Mutex.unlock();
                continue;
            }
            
            // Valid, perform
            dq_Job[i].p_Module->HandleEvent(dq_Job[i].p_Event);
            
            dq_Job[i].p_Event = MRH_EVD_DestroyEvent(dq_Job[i].p_Event);
            dq_Job[i].p_Module.reset();
            
            dq_Job[i].c_Mutex.unlock();
            
            us_AvailableCount -= 1;
            
            // All work done?
            if (us_AvailableCount == 0)
            {
                // Notify waiting that jobs were performed
                c_WaitCondition.notify_all();
            }
        }
        
        // Now wait for new jobs
        std::unique_lock<std::mutex> c_Lock(c_JobMutex);
        c_JobCondition.wait(c_Lock);
    }
}
