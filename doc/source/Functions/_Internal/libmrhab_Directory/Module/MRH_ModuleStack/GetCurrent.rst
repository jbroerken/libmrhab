GetCurrent
==========
The GetCurrent function is used to get the module currently in use.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhab/Module/MRH_ModuleStack.h"


Syntax
------
.. code-block:: c

    std::shared_ptr<MRH_Module> GetCurrent() noexcept;


Parameters
----------
None.

Return Value
------------
The module currently in use.

Remarks
-------
* NULL is returned if no module is currently used.

Code Examples
-------------
None.