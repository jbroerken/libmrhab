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
#include "../../../include/libmrhab/libmrhab/Module/MRH_Module.h"


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_Module::MRH_Module(std::string const& s_Name) : s_Name(s_Name)
{
    if (s_Name.size() == 0)
    {
        throw MRH_ModuleException("<undefined>", "Invalid module name!");
    }
}

MRH_Module::~MRH_Module() noexcept
{}

//*************************************************************************************
// Update
//*************************************************************************************

void MRH_Module::HandleEvent(const MRH_Event* p_Event) noexcept
{
    // Dummy
}

MRH_Module::Result MRH_Module::Update()
{
    // Dummy
    throw MRH_ModuleException("<undefined>",
                              "Base class module update called!");
}

std::shared_ptr<MRH_Module> MRH_Module::NextModule()
{
    // Dummy
    throw MRH_ModuleException("<undefined>",
                              "No module to switch to!");
}

//*************************************************************************************
// Getters
//*************************************************************************************

std::string MRH_Module::GetName() noexcept
{
    return s_Name;
}

bool MRH_Module::CanHandleEvent(MRH_Uint32 u32_Type) noexcept
{
    // Dummy
    return false;
}
