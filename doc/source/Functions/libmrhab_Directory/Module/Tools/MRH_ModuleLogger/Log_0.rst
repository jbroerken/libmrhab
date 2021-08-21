Log (Standard Message)
======================
The standard message Log function is used to log any module 
message to file.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/Tools/MRH_ModuleLogger.h>


Syntax
------
.. code-block:: c

    void Log(std::string const& s_Module, 
             std::string const& s_Message, 
             std::string const& s_File, 
             size_t us_Line) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_Module
      - The module name.
    * - s_Message
      - The log message string.
    * - s_File
      - The null terminated name of the file where the log message originated.
    * - us_Line
      - The file line where the log message originated.
      

Return Value
------------
None.

Remarks
-------
* All log messages will be written to the same log file.
* The log file will be kept open as long as the singleton lives.
* This function is thread safe.

Code Examples
-------------
None.