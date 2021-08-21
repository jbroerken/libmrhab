MRH_ModuleLogger (Default Constructor)
======================================
The default MRH_ModuleLogger constructor function is used to construct 
the MRH_ModuleLogger class.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/Tools/MRH_ModuleLogger.h>


Syntax
------
.. code-block:: c

    MRH_ModuleLogger() noexcept;


Parameters
----------
None.

Return Value
------------
None.

Remarks
-------
* This constructor is completely private due to the class being a singleton.
* The log file will be opened on class construction.

Code Examples
-------------
None.