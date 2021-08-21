Log (Exception)
===============
The exception Log function is used to log a module exception 
to file.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/Tools/MRH_ModuleLogger.h>


Syntax
------
.. code-block:: c

    void Log(MRH_ModuleException const& c_Exception, 
             std::string const& s_File, 
             size_t us_Line) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - c_Exception
      - The module exception to log.
    * - s_File
      - The name of the file where the exception originated.
    * - us_Line
      - The file line where the exception originated.
      

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