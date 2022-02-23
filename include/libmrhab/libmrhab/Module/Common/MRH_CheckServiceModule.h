/**
 *  libmrhab
 *  Copyright (C) 2021 - 2022 Jens Brörken
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty.  In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *
 *  2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *
 *  3. This notice may not be removed or altered from any source distribution.
 */

#ifndef MRH_CheckServiceModule_h
#define MRH_CheckServiceModule_h

// C / C++
#include <atomic>

// External

// Project
#include "../MRH_Module.h"


class MRH_CheckServiceModule : public MRH_Module
{
public:
    
    //*************************************************************************************
    // Types
    //*************************************************************************************
    
    enum Service
    {
        LISTEN = 0,
        SAY = 1,
        PASSWORD = 2,
        USER = 3,
        APPLICATION = 4,
        NOTIFICATION = 5,
        
        SERVICE_MAX = NOTIFICATION,
        
        SERVICE_COUNT = SERVICE_MAX + 1
    };
    
    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************
    
    /**
     *  Default constructor.
     *
     *  \param e_Service The platform service to check.
     *  \param u32_TimeoutMS The check service timeout in milliseconds.
     *  \param b_ServiceAvailable The services available flag to set.
     */
    
    MRH_CheckServiceModule(Service e_Service,
                           MRH_Uint32 u32_TimeoutMS,
                           bool& b_ServiceAvailable);
    
    /**
     *  Default destructor.
     */
    
    ~MRH_CheckServiceModule() noexcept;
    
    //*************************************************************************************
    // Update
    //*************************************************************************************
    
    /**
     *  Hand a recieved event to the module.
     *
     *  \param p_Event The recieved event.
     */
    
    void HandleEvent(const MRH_Event* p_Event) noexcept override;
    
    /**
     *  Perform a module update.
     *
     *  \return The module update result.
     */
    
    MRH_Module::Result Update() override;
    
    /**
     *  Get the module to switch to.
     *
     *  \return The module switch information.
     */
    
    std::shared_ptr<MRH_Module> NextModule() override;
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Check if the module can handle a event.
     *
     *  \param u32_Type The type of the event to handle.
     *
     *  \return true if the event can be used, false if not.
     */
    
    bool CanHandleEvent(MRH_Uint32 u32_Type) noexcept override;
    
private:
    
    //*************************************************************************************
    // Types
    //*************************************************************************************
    
    enum Result
    {
        NOT_SET = 0,
        AVAILABLE = 1,
        UNAVAILABLE = 2,
        
        RESULT_MAX = UNAVAILABLE,
        
        RESULT_COUNT = RESULT_MAX + 1
    };
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    MRH_ModuleTimer c_Timer;
    
    Service e_Service;
    bool& b_ServiceAvailable;
    
    std::atomic<Result> e_Result;
    
protected:
    
};

#endif /* MRH_CheckServiceModule_h */
