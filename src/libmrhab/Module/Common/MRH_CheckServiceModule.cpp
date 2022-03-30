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

// C / C++

// External

// Project
#include "../../../../include/libmrhab/libmrhab/Module/Common/MRH_CheckServiceModule.h"


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_CheckServiceModule::MRH_CheckServiceModule(Service e_Service,
                                               MRH_Uint32 u32_TimeoutMS,
                                               bool& b_ServiceAvailable) : MRH_Module("MRH_CheckServiceModule"),
                                                                           c_Timer(),
                                                                           e_Service(e_Service),
                                                                           b_ServiceAvailable(b_ServiceAvailable),
                                                                           e_Result(NOT_SET)
{
    this->b_ServiceAvailable = false;
    
    MRH_EventStorage& c_Storage = MRH_EventStorage::Singleton();
    
    switch (e_Service)
    {
        case LISTEN:
            c_Storage.Add(MRH_EVD_CreateEvent(MRH_EVENT_LISTEN_AVAIL_U, NULL, 0));
            break;
        case SAY:
            c_Storage.Add(MRH_EVD_CreateEvent(MRH_EVENT_SAY_AVAIL_U, NULL, 0));
            break;
        case PASSWORD:
            c_Storage.Add(MRH_EVD_CreateEvent(MRH_EVENT_PASSWORD_AVAIL_U, NULL, 0));
            break;
        case USER:
            c_Storage.Add(MRH_EVD_CreateEvent(MRH_EVENT_USER_AVAIL_U, NULL, 0));
            break;
        case APPLICATION:
            c_Storage.Add(MRH_EVD_CreateEvent(MRH_EVENT_APP_AVAIL_U, NULL, 0));
            break;
            
        default:
            throw MRH_ModuleException("MRH_CheckServiceModule", 
                                      "Unknown service to check!");
    }
    
    c_Timer.SetTimer(u32_TimeoutMS);
}

MRH_CheckServiceModule::~MRH_CheckServiceModule() noexcept
{}

//*************************************************************************************
// Update
//*************************************************************************************

void MRH_CheckServiceModule::HandleEvent(const MRH_Event* p_Event) noexcept
{
    MRH_EvD_Base_ServiceAvail_S_t c_ServiceAvail;
    
    if (MRH_EVD_ReadEvent(&c_ServiceAvail, p_Event->u32_Type, p_Event) < 0)
    {
        MRH_ModuleLogger::Singleton().Log("MRH_CheckServiceModule", "Failed to read service available event!",
                                          "MRH_CheckServiceModule.cpp", __LINE__);
        return;
    }
    
    switch (p_Event->u32_Type)
    {
        case MRH_EVENT_LISTEN_AVAIL_S:
            if (e_Service != LISTEN)
            {
                return;
            }
            break;
        case MRH_EVENT_SAY_AVAIL_S:
            if (e_Service != SAY)
            {
                return;
            }
            break;
        case MRH_EVENT_PASSWORD_AVAIL_S:
            if (e_Service != PASSWORD)
            {
                return;
            }
            break;
        case MRH_EVENT_USER_AVAIL_S:
            if (e_Service != USER)
            {
                return;
            }
            break;
        case MRH_EVENT_APP_AVAIL_S:
            if (e_Service != APPLICATION)
            {
                return;
            }
            break;
            
        default:
            return;
    }
    
    if (c_ServiceAvail.u8_Available == MRH_EVD_BASE_RESULT_SUCCESS)
    {
        e_Result = AVAILABLE;
    }
    else
    {
        e_Result = UNAVAILABLE;
    }
}

MRH_Module::Result MRH_CheckServiceModule::Update()
{
    if (e_Result != NOT_SET || c_Timer.GetTimerFinished() == true)
    {
        b_ServiceAvailable = (e_Result == AVAILABLE ? true : false);
        return MRH_Module::FINISHED_POP;
    }
    
    return MRH_Module::IN_PROGRESS;
}

std::shared_ptr<MRH_Module> MRH_CheckServiceModule::NextModule()
{
    throw MRH_ModuleException("MRH_CheckServiceModule",
                              "No module to switch to!");
}

//*************************************************************************************
// Getters
//*************************************************************************************

bool MRH_CheckServiceModule::CanHandleEvent(MRH_Uint32 u32_Type) noexcept
{
    switch (u32_Type)
    {
        case MRH_EVENT_LISTEN_AVAIL_S:
        case MRH_EVENT_SAY_AVAIL_S:
        case MRH_EVENT_PASSWORD_AVAIL_S:
        case MRH_EVENT_USER_AVAIL_S:
        case MRH_EVENT_APP_AVAIL_S:
            return true;
            
        default:
            return false;
    }
}
