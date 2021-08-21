~MRH_ThreadPool
===============
The ~MRH_ThreadPool function is the default destructor for the MRH_ThreadPool 
class.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhab/ThreadPool/MRH_ThreadPool.h"


Syntax
------
.. code-block:: c

    ~MRH_ThreadPool() noexcept;


Parameters
----------
None.

Return Value
------------
None.

Remarks
-------
* This destructor will stop all threads and clear all jobs from the pool queue.

Code Examples
-------------
None.