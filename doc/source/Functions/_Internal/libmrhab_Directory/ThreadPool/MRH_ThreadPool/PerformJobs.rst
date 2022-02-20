PerformJobs
===========
The PerformJobs function is used to perform all currently added jobs
with their modules.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhab/ThreadPool/MRH_ThreadPool.h"


Syntax
------
.. code-block:: c

    void PerformJobs() noexcept;


Parameters
----------
None.

Return Value
------------
None.

Remarks
-------
* The function will wait until all jobs are performed.

Code Examples
-------------
None.