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

#ifndef MRH_EventStorage_h
#define MRH_EventStorage_h

// C / C++
#include <mutex>
#include <vector>

// External
#include <libmrhcevs.h>

// Project
#include "./MRH_ABException.h"


class MRH_EventStorage
{
public:

    //*************************************************************************************
    // Singleton
    //*************************************************************************************

    /**
     *  Get the class instance. This function is thread safe.
     *
     *  \return The class instance.
     */

    static MRH_EventStorage& Singleton() noexcept;

    //*************************************************************************************
    // Clear
    //*************************************************************************************
    
    /**
     *  Clear all currently stored events. This function is thread safe.
     */
    
    void Clear() noexcept;
    
    //*************************************************************************************
    // Add
    //*************************************************************************************
    
    /**
     *  Add a event to storage. This function is thread safe.
     *
     *  \param c_Event The event to add.
     */
    
    void Add(MRH_EVBase const& c_Event);
    
    /**
     *  Add a event to storage. This function is thread safe.
     *
     *  \param p_Event The event to add.
     */
    
    void Add(MRH_Event* p_Event);
    
    //*************************************************************************************
    // Remove
    //*************************************************************************************

    /**
     *  Remove the first event in the container. The event will not be deleted.
     *  This function is thread safe.
     */
    
    void RemoveFront() noexcept;
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Get the amount of stored events. This function is thread safe.
     *
     *  \return The amount of stored events.
     */
    
    size_t GetCount() noexcept;
    
    /**
     *  Get the first (oldest) event in storage. This function is thread safe.
     *
     *  \return The oldest stored event.
     */
    
    MRH_Event* GetEvent() noexcept;
    
    /**
     *  Get the first (oldest) event in storage with a removal option. This function is thread safe.
     *
     *  \param b_RemoveFront If the oldest stored event (the front of the list) should be removed or not.
     *
     *  \return The oldest stored event.
     */
    
    MRH_Event* GetEvent(bool b_RemoveFront) noexcept;
    
private:

    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************
    
    /**
     *  Default constructor.
     */
    
    MRH_EventStorage() noexcept;
    
    /**
     *  Default destructor.
     */
    
    ~MRH_EventStorage() noexcept;
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    std::mutex c_Mutex;
    std::vector<MRH_Event*> v_Event;
    
protected:
    
};

#endif /* MRH_EventStorage_h */
