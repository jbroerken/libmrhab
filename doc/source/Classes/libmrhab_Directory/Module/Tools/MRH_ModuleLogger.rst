MRH_ModuleLogger
================
The MRH_ModuleLogger class is used to log module messages and exceptions.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/Tools/MRH_ModuleLogger.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/Tools/MRH_ModuleLogger/Log_0`
      - Public
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/Tools/MRH_ModuleLogger/Log_1`
      - Public
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/Tools/MRH_ModuleLogger/MRH_ModuleLogger_0`
      - Private
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/Tools/MRH_ModuleLogger/~MRH_ModuleLogger`
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
      - Visbility
    * - c_Mutex
      - std::mutex
      - The mutex lock for multithreading.
      - Private
    * - f_File
      - std::ofstream
      - The message log file in use.
      - Private


Remarks
-------
* This class starts existing as soon as the singleton function was used.
* This class can not be constructed freely.
* This class exists as a single shared instance.
* Log files are written in the current working directory.