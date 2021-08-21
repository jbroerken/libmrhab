MRH_ModuleException
===================
The MRH_ModuleException class stores messages for exceptions specific to 
used modules.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/MRH_ModuleException.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../Functions/libmrhab_Directory/Module/MRH_ModuleException/MRH_ModuleException_0`
      - Public
    * - :doc:`../../../Functions/libmrhab_Directory/Module/MRH_ModuleException/MRH_ModuleException_1`
      - Public
    * - :doc:`../../../Functions/libmrhab_Directory/Module/MRH_ModuleException/~MRH_ModuleException`
      - Public
    * - :doc:`../../../Functions/libmrhab_Directory/Module/MRH_ModuleException/what`
      - Public
    * - :doc:`../../../Functions/libmrhab_Directory/Module/MRH_ModuleException/what2`
      - Public
    * - :doc:`../../../Functions/libmrhab_Directory/Module/MRH_ModuleException/module`
      - Public
    * - :doc:`../../../Functions/libmrhab_Directory/Module/MRH_ModuleException/module2`
      - Public


Enumerations
------------
None.

Nested Classes
--------------
None.

Inherited Classes
-----------------
.. list-table::
    :header-rows: 1

    * - Class
      - Visibility
    * - std::exception
      - Public


Variables
---------
.. list-table::
    :header-rows: 1

    * - Name
      - Type
      - Description
      - Visbility
    * - s_Module
      - std::string
      - The module this exception relates to.
      - Private
    * - s_Message
      - std::string
      - The exception message.
      - Private


Remarks
-------
None.