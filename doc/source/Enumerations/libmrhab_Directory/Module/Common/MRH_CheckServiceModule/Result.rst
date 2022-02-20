Result
======
The Result enumeration is used to describe the type of service result 
for the check service module.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/Common/MRH_CheckServiceModule.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    enum Result
    {
        NOT_SET = 0,
        AVAILABLE = 1,
        UNAVAILABLE = 2,
        
        RESULT_MAX = UNAVAILABLE,
        
        RESULT_COUNT = RESULT_MAX + 1
    };


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - NOT_SET
      - No response from the service.
    * - AVAILABLE
      - The service is available and usable.
    * - UNAVAILABLE
      - The service is available but not usable.
    * - RESULT_MAX
      - The highest value in this enumeration.
    * - RESULT_COUNT
      - The amount of values in this enumeration.