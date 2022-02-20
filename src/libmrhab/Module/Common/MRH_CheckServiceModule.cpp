/**
 *  CheckService.cpp
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
        case NOTIFICATION:
            c_Storage.Add(MRH_EVD_CreateEvent(MRH_EVENT_NOTIFICATION_AVAIL_U, NULL, 0));
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
        case MRH_EVENT_NOTIFICATION_AVAIL_S:
            if (e_Service != NOTIFICATION)
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
        case MRH_EVENT_NOTIFICATION_AVAIL_S:
            return true;
            
        default:
            return false;
    }
}
