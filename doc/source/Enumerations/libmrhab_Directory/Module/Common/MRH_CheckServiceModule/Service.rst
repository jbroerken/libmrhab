Service
=======
The Service enumeration lists all services known to the check service 
module.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/Common/MRH_CheckServiceModule.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    enum Service
    {
        LISTEN = 0,
        SAY = 1,
        PASSWORD = 2,
        USER = 3,
        APPLICATION = 4,
        NOTIFICATION = 5,
        
        SERVICE_MAX = NOTIFICATION,
        
        SERVICE_COUNT = SERVICE_MAX + 1
    };


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - LISTEN
      - Listen platform service.
    * - SAY
      - Say platform service.
    * - PASSWORD
      - Password platform service.
    * - USER
      - User platform service.
    * - APPLICATION
      - Application platform service.
    * - NOTIFICATION
      - Notification platform service.
    * - SERVICE_MAX
      - The highest value in this enumeration.
    * - SERVICE_COUNT
      - The amount of values in this enumeration.