/**
 *  libmrhab
 *  Copyright (C) 2021 - 2022 Jens Brörken
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
#include <deque>
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
     *  \param p_Event The received user event.
     *  \param p_Module The module meant to process the user event.
     */
    
    void AddJob(const MRH_Event* p_Event, std::shared_ptr<MRH_Module>& p_Module);
    
    //*************************************************************************************
    // Wait
    //*************************************************************************************
    
    /**
     *  Start and wait for all thread pool jobs. This function is thread safe.
     */
    
    void PerformJobs() noexcept;
    
private:
    
    //*************************************************************************************
    // Types
    //*************************************************************************************
    
    struct Job
    {
    public:
        
        //*************************************************************************************
        // Constructor / Destructor
        //*************************************************************************************
        
        /**
         *  Default constructor.
         *
         *  \param p_Event The event job to add.
         *  \param p_Module The module performing the event job.
         */
        
        Job(MRH_Event* p_Event,
            std::shared_ptr<MRH_Module>& p_Module) noexcept;
        
        /**
         *  Copy constructor. Disabled for this class.
         *
         *  \param c_Job Job class source.
         */
        
        Job(Job const& c_Job) = delete;
        
        /**
         *  Default destructor.
         */
        
        ~Job() noexcept;
        
        //*************************************************************************************
        // Data
        //*************************************************************************************
        
        std::mutex c_Mutex;
        
        MRH_Event* p_Event;
        std::shared_ptr<MRH_Module> p_Module;
    };
    
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
    std::deque<std::thread> dq_Thread;
    std::atomic<bool> b_Update;
    
    // Job List
    std::mutex c_JobMutex;
    std::condition_variable c_JobCondition;
    std::deque<Job> dq_Job;
    std::atomic<size_t> us_TotalCount;
    std::atomic<size_t> us_AvailableCount;
    
    // Wait
    std::mutex c_WaitMutex;
    std::condition_variable c_WaitCondition;
    
protected:

};

#endif /* MRH_ThreadPool_h */
