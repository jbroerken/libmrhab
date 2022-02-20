Update
======
The Update function is run by each thread in the thread pool to 
hand jobs to their modules.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhab/ThreadPool/MRH_ThreadPool.h"


Syntax
------
.. code-block:: c

    void Update(MRH_ThreadPool* p_Instance) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Instance
      - The thread pool instance containing callbacks and 
        jobs.


Return Value
------------
None.

Remarks
-------
None.

Code Examples
-------------
None.