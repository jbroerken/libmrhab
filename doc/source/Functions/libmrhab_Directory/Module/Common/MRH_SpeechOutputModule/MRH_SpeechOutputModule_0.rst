MRH_SpeechOutputModule (Default Constructor)
============================================
The default MRH_SpeechOutputModule constructor function is used 
to construct the MRH_SpeechOutputModule class.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/Common/MRH_SpeechOutputModule.h>


Syntax
------
.. code-block:: c

    MRH_SpeechOutputModule(std::string s_String,
                           MRH_Uint32 u32_TimeoutMS,
                           MRH_Uint32 u32_OutputID);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_Output
      - The string to perform as speech output.
	* - u32_TimeoutMS
	  - The time in milliseconds to wait until output is performed.
	* - u32_OutputID
	  - The output id to use.


Return Value
------------
None.

Remarks
-------
* A random output id is chosen if one was not supplied.

Code Examples
-------------
None.