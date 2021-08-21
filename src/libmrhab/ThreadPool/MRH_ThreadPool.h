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

#ifndef MRH_ThreadPool_h
#define MRH_ThreadPool_h

// C / C++
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unordered_map>
#include <list>
#include <utility>
#include <memory>

// External

// Project
#include "../../../include/libmrhab/libmrhab/Module/MRH_Module.h"
#include "../../../include/libmrhab/libmrhab/MRH_ABException.h"


class MRH_ThreadPool
{
public:

    //*************************************************************************************
    // Destructor
    //*************************************************************************************

    /**
     *  Default constructor.
     *
     *  \param us_ThreadCount The number of worker threads to use.
     */
    
    MRH_ThreadPool(size_t us_ThreadCount);
    
    /**
     *  Copy constructor. Disabled for this class.
     *
     *  \param c_ThreadPool ThreadPool class source.
     */

    MRH_ThreadPool(MRH_ThreadPool const& c_ThreadPool) = delete;
    
    /**
     *  Default destructor.
     */

    ~MRH_ThreadPool() noexcept;
    
    //*************************************************************************************
    // Add
    //*************************************************************************************
    
    /**
     *  Add a event as a job. This function is thread safe.
     *
     *  \param p_Event The recieved user event.
     *  \param p_Module The module meant to process the user event.
     */
    
    void AddJob(MRH_EVBase*& p_Event, std::shared_ptr<MRH_Module> p_Module);
    
private:
    
    //*************************************************************************************
    // Types
    //*************************************************************************************
    
    typedef std::list<std::pair<MRH_EVBase*, std::shared_ptr<MRH_Module>>> JobList;
    
    //*************************************************************************************
    // Update
    //*************************************************************************************

    /**
     *  Update the thread pool.
     *
     *  \param p_Instance The thread pool instance to update with.
     */
    
    static void Update(MRH_ThreadPool* p_Instance) noexcept;
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    // Thread
    std::list<std::thread> l_Thread;
    std::atomic<bool> b_Update;
    std::mutex c_ConditionMutex;
    std::mutex c_JobMutex;
    std::condition_variable c_Condition;
    
    // Job List
    JobList l_Job;
    
protected:

};

#endif /* MRH_ThreadPool_h */
