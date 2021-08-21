Update (MRH_Module)
===================
The Update function is used to update a module.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/MRH_Module.h>


Syntax
------
.. code-block:: c

    virtual Result Update();


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
The module update :doc:`../../../../Enumerations/libmrhab_Directory/Module/MRH_Module/Result`.

Remarks
-------
* This function is meant to be overwritten by the inheriting class.
* This function will be called on the main or a background thread, 
  depending on implementation of module updating by the application.

Code Examples
-------------
None.