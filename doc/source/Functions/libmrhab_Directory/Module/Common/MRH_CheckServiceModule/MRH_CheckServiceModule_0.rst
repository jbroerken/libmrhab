MRH_CheckServiceModule (Default Constructor)
============================================
The default MRH_CheckServiceModule constructor function is used 
to construct the MRH_CheckServiceModule class.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/Common/MRH_CheckServiceModule.h>


Syntax
------
.. code-block:: c

    MRH_CheckServiceModule(Service e_Service,
						   MRH_Uint32 u32_TimeoutMS,
						   bool& b_ServiceAvailable);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - e_Service
      - The platform service to check.
	* - u32_TimeoutMS
	  - The check service timeout in milliseconds.
	* - b_ServiceAvailable 
	  - The services available flag to set.


Return Value
------------
None.

Remarks
-------
* The service available flag is reset on construction.

Code Examples
-------------
None.