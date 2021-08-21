Result
======
The Result enumeration is used to describe the type of update result 
for a module update.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/MRH_Module.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    enum Result
    {
        IN_PROGRESS = 0, // Keep updating
        
        FINISHED_APPEND = 1, // Finished updating, append a new module level
        FINISHED_REPLACE = 2, // Finished updating, replace current module
        FINISHED_POP = 3, // Finished updating, go back one level
        
        RESULT_MAX = FINISHED_POP,
        
        RESULT_COUNT = RESULT_MAX + 1
    };


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - IN_PROGRESS
      - The module is still being used.
    * - FINISHED_APPEND
      - The module is finished and wants to append a new module after itself.
    * - FINISHED_REPLACE
      - The module is finished and wants to replace itself with a new module.
    * - FINISHED_POP
      - The module is finished and wants to remove itself, returning to the 
        module before it.
    * - RESULT_MAX
      - The highest value in this enumeration.
    * - RESULT_COUNT
      - The amount of values in this enumeration.