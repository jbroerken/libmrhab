AddJob
======
The AddJob function is used to add an event job to be performed with a callback.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab.h>


Syntax
------
.. code-block:: c

    void AddJob(const MRH_Event* p_Event);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The event to perform a module callback for.


Return Value
------------
None.

Remarks
-------
* This function is thread safe.
* The event will be used to create a job and is not required to be
  valid after use.
* The created job will either be given to the thread pool for the module 
  callback or used immediatly on the caller thread.

Code Examples
-------------
None.