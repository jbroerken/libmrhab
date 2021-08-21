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
    * - l_Thread
      - std::list<std::thread>
      - The active thread pool threads.
      - Private
    * - b_Update
      - std::atomic<bool>
      - The thread run control flag.
      - Private
    * - c_ConditionMutex
      - std::mutex
      - The mutex lock for the thread wait condition.
      - Private
    * - c_JobMutex
      - std::mutex
      - The mutex lock for the job list.
      - Private
    * - c_Condition
      - std::condition_variable
      - The thread wait condition.
      - Private
    * - l_Job
      - std::list<MRH_EVBase*>
      - The jobs waiting to be performed by the threads.
      - Private


Remarks
-------
None.