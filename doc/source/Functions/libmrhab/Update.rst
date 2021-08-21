Update (libmrhab)
=================
The Update function is used to update the module stack.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab.h>


Syntax
------
.. code-block:: c

    LIBMRHAB_UPDATE_RESULT Update();


Parameters
----------
None.

Return Value
------------
:doc:`../../Macros/libmrhab/LIBMRHAB_UPDATE_CONTINUE` if the app should continue 
to update, :doc:`../../Macros/libmrhab/LIBMRHAB_UPDATE_CLOSE_APP` if the app 
should be closed.

Remarks
-------
* Exceptions thrown in modules will be thrown by this function.

Code Examples
-------------
None.