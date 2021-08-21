MRH_ModuleException (const char* Constructor)
=============================================
The const char* MRH_ModuleException constructor function is used to construct 
the MRH_ModuleException class with a const char* message source.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/MRH_ModuleException.h>


Syntax
------
.. code-block:: c

    MRH_ModuleException(const char* p_Module,
                        const char* p_Message);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Module
      - The module name.
    * - p_Message
      - The null terminated exception message.


Return Value
------------
None.

Remarks
-------
None.

Code Examples
-------------
None.