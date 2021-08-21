UpdateCurrent
=============
The UpdateCurrent function is used to update the module currently 
in use.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhab/Module/MRH_ModuleStack.h"


Syntax
------
.. code-block:: c

    MRH_MODULESTACK_RESULT UpdateCurrent();


Parameters
----------
None.

Return Value
------------
:doc:`../../../../../Macros/_Internal/libmrhab_Directory/Module/MRH_ModuleStack/MRH_MODULESTACK_CONTINUE` 
if the app should continue to update, 
:doc:`../../../../../Macros/_Internal/libmrhab_Directory/Module/MRH_ModuleStack/MRH_MODULESTACK_CLOSE_APP` 
if the app should be closed.

Remarks
-------
* Exceptions thrown in modules will be thrown by this function.

Code Examples
-------------
None.