CanHandleEvent
==============
The CanHandleEvent function is used to check if a module should 
recieve a event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/MRH_Module.h>


Syntax
------
.. code-block:: c

    virtual bool CanHandleEvent(MRH_Uint32 u32_Type) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - u32_Type
      - The event type identifier.


Return Value
------------
true if the module can handle the event, false if not.

Remarks
-------
* This function is meant to be overwritten by the inheriting class.
* This function will be called on the main or a background thread, 
  depending on implementation of module updating by the application.

Code Examples
-------------
None.