Singleton
=========
The Singleton function is used to recieve the single instance of the event 
storage container.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/MRH_EventStorage.h>


Syntax
------
.. code-block:: c

    static MRH_EventStorage& Singleton() noexcept;


Parameters
----------
None.

Return Value
------------
The singleton instance of the event storage class.

Remarks
-------
* This function is thread safe.

Code Examples
-------------
None.