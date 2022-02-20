/**
 *  MRH_CheckServiceModule.h
 *
 *  This file is part of the MRH project.
 *  See the AUTHORS file for Copyright information.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
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
