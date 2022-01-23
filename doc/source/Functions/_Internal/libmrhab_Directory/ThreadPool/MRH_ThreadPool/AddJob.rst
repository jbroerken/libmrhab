AddJob
======
The AddJob function is used to add a event to the job list.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhab/ThreadPool/MRH_ThreadPool.h"


Syntax
------
.. code-block:: c

    void AddJob(const MRH_Event* p_Event,
                std::shared_ptr<MRH_Module> p_Module);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The event to add as a job.
    * - p_Module
      - The module which will recieve the event job.


Return Value
------------
None.

Remarks
-------
* The given event is copied.

Code Examples
-------------
None.