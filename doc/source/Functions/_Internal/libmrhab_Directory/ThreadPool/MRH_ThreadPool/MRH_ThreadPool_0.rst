MRH_ThreadPool (Default Constructor)
====================================
The default MRH_ThreadPool constructor function is used to construct the 
MRH_ThreadPool class with a given thread count.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhab/ThreadPool/MRH_ThreadPool.h"


Syntax
------
.. code-block:: c

    MRH_ThreadPool(size_t us_ThreadCount);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - us_ThreadCount
      - The number of worker threads to create.


Return Value
------------
None.

Remarks
-------
* The thread count has to be greater than 0.

Code Examples
-------------
None.