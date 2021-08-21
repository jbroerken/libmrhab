MRH_EventStorage
================
The MRH_EventStorage class is used to store events intended for platform 
services. 

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/MRH_EventStorage.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../Functions/libmrhab_Directory/MRH_EventStorage/Singleton`
      - Public
    * - :doc:`../../Functions/libmrhab_Directory/MRH_EventStorage/Clear`
      - Public
    * - :doc:`../../Functions/libmrhab_Directory/MRH_EventStorage/Add_0`
      - Public
    * - :doc:`../../Functions/libmrhab_Directory/MRH_EventStorage/Add_1`
      - Public
    * - :doc:`../../Functions/libmrhab_Directory/MRH_EventStorage/RemoveFront`
      - Public
    * - :doc:`../../Functions/libmrhab_Directory/MRH_EventStorage/GetCount`
      - Public
    * - :doc:`../../Functions/libmrhab_Directory/MRH_EventStorage/GetEvent_0`
      - Public
    * - :doc:`../../Functions/libmrhab_Directory/MRH_EventStorage/GetEvent_1`
      - Public
    * - :doc:`../../Functions/libmrhab_Directory/MRH_EventStorage/MRH_EventStorage_0`
      - Private
    * - :doc:`../../Functions/libmrhab_Directory/MRH_EventStorage/~MRH_EventStorage`
      - Private


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
      - Visibility
    * - c_Mutex
      - std::mutex
      - The mutex lock for the event storage.
      - Private
    * - v_Event
      - std::vector<MRH_Event*>
      - All events added to the event storage.
      - Private


Remarks
-------
* This class starts existing as soon as the singleton function was used.
* This class can not be constructed freely.
* This class exists as a single shared instance.