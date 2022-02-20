MRH_SpeechInputModule (Default Constructor)
===========================================
The default MRH_SpeechInputModule constructor function is used 
to construct the MRH_SpeechInputModule class.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/Common/MRH_SpeechInputModule.h>


Syntax
------
.. code-block:: c

    MRH_SpeechInputModule(std::string& s_Input,
						  MRH_Uint32 u32_TimeoutMS);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_Input
      - The input recieved by listening.
	* - u32_TimeoutMS
	  - The input recieve timeout in milliseconds.


Return Value
------------
None.

Remarks
-------
* The input string is reset on construction.

Code Examples
-------------
None.