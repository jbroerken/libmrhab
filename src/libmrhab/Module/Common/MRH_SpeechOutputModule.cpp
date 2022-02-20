/**
 *  MRH_SpeechOutputModule.cpp
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
#include "../../../../include/libmrhab/libmrhab/Module/Common/MRH_SpeechOutputModule.h"


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_SpeechOutputModule::MRH_SpeechOutputModule(std::string s_Output,
                                               MRH_Uint32 u32_TimeoutMS,
                                               MRH_Uint32 u32_OutputID) : MRH_Module("MRH_SpeechOutputModule"),
                                                                          c_Timer(),
                                                                          u32_SentOutputID(u32_OutputID),
                                                                          u32_RecievedOutputID(u32_OutputID + 1)
{
    MRH_ModuleLogger::Singleton().Log("MRH_SpeechOutputModule", "Sending output: " +
                                                                s_Output +
                                                                " (ID: " +
                                                                std::to_string(u32_SentOutputID) +
                                                                ")",
                                      "MRH_SpeechOutputModule.cpp", __LINE__);
    
    MRH_EventStorage& c_Storage = MRH_EventStorage::Singleton();
    MRH_Event* p_Event = NULL;
    MRH_EvD_S_String_U c_Data;
    
    // ID never changes, part get incremented
    c_Data.u32_ID = u32_SentOutputID;
    c_Data.u32_Part = 0;
    
    while (s_Output.size() > 0)
    {
        // Reset last
        memset((c_Data.p_String), '\0', MRH_EVD_S_STRING_BUFFER_MAX_TERMINATED);
        
        // Define string type and copy
        if (s_Output.size() <= MRH_EVD_S_STRING_BUFFER_MAX)
        {
            strncpy(c_Data.p_String, s_Output.c_str(), s_Output.size());
            s_Output.clear();
            
            c_Data.u8_Type = MRH_EVD_L_STRING_END;
        }
        else
        {
            strncpy(c_Data.p_String, s_Output.c_str(), MRH_EVD_S_STRING_BUFFER_MAX);
            s_Output.erase(0, MRH_EVD_S_STRING_BUFFER_MAX);
            
            c_Data.u8_Type = MRH_EVD_L_STRING_UNFINISHED;
        }
        
        // Create next event
        if (p_Event == NULL && (p_Event = MRH_EVD_CreateEvent(MRH_EVENT_SAY_STRING_U, NULL, 0)) == NULL)
        {
            throw MRH_ModuleException("MRH_SpeechOutputModule", 
                                      "Failed to allocate new output event!");
        }
        else if (MRH_EVD_SetEvent(p_Event, MRH_EVENT_SAY_STRING_U, &c_Data) < 0)
        {
            MRH_EVD_DestroyEvent(p_Event);
            throw MRH_ModuleException("MRH_SpeechOutputModule", 
                                      "Failed to set output event!");
        }
        
        // Attempt to add to out storage
        try
        {
            c_Storage.Add(p_Event);
            p_Event = NULL;
        }
        catch (MRH_ABException& e)
        {
            MRH_EVD_DestroyEvent(p_Event);
            throw MRH_ModuleException("MRH_SpeechOutputModule", 
                                      "Failed to send output: " + e.what2());
        }
        
        // Part added, identify next part
        c_Data.u32_Part += 1;
    }
    
    // All sent, start timer and wait
    c_Timer.SetTimer(u32_TimeoutMS);
}

MRH_SpeechOutputModule::~MRH_SpeechOutputModule() noexcept
{}

//*************************************************************************************
// Update
//*************************************************************************************

void MRH_SpeechOutputModule::HandleEvent(const MRH_Event* p_Event) noexcept
{
    // @NOTE: CanHandleEvent() allows skipping event type check!
    MRH_EvD_S_String_S c_String;
    
    if (MRH_EVD_ReadEvent(&c_String, p_Event->u32_Type, p_Event) < 0)
    {
        MRH_ModuleLogger::Singleton().Log("MRH_SpeechOutputModule", "Failed to read string event!",
                                          "MRH_SpeechOutputModule.cpp", __LINE__);
    }
    else
    {
        MRH_ModuleLogger::Singleton().Log("MRH_SpeechOutputModule", "Recieved output performed: " +
                                          std::to_string(c_String.u32_ID),
                                          "MRH_SpeechOutputModule.cpp", __LINE__);
        
        u32_RecievedOutputID = c_String.u32_ID;
    }
}

MRH_Module::Result MRH_SpeechOutputModule::Update()
{
    if (u32_SentOutputID == u32_RecievedOutputID || c_Timer.GetTimerFinished() == true)
    {
        return MRH_Module::FINISHED_POP;
    }
    
    return MRH_Module::IN_PROGRESS;
}

std::shared_ptr<MRH_Module> MRH_SpeechOutputModule::NextModule()
{
    throw MRH_ModuleException("MRH_SpeechOutputModule",
                              "No module to switch to!");
}

//*************************************************************************************
// Getters
//*************************************************************************************

bool MRH_SpeechOutputModule::CanHandleEvent(MRH_Uint32 u32_Type) noexcept
{
    switch (u32_Type)
    {
        case MRH_EVENT_SAY_STRING_S:
            return true;
            
        default:
            return false;
    }
}
