MRH_CheckServiceModule
======================
The MRH_CheckServiceModule class implements a common module used to 
check the availability of services.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Modules/Common/MRH_CheckServiceModule.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/Common/MRH_CheckServiceModule/MRH_CheckServiceModule_0`
      - Public
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/Common/MRH_CheckServiceModule/~MRH_CheckServiceModule`
      - Public
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/MRH_Module/HandleEvent`
      - Public
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/MRH_Module/Update`
      - Public
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/MRH_Module/NextModule`
      - Public
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/MRH_Module/CanHandleEvent`
      - Public


Enumerations
------------
.. list-table::
    :header-rows: 1

    * - Enumeration
      - Visibility
    * - :doc:`../../../Enumerations/libmrhab_Directory/Module/Common/MRH_CheckServiceModule/Service`
      - Public
    * - :doc:`../../../Enumerations/libmrhab_Directory/Module/Common/MRH_CheckServiceModule/Result`
      - Private
      

Nested Classes
--------------
None.

Inherited Classes
-----------------
.. list-table::
    :header-rows: 1

    * - Class
      - Visibility
    * - :doc:`../MRH_Module`
      - Public
	  

Variables
---------
.. list-table::
    :header-rows: 1

    * - Name
      - Type
      - Description
      - Visbility
    * - c_Timer
      - MRH_ModuleTimer
      - The module timer used for timeout checking.
      - Private
	* - e_Service
	  - Service
	  - The service to check.
	  - Private
	* - b_ServiceAvailable
	  - bool&
	  - The service available flag to set.
	  - Private
	* - e_Result
	  - std::atomic<Result>
	  - The internal result for the service check.
	  - Private
      

Remarks
-------
* The module is thread safe.