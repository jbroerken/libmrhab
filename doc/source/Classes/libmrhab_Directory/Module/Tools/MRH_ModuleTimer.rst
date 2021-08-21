MRH_ModuleTimer
===============
The MRH_ModuleTimer class offers a simple timer solution for timing based 
actions like response event timeouts.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/Tools/MRH_ModuleTimer.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/Tools/MRH_ModuleTimer/MRH_ModuleTimer_0`
      - Public
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/Tools/MRH_ModuleTimer/~MRH_ModuleTimer`
      - Public
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/Tools/MRH_ModuleTimer/ResetTimer`
      - Public
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/Tools/MRH_ModuleTimer/SetTimer`
      - Public
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/Tools/MRH_ModuleTimer/GetTimerFinished`
      - Public
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/Tools/MRH_ModuleTimer/GetTimerSet`
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
    * - c_End
      - std::chrono::high_resolution_clock::time_point
      - The time point (based on system time) when the timer is reached.
      - Private
    * - b_Set
      - bool
      - The flag indicating if the timer was set or not.
      - Private


Remarks
-------
None.