event_cast
==========
The event_cast macro defines the cast type used based on the build 
configuration.

Header
------
The macro definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/MRH_Module.h>


Definition
----------
The defined cast type in the header is as follows:

.. code-block:: c

    #ifdef DEBUG
        #define event_cast dynamic_cast
    #else
        #define event_cast static_cast
    #endif