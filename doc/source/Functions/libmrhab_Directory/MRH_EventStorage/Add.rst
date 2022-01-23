Add
===
The Add function is used to add an event to the storage container.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/MRH_EventStorage.h>


Syntax
------
.. code-block:: c

    void Add(MRH_Event* p_Event) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The event to add.


Return Value
------------
None.

Remarks
-------
* This function is thread safe.
* The given event will be added without copying.

Code Examples
-------------
None.