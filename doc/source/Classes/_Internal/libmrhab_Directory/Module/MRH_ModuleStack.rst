MRH_ModuleStack
===============
The MRH_ModuleStack class is handles the module list hierachy and 
manages is used to update all modules.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include "libmrhab/Module/MRH_ModuleStack.h"


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../../Functions/_Internal/libmrhab_Directory/Module/MRH_ModuleStack/MRH_ModuleStack_0`
      - Public
    * - :doc:`../../../../Functions/_Internal/libmrhab_Directory/Module/MRH_ModuleStack/~MRH_ModuleStack`
      - Public
    * - :doc:`../../../../Functions/_Internal/libmrhab_Directory/Module/MRH_ModuleStack/UpdateCurrent`
      - Public
    * - :doc:`../../../../Functions/_Internal/libmrhab_Directory/Module/MRH_ModuleStack/GetCurrent`
      - Public


Enumerations
------------
None.

Nested Classes
--------------
None.

Inherited Classes
-----------------
None.

Variables
---------
.. list-table::
    :header-rows: 1

    * - Name
      - Type
      - Description
      - Visbility
    * - l_Module
      - std::list<std::shared_ptr<MRH_Module>>
      - The module hierachy, sorted first (top) to current (last).
      - Private


Remarks
-------
None.