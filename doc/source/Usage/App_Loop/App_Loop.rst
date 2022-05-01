*********************
Main Application Loop
*********************
libmrhab is meant to be used together with the libmrh library, which 
supplies the default application functions. These function can be found 
in the following libmrh headers:

.. code-block:: c

    #include <libmrh/MRH_AppLoop.h>
    #include <libmrh.h> // Includes libmrh/MRH_AppLoop.h

All functions declared in the MRH_AppLoop header have to be implemented 
by the user application to be usable. The main libmrhab functions used 
will be placed inside the defined application functions.

The libmrhab functions then build on top of the default application loop 
used by MRH applications and allows for programming with a multithreaded 
event callback structure using modules.

Context Creation
----------------
The first action required is to create a libmrhab context by using 
the :doc:`../../Functions/libmrhab/libmrhab_0` function. 
This context is used to manage the module stack and multithreaded 
event callback structure.

The context should be created in the applications **MRH_Init** 
function to allow for easy application termination on issues.

Creating a context requires a top level module to be given as a 
starting point. This module then be used for updating the application, 
allowing a module stack to be created.

The created module should be decided on by the given launch command id 
and (if given) launch input, allowing the application to start at different 
points depending on the requested user action.

.. code-block:: c

    ...
    libmrhab* p_Context = NULL;
    ...

    int MRH_Init(const char* p_LaunchInput, int i_LaunchCommandID)
    {
        int i_ThreadCount = 2; // Use 2 callback threads
        std::unique_ptr<MRH_Module> p_TopModule;
        
        try
        {
            switch (i_LaunchCommandID)
            {
                case 3:
                    p_TopModule = std::make_unique<SpecialModule>();
                    break;
                default:
                    p_TopModule = std::make_unique<DefaultModule>();
                    break;
            }
            
            // Create the library context, setting up the module stack
            // and thread pool for event jobs
            p_Context = new libmrhab(p_TopModule, 
                                     i_ThreadCount);
            return 0;
        }
        catch (MRH_ABException& e)
        {
            printf("Init failed! Error: %s\n", e.what());
            return -1;
        }
    }


Adding Event Jobs
-----------------
All events handed to libmrhab are seen as jobs to be performed by 
the modules. 
These jobs will be given to the currently active module by triggering 
a callback function defined in each module. 
The callback function of a module will never be called on the main 
thread.

The addition of jobs for modules should be handled in the 
**MRH_ReceiveEvent** function to be able to directly hand off 
recieved events to the library.

The library will first check if the current module is able to handle 
the event job by calling the modules 
:doc:`../../Functions/libmrhab_Directory/Module/MRH_Module/CanHandleEvent` 
function to make sure that the module support the event.
:doc:`../../Functions/libmrhab_Directory/Module/MRH_Module/HandleEvent` 
is then used to recieve each event as a callback. 

Both functions used have to be implemented by the current module, otherwise 
an exception will be thrown.

.. code-block:: c

    ...
    libmrhab* p_Context; // Existing, valid
    ...

    void MRH_ReceiveEvent(const MRH_Event* p_Event)
    {
        try
        {
            // Add received event as library thread pool job
            // for the current module
            p_Context->AddJob(p_Event);
        }
        catch (MRH_ABException& e)
        {
            printf("Failed to add job! Error %s\n", e.what());
        }
    }


Updating Modules
----------------
libmrhab gives the current application module a specific point at 
which it can update itself based on the received events. This 
update point can be chosen by the application, but it is recommended 
to place the module update inside the **MRH_SendEvent** function 
to ensure that all updates happen on the main thread.

The library will use the 
:doc:`../../Functions/libmrhab_Directory/Module/MRH_Module/Update` 
function of the current module to perform the module update when calling 
the :doc:`../../Functions/libmrhab/Update` function. The update will be 
performed once all thread jobs have been completed. This function will also 
return information about wether the application should close or continue.

Events which are generated inside modules should be stored in the 
:doc:`../../Classes/libmrhab_Directory/MRH_EventStorage` singleton class. 
These events can then be returned in the **MRH_SendEvent** function to 
send them to platform services.

.. code-block:: c

    ...
    libmrhab* p_Context; // Existing, valid
    bool b_CloseApp = false;
    ...

    MRH_Event* MRH_SendEvent(void)
    {
        // We update the module first, but this is actually 
        // not a requirement. It just makes events sendable 
        // faster.
        // We flag with a boolean to prevent calling module 
        // updates for every SendEvent call
        static bool b_UpdateModules = true;
        
        if (b_UpdateModules == true)
        {
            try
            {
                // Perform the update first, generating module events
                LIBMRHAB_UPDATE_RESULT b_Result = p_Context->Update();
                
                // App closing requested?
                if (b_Result == LIBMRHAB_UPDATE_CLOSE_APP)
                {
                    // Set app closure, and then send remaining events 
                    // generated this module update
                    b_CloseApp = true;
                }
            }
            catch (MRH_ABException& e)
            {
                printf("Failed to update modules! Error %s\n", e.what());
            
                // Stop sending immediatly to get to MRH_CanExit()
                b_CloseApp = true;
                return NULL;
            }
            
            // Reset, next calls don't update
            b_UpdateModules = false;
        }
        
        // Send the oldest available event and remove it from storage
        MRH_Event* p_Event = MRH_EventStorage::Singleton().GetEvent(true);
        
        // Is the container empty now with nothing left to send?
        if (p_Event == NULL)
        {
            // All generated events are sent, next call should update again
            b_UpdateModules = true;
        }
        
        return p_Event;
    }
    

Closing the Application
-----------------------
A application using libmrhab closes when either the module stack is empty 
(last module popped) or if SIGTERM was received by the application parent.

Handling expected application closure is handled by simply storing the 
module update result and returning it in the **MRH_CanExit** function.

.. code-block:: c

    ...
    bool b_CloseApp = true;
    ...

    int MRH_CanExit(void)
    {
        return b_CloseApp == true ? 0 : -1;
    }


Returning 0 for the **MRH_CanExit** function or recieving SIGTERM will 
both call the **MRH_Exit** function. The **MRH_Exit** function should 
be used to simply deallocate the library context, closing the thread 
pool and cleaning the module stack before closing the application.

.. code-block:: c

    ...
    libmrhab* p_Context; // Existing, valid
    ...

    void MRH_Exit(void)
    {
        // Check NULL for the rare case where SIGTERM hits before MRH_Init (or during)
        if (p_Context != NULL)
        {
            delete p_Context;
        }
    }
