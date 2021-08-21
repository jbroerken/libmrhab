GetEvent (Simple)
=================
The simple GetEvent function is used to get the first (next) event in the 
storage container.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/MRH_EventStorage.h>


Syntax
------
.. code-block:: c

    MRH_Event* GetEvent() noexcept;


Parameters
----------
None.

Return Value
------------
The event if one exists, NULL if no event exists.

Remarks
-------
* This function is thread safe.

Code Examples
-------------
None.