HandleEvent
===========
The HandleEvent function is used to construct to recieve and process 
event in the module.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/MRH_Module.h>


Syntax
------
.. code-block:: c

    virtual void HandleEvent(const MRH_EVBase* p_Event) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The recieved event.


Return Value
------------
None.

Remarks
-------
* This function is meant to be overwritten by the inheriting class.
* This function will never be called on the main thread.

Code Examples
-------------
None.