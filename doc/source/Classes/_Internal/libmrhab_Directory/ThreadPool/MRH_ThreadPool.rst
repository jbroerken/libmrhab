MRH_ThreadPool
==============
The MRH_ThreadPool class is used to manage the thread pool update.
It remembers the given callbacks and adds jobs to thread which then 
call the given callbacks.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include "libmrhab/ThreadPool/MRH_ThreadPool.h"


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../../Functions/_Internal/libmrhab_Directory/ThreadPool/MRH_ThreadPool/MRH_ThreadPool_0`
      - Public
    * - :doc:`../../../../Functions/_Internal/libmrhab_Directory/ThreadPool/MRH_ThreadPool/~MRH_ThreadPool`
      - Public
    * - :doc:`../../../../Functions/_Internal/libmrhab_Directory/ThreadPool/MRH_ThreadPool/AddJob`
      - Public
    * - :doc:`../../../../Functions/_Internal/libmrhab_Directory/ThreadPool/MRH_ThreadPool/PerformJobs`
      - Public
    * - :doc:`../../../../Functions/_Internal/libmrhab_Directory/ThreadPool/MRH_ThreadPool/Update`
      - Private


Enumerations
------------
None.

Nested Classes
--------------
None.

Inherited Classes
-----------------
None.

Variables
---------
.. list-table::
    :header-rows: 1

    * - Name
      - Type
      - Description
      - Visbility
    * - dq_Thread
      - std::dque<std::thread>
      - The active thread pool threads.
      - Private
    * - b_Update
      - std::atomic<bool>
      - The thread run control flag.
      - Private
    * - c_JobMutex
      - std::mutex
      - The mutex lock for the job list.
      - Private
    * - c_JobCondition
      - std::condition_variable
      - The thread wait condition for the job list.
      - Private
    * - dq_Job
      - std::deque<Job>
      - The jobs waiting to be performed by the threads.
      - Private
	* - us_TotalCount
	  - std::atomic<size_t>
	  - The total count of job list slots.
	  - Private
	* - us_AvailableCount
	  - std::atomic<size_t>
	  - The amount of jobs available to perform.
	  - Private
    * - c_WaitMutex
      - std::mutex
      - The mutex lock for the thread starting jobs.
      - Private
    * - c_WaitCondition
      - std::condition_variable
      - The thread wait condition for the thread starting jobs.
      - Private


Remarks
-------
None.