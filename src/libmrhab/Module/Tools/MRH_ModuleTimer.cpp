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
#include "../../../../include/libmrhab/libmrhab/Module/Tools/MRH_ModuleTimer.h"


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_ModuleTimer::MRH_ModuleTimer(MRH_Uint32 u32_TimeMS) noexcept : c_End(TimePoint(Clock::now())),
                                                                   b_Set(false)
{
    if (u32_TimeMS > 0)
    {
        SetTimer(u32_TimeMS);
    }
}

MRH_ModuleTimer::~MRH_ModuleTimer() noexcept
{}

//*************************************************************************************
// Reset
//*************************************************************************************

void MRH_ModuleTimer::ResetTimer() noexcept
{
    b_Set = false;
}

//*************************************************************************************
// Set
//*************************************************************************************

void MRH_ModuleTimer::SetTimer(MRH_Uint32 u32_TimeMS) noexcept
{
    c_End = TimePoint(Clock::now() + Milliseconds(u32_TimeMS));
    b_Set = true;
}

//*************************************************************************************
// Getters
//*************************************************************************************

bool MRH_ModuleTimer::GetTimerFinished() const noexcept
{
    return Clock::now() >= c_End ? true : false;
}

bool MRH_ModuleTimer::GetTimerSet() const noexcept
{
    return b_Set;
}
