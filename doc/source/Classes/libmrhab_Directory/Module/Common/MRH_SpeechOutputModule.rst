MRH_SpeechOutputModule
======================
The MRH_SpeechOutputModule class implements a common module used to 
send strings as speech output.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Modules/Common/MRH_SpeechOutputModule.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/Common/MRH_SpeechOutputModule/MRH_SpeechOutputModule_0`
      - Public
    * - :doc:`../../../../Functions/libmrhab_Directory/Module/Common/MRH_SpeechOutputModule/~MRH_SpeechOutputModule`
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
	* - u32_SentOutputID
	  - const MRH_Uint32
	  - The output id used to send speech output.
	  - Private
	* - u32_RecievedOutputID
	  - std::atomic<MRH_Uint32>
	  - The output id recieved for the last performed output.
	  - Private
      

Remarks
-------
* The module is thread safe.