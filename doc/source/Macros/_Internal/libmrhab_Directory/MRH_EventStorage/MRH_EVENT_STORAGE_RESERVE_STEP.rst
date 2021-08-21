MRH_EVENT_STORAGE_RESERVE_STEP
==============================
The MRH_EVENT_STORAGE_RESERVE_STEP macro defines the amount of event space 
reserved if the event storage vector capacity limit is reached. This value 
will be added to the total capacity to provide.

Header
------
The macro definition can be found in the following file:

.. code-block:: c

    libmrhab/MRH_EventStorage.cpp


Definition
----------
The defined reserve size in the source file is as follows:

.. code-block:: c

    #define MRH_EVENT_STORAGE_RESERVE_STEP 100