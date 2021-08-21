NextModule
==========
The NextModule function is used to retrieve the next module in the module 
stack once updating a module returned a finished result.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhab/Module/MRH_Module.h>


Syntax
------
.. code-block:: c

    virtual std::shared_ptr<MRH_Module> NextModule();


Parameters
----------
None.

Return Value
------------
The next module.

Remarks
-------
* This function is meant to be overwritten by the inheriting class.
* This function is only called once after the update function returns
  a finished result.

Code Examples
-------------
None.