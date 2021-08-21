libmrhab (Default Constructor)
==============================
The default libmrhab constructor function is used to construct the libmrhab 
class.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab.h>


Syntax
------
.. code-block:: c

    libmrhab(std::unique_ptr<MRH_Module> p_TopModule,
             size_t us_ThreadCount);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_TopModule
      - The first module to use in the module stack.
    * - us_ThreadCount
      - The number of threads to use for callback performing or 0 for single threaded.
      

Return Value
------------
None.

Remarks
-------
* The library thread pool and module stack starts on construction finish.
* The thread count equals the number of threads spawned in the callback thread 
  pool. Using 0 will not create a thread pool and rely on single threaded callbacks 
  on the main thread.
* A valid (non-NULL) top module has to be provided.

Code Examples
-------------
None.