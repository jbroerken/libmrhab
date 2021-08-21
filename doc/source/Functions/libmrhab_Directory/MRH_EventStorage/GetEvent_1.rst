GetEvent (With Remover)
=======================
The GetEvent function with remover is used to get the first (next) event in the 
storage container and remove said event from the container if requested.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/MRH_EventStorage.h>


Syntax
------
.. code-block:: c

    MRH_Event* GetEvent(bool b_RemoveFront) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - b_RemoveFront
      - Wether or not to remove the returned event.


Return Value
------------
The event if one exists, NULL if no event exists.

Remarks
-------
* This function is thread safe.
* The event will not be deallocated if removed.

Code Examples
-------------
None.