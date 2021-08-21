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
#include "../../include/libmrhab/libmrhab/MRH_EventStorage.h"

// Pre-defined
#ifndef MRH_EVENT_STORAGE_RESERVE_STEP
    #define MRH_EVENT_STORAGE_RESERVE_STEP 100
#endif


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_EventStorage::MRH_EventStorage() noexcept
{
    v_Event.reserve(MRH_EVENT_STORAGE_RESERVE_STEP);
}

MRH_EventStorage::~MRH_EventStorage() noexcept
{}

//*************************************************************************************
// Singleton
//*************************************************************************************

MRH_EventStorage& MRH_EventStorage::Singleton() noexcept
{
    static MRH_EventStorage c_EventStorage;
    return c_EventStorage;
}

//*************************************************************************************
// Clear
//*************************************************************************************

void MRH_EventStorage::Clear() noexcept
{
    std::lock_guard<std::mutex> c_Guard(c_Mutex);
    
    for (auto& Event : v_Event)
    {
        if (Event->p_Data != NULL)
        {
            free(Event->p_Data);
        }
        
        free(Event);
    }
    
    v_Event.clear();
}

//*************************************************************************************
// Add
//*************************************************************************************

void MRH_EventStorage::Add(MRH_EVBase const& c_Event)
{
    MRH_Event* p_Event;
    
    try
    {
        p_Event = c_Event.Build();
        Add(p_Event);
    }
    catch (MRH_CEVSException& e)
    {
        throw MRH_ABException("CEVS Issue: " + e.what2());
    }
    catch (MRH_ABException& e)
    {
        delete p_Event;
        throw;
    }
}

void MRH_EventStorage::Add(MRH_Event* p_Event)
{
    std::lock_guard<std::mutex> c_Guard(c_Mutex);
    
    try
    {
        if (v_Event.size() == v_Event.capacity())
        {
            v_Event.reserve(v_Event.capacity() + MRH_EVENT_STORAGE_RESERVE_STEP);
        }
        
        v_Event.emplace_back(p_Event);
    }
    catch (std::exception& e)
    {
        throw MRH_ABException(e.what());
    }
}

//*************************************************************************************
// Remove
//*************************************************************************************

void MRH_EventStorage::RemoveFront() noexcept
{
    if (v_Event.size() == 0)
    {
        return;
    }
    
    std::lock_guard<std::mutex> c_Guard(c_Mutex);
    v_Event.erase(v_Event.begin());
}

//*************************************************************************************
// Getters
//*************************************************************************************

size_t MRH_EventStorage::GetCount() noexcept
{
    std::lock_guard<std::mutex> c_Guard(c_Mutex);
    return v_Event.size();
}

MRH_Event* MRH_EventStorage::GetEvent() noexcept
{
    std::lock_guard<std::mutex> c_Guard(c_Mutex);
    return (v_Event.size() > 0 ? v_Event[0] : NULL);
}

MRH_Event* MRH_EventStorage::GetEvent(bool b_RemoveFront) noexcept
{
    std::lock_guard<std::mutex> c_Guard(c_Mutex);
    
    if (v_Event.size() == 0)
    {
        return NULL;
    }
    
    if (b_RemoveFront == true)
    {
        MRH_Event* p_Event = v_Event[0];
        v_Event.erase(v_Event.begin());
        
        return p_Event;
    }
    else
    {
        return v_Event[0];
    }
}
