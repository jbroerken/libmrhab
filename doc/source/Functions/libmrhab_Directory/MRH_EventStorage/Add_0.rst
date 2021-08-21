Add (Class Event)
=================
The Add function is used to add an event to the storage container.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/MRH_EventStorage.h>


Syntax
------
.. code-block:: c

    void Add(MRH_EVBase const& c_Event) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - c_Event
      - The event to add.


Return Value
------------
None.

Remarks
-------
* This function is thread safe.
* The given event will be used to construct a C-style event.

Code Examples
-------------
None.