MRH_Module
==========
The MRH_Module class serves as the module base used to implement custom 
application modules.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Modules/MRH_Module.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../Functions/libmrhab_Directory/Module/MRH_Module/~MRH_Module`
      - Public
    * - :doc:`../../../Functions/libmrhab_Directory/Module/MRH_Module/HandleEvent`
      - Public
    * - :doc:`../../../Functions/libmrhab_Directory/Module/MRH_Module/Update`
      - Public
    * - :doc:`../../../Functions/libmrhab_Directory/Module/MRH_Module/NextModule`
      - Public
    * - :doc:`../../../Functions/libmrhab_Directory/Module/MRH_Module/GetName`
      - Public
    * - :doc:`../../../Functions/libmrhab_Directory/Module/MRH_Module/CanHandleEvent`
      - Public
    * - :doc:`../../../Functions/libmrhab_Directory/Module/MRH_Module/MRH_Module_0`
      - Protected


Enumerations
------------
.. list-table::
    :header-rows: 1

    * - Enumeration
      - Visibility
    * - :doc:`../../../Enumerations/libmrhab_Directory/Module/MRH_Module/Result`
      - Public
      

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
    * - s_Name
      - std::string
      - The module name.
      - Private
      

Remarks
-------
* This class can only be constructed by the inheriting class.
* All virtual functions are meant to be overwritten, exceptions will be
  thrown if base functions are used.
* Module names are not required (although recommended) to be unique.