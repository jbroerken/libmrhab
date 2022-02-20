/**
 *  MRH_SpeechInputModule.cpp
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
#include "../../../../include/libmrhab/libmrhab/Module/Common/MRH_SpeechInputModule.h"


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_SpeechInputModule::MRH_SpeechInputModule(std::string& s_Input,
                                             MRH_Uint32 u32_TimeoutMS) noexcept : MRH_Module("MRH_SpeechInputModule"),
                                                                                  c_Timer(),
                                                                                  u32_StringID(0),
                                                                                  u32_EndPart(((MRH_Uint32) - 1)),
                                                                                  s_Input(s_Input)
{
    this->s_Input = "";
    
    c_Timer.SetTimer(u32_TimeoutMS);
}

MRH_SpeechInputModule::~MRH_SpeechInputModule() noexcept
{}

//*************************************************************************************
// Update
//*************************************************************************************

void MRH_SpeechInputModule::HandleEvent(const MRH_Event* p_Event) noexcept
{
    MRH_EvD_L_String_S c_String;
    
    if (MRH_EVD_ReadEvent(&c_String, p_Event->u32_Type, p_Event) < 0)
    {
        MRH_ModuleLogger::Singleton().Log("MRH_SpeechInputModule", "Failed to read listen string event!",
                                          "MRH_SpeechInputModule.cpp", __LINE__);
        return;
    }
    
    // We need a lock here, editing multiple vars and map
    std::lock_guard<std::mutex> c_Guard(c_Mutex);
    
    // String id change? reset input
    if (u32_StringID != c_String.u32_ID)
    {
        MRH_ModuleLogger::Singleton().Log("MRH_SpeechInputModule", "Recieved new input with ID: " +
                                                                   std::to_string(c_String.u32_ID) +
                                                                   ", resetting input.",
                                          "MRH_SpeechInputModule.cpp", __LINE__);
        
        m_Part.clear();
        u32_StringID = c_String.u32_ID;
        u32_EndPart = ((MRH_Uint32) - 1);
    }
    
    // Add part
    m_Part.insert(std::make_pair(c_String.u32_Part, 
                                 c_String.p_String));
    
    // Set end if provided
    if (c_String.u8_Type == MRH_EVD_L_STRING_END)
    {
        u32_EndPart = c_String.u32_Part;
    }
}

MRH_Module::Result MRH_SpeechInputModule::Update()
{
    if (c_Timer.GetTimerFinished() == true)
    {
        return MRH_Module::FINISHED_POP;
    }
    
    // Still assembling?
    if (m_Part.size() <= u32_EndPart) // <=, size - 1 = endpart
    {
        return MRH_Module::IN_PROGRESS;
    }
    
    // Finished, assemble string
    MRH_Uint32 u32_NextPart = 0;
    
    for (auto& Part : m_Part)
    {
        if (Part.first != u32_NextPart)
        {
            s_Input = "";
            return MRH_Module::IN_PROGRESS;
        }
        
        s_Input += Part.second;
        ++u32_NextPart;
    }
    
    return MRH_Module::FINISHED_POP;
}

std::shared_ptr<MRH_Module> MRH_SpeechInputModule::NextModule()
{
    throw MRH_ModuleException("MRH_SpeechInputModule",
                              "No module to switch to!");
}

//*************************************************************************************
// Getters
//*************************************************************************************

bool MRH_SpeechInputModule::CanHandleEvent(MRH_Uint32 u32_Type) noexcept
{
    switch (u32_Type)
    {
        case MRH_EVENT_LISTEN_STRING_S:
            return true;
            
        default:
            return false;
    }
}
