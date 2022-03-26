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
#include "../../../../include/libmrhab/libmrhab/Module/Common/MRH_SpeechInputModule.h"


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_SpeechInputModule::MRH_SpeechInputModule(std::string& s_Input,
                                             MRH_Uint32 u32_TimeoutMS) noexcept : MRH_Module("MRH_SpeechInputModule"),
                                                                                  c_Timer(),
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
    
    if (strnlen(c_String.p_String, MRH_EVD_L_STRING_BUFFER_MAX_TERMINATED) > 0)
    {
        std::lock_guard<std::mutex> c_Guard(c_Mutex);
        
        s_Input = c_String.p_String;
    }
}

MRH_Module::Result MRH_SpeechInputModule::Update()
{
    if (c_Timer.GetTimerFinished() == true)
    {
        return MRH_Module::FINISHED_POP;
    }
    else
    {
        std::lock_guard<std::mutex> c_Guard(c_Mutex);
        
        if (s_Input.size() > 0)
        {
            return MRH_Module::FINISHED_POP;
        }
    }
    
    return MRH_Module::IN_PROGRESS;
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
