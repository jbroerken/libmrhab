MRH_SpeechInputModule
=====================
The MRH_SpeechInputModule class implements a common module used to 
recieve strings from listen input.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Modules/Common/MRH_SpeechInputModule.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/Common/MRH_SpeechInputModule/MRH_SpeechInputModule_0`
      - Public
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/Common/MRH_SpeechInputModule/~MRH_SpeechInputModule`
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
	* - c_Mutex
	  - std::mutex
	  - Recieved event thread lock.
	  - Private
	* - m_Part
	  - std::map<MRH_Uint32, std::string>
	  - The recieved string parts.
	  - Private
	* - u32_StringID
	  - MRH_Uint32
	  - The id for the recieved string.
	  - Private
	* - u32_EndPart
	  - MRH_Uint32
	  - The part id for the last string part.
	  - Private
	* - s_Input
	  - std::string&
	  - The input to set with recieved string parts.
	  - Private
      

Remarks
-------
* The module is thread safe.