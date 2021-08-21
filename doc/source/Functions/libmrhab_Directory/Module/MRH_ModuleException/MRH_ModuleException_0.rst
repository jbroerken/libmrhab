MRH_ModuleException (std::string Constructor)
=============================================
The std::string MRH_ModuleException constructor function is used to construct 
the MRH_ModuleException class with a std::string message source.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/MRH_ModuleException.h>


Syntax
------
.. code-block:: c

    MRH_ModuleException(std::string const& s_Module,
                        std::string const& s_Message);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_Module
      - The module name.
    * - s_Message
      - The exception message.


Return Value
------------
None.

Remarks
-------
None.

Code Examples
-------------
None.