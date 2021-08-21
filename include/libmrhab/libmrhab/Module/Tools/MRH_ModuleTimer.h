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

#ifndef MRH_ModuleTimer_h
#define MRH_ModuleTimer_h

// C / C++
#include <chrono>

// External
#include <MRH_Typedefs.h>

// Project


class MRH_ModuleTimer
{
public:
    
    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************
    
    /**
     *  Default constructor.
     *
     *  \param u32_TimeMS The initial wait time in milliseconds.
     */
    
    MRH_ModuleTimer(MRH_Uint32 u32_TimeMS = 0) noexcept;
    
    /**
     *  Default destructor.
     */
    
    ~MRH_ModuleTimer() noexcept;
    
    //*************************************************************************************
    // Reset
    //*************************************************************************************
    
    /**
     *  Reset the timer.
     */
    
    void ResetTimer() noexcept;
    
    //*************************************************************************************
    // Set
    //*************************************************************************************
    
    /**
     *  Set the timer.
     *
     *  \param u32_TimeMS The wait time in milliseconds.
     */
    
    void SetTimer(MRH_Uint32 u32_TimeMS) noexcept;
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Check if the timer has been finished.
     *
     *  \return true if the timer is finished, false if not.
     */
    
    bool GetTimerFinished() const noexcept;
    
    /**
     *  Check if the timer has been set.
     *
     *  \return true if set, false if not.
     */
    
    bool GetTimerSet() const noexcept;
    
private:
    
    //*************************************************************************************
    // Types
    //*************************************************************************************

    typedef std::chrono::high_resolution_clock Clock;
    typedef std::chrono::milliseconds Milliseconds;
    typedef Clock::time_point TimePoint;
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    TimePoint c_End;
    bool b_Set;
    
protected:

};

#endif /* MRH_ModuleTimer_h */
