*****
Usage
*****
libmrhab works by building a module stack which then uses the currently 
used module to perform callbacks with event jobs, which the module then 
reacts to to build events of its own.

Using libmrh requires the main application loop of MRH applications to 
implement library function usage as well as custom modules created by 
inheriting from the base module class and then overwriting the virtual 
module member functions.

.. toctree::
  :maxdepth: 1

  App_Loop/App_Loop
  Module/Module