MRH_ModuleStack (Default Constructor)
=====================================
The default MRH_ModuleStack constructor function is used to construct the 
MRH_ModuleStack class with a given thread count.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhab/Module/MRH_ModuleStack.h"


Syntax
------
.. code-block:: c

    MRH_ModuleStack(std::unique_ptr<MRH_Module>& p_TopModule);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_TopModule
      - The top module to start with.


Return Value
------------
None.

Remarks
-------
* The modul has to be valid.
* The pointer will be released and stored as a shared pointer.

Code Examples
-------------
None.