/**
 *  libmrhab
 *  Copyright (C) 2021 Jens Brörken
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

// C / C++

// External

// Project
#include "../include/libmrhab/libmrhab.h"
#include "./libmrhab/Module/MRH_ModuleStack.h"
#include "./libmrhab/ThreadPool/MRH_ThreadPool.h"


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

libmrhab::libmrhab(std::unique_ptr<MRH_Module> p_TopModule,
                   size_t us_ThreadCount) : p_ModuleStack(NULL),
                                            p_ThreadPool(NULL)
{
    if (p_TopModule == NULL)
    {
        throw MRH_ABException("Invalid top module!");
    }
    
    try
    {
        p_ModuleStack = new MRH_ModuleStack(p_TopModule);
        
        // Use callbacks in thread pool only if requested
        if (us_ThreadCount > 0)
        {
            p_ThreadPool = new MRH_ThreadPool(us_ThreadCount);
        }
    }
    catch (MRH_ABException& e)
    {
        throw MRH_ABException(e.what());
    }
}

libmrhab::~libmrhab() noexcept
{
    if (p_ThreadPool != NULL)
    {
        delete p_ThreadPool;
    }
    
    if (p_ModuleStack != NULL)
    {
        delete p_ModuleStack;
    }
}

//*************************************************************************************
// Update
//*************************************************************************************

void libmrhab::AddJob(const MRH_Event* p_Event)
{
    if (p_Event == NULL || IsValidEventType(p_Event->u32_Type) == false)
    {
        throw MRH_ABException("Invalid job!");
    }
    
    std::shared_ptr<MRH_Module> p_Module(p_ModuleStack->GetCurrent());
    
    if (p_Module == NULL)
    {
        throw MRH_ABException("No module to handle job!");
    }
    else if (p_Module->CanHandleEvent(p_Event->u32_Type) == false)
    {
        return;
    }
    
    MRH_EVBase* p_Job;
    
    try
    {
        // Create a shared event here, given event is returned to parent
        p_Job = libmrhcevs::Create(p_Event);
        
        // Handle by thread pool or single threaded
        if (p_ThreadPool != NULL)
        {
            p_ThreadPool->AddJob(p_Job, p_Module);
        }
        else
        {
            p_Module->HandleEvent(p_Job);
            delete p_Job; // We need to delete the job ourselfs here
        }
    }
    catch (MRH_CEVSException& e)
    {
        // No job deletion since thats what failed
        throw MRH_ABException("CEVS Issue: " + e.what2());
    }
    catch (MRH_ABException& e)
    {
        delete p_Job;
        throw;
    }
}

LIBMRHAB_UPDATE_RESULT libmrhab::Update()
{
    try
    {
        if (p_ModuleStack->UpdateCurrent() == MRH_MODULESTACK_CLOSE_APP)
        {
            return LIBMRHAB_UPDATE_CLOSE_APP;
        }
        
        return LIBMRHAB_UPDATE_CONTINUE;
    }
    catch (MRH_ABException& e)
    {
        throw;
    }
}

//*************************************************************************************
// Getters
//*************************************************************************************

bool libmrhab::IsValidEventType(MRH_Uint32 u32_Type) noexcept
{
    switch (u32_Type)
    {
        /* Event Version 1 */
            
        // System
        case MRH_EVENT_UNK:
        case MRH_EVENT_PS_RESET_REQUEST_U:
        case MRH_EVENT_PS_RESET_ACKNOLEDGED_U:
            
        // Custom
        case MRH_EVENT_CUSTOM_CUSTOM_COMMAND_U:
            
        // Listen
        case MRH_EVENT_LISTEN_AVAIL_U:
        case MRH_EVENT_LISTEN_GET_METHOD_U:
        case MRH_EVENT_LISTEN_CUSTOM_COMMAND_U:
            
        // Say
        case MRH_EVENT_SAY_AVAIL_U:
        case MRH_EVENT_SAY_STRING_U:
        case MRH_EVENT_SAY_GET_METHOD_U:
        case MRH_EVENT_SAY_CUSTOM_COMMAND_U:
            
        // Password
        case MRH_EVENT_PASSWORD_AVAIL_U:
        case MRH_EVENT_PASSWORD_CHECK_U:
        case MRH_EVENT_PASSWORD_SET_U:
        case MRH_EVENT_PASSWORD_CUSTOM_COMMAND_U:
            
        // User
        case MRH_EVENT_USER_AVAIL_U:
        case MRH_EVENT_USER_ACCESS_DOCUMENTS_U:
        case MRH_EVENT_USER_ACCESS_PICTURES_U:
        case MRH_EVENT_USER_ACCESS_MUSIC_U:
        case MRH_EVENT_USER_ACCESS_VIDEOS_U:
        case MRH_EVENT_USER_ACCESS_DOWNLOADS_U:
        case MRH_EVENT_USER_ACCESS_CLIPBOARD_U:
        case MRH_EVENT_USER_ACCESS_INFO_PERSON_U:
        case MRH_EVENT_USER_ACCESS_INFO_RESIDENCE_U:
        case MRH_EVENT_USER_ACCESS_CLEAR_U:
        case MRH_EVENT_USER_GET_LOCATION_U:
        case MRH_EVENT_USER_CUSTOM_COMMAND_U:
            
        // Application
        case MRH_EVENT_APP_AVAIL_U:
        case MRH_EVENT_APP_LAUNCH_SOA_U:
        case MRH_EVENT_APP_LAUNCH_SOA_TIMER_U:
        case MRH_EVENT_APP_LAUNCH_SOA_CLEAR_U:
        case MRH_EVENT_APP_LAUNCH_SOA_CLEAR_TIMER_U:
        case MRH_EVENT_APP_GET_DEFAULT_PACKAGE_U:
        case MRH_EVENT_APP_SET_DEFAULT_PACKAGE_U:
        case MRH_EVENT_APP_CUSTOM_COMMAND_U:
            
        // Notification
        case MRH_EVENT_NOTIFICATION_AVAIL_U:
        case MRH_EVENT_NOTIFICATION_CREATE_APP_U:
        case MRH_EVENT_NOTIFICATION_CREATE_SERVICE_U:
        case MRH_EVENT_NOTIFICATION_DESTROY_APP_U:
        case MRH_EVENT_NOTIFICATION_GET_WAITING_U:
        case MRH_EVENT_NOTIFICATION_GET_NEXT_U:
        case MRH_EVENT_NOTIFICATION_CUSTOM_COMMAND_U:
            return false;
            
        // Allowed Service
        default:
            return true;
    }
}
