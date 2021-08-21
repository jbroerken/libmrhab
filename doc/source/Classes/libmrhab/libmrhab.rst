libmrhab
========
The libmrhab class is used to setup and control the libmrhab library. The class 
manages the current module state and handles jobs which are meant to be processed 
by the modules in use.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhab.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../Functions/libmrhab/libmrhab_0`
      - Public
    * - :doc:`../../Functions/libmrhab/~libmrhab`
      - Public
    * - :doc:`../../Functions/libmrhab/AddJob`
      - Public
    * - :doc:`../../Functions/libmrhab/Update`
      - Public
    * - :doc:`../../Functions/libmrhab/IsValidEventType`
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
    * - p_ModuleStack
      - MRH_ModuleStack*
      - The module stack used for module mangement.
      - Private
    * - p_ThreadPool
      - MRH_ThreadPool*
      - The thread pool used to perform callbacks for jobs.
      - Private


Remarks
-------
* This class should be constructed first before using any library functionality.