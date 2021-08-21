GetCount
========
The GetCount function is used to return the amount of currently stored events 
in the storage container.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/MRH_EventStorage.h>


Syntax
------
.. code-block:: c

    size_t GetCount() noexcept;


Parameters
----------
None.

Return Value
------------
The number of events stored.

Remarks
-------
* This function is thread safe.

Code Examples
-------------
None.