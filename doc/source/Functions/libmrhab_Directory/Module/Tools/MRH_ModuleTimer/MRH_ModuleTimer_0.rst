MRH_ModuleTimer (Default Constructor)
=====================================
The default MRH_ModuleTimer constructor function is used to construct 
the MRH_ModuleTimer class.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/Tools/MRH_ModuleTimer.h>


Syntax
------
.. code-block:: c

    MRH_ModuleTimer(MRH_Uint32 u32_TimeMS = 0) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - u32_TimeMS
      - The timer in milliseconds.
      

Return Value
------------
None.

Remarks
-------
* Using 0 as the time immediatly sets the timer to finished.

Code Examples
-------------
None.