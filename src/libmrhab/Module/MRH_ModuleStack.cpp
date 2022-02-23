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
#include "./MRH_ModuleStack.h"


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_ModuleStack::MRH_ModuleStack(std::unique_ptr<MRH_Module>& p_TopModule)
{
    l_Module.emplace_back(std::shared_ptr<MRH_Module>(p_TopModule.release()));
}

MRH_ModuleStack::~MRH_ModuleStack() noexcept
{
    l_Module.clear(); // Let default delete handle everything
}

//*************************************************************************************
// Update
//*************************************************************************************

MRH_MODULESTACK_RESULT MRH_ModuleStack::UpdateCurrent()
{
    try
    {
        std::shared_ptr<MRH_Module>& p_Current = l_Module.back();
        
        switch (p_Current->Update())
        {
            case MRH_Module::IN_PROGRESS:
                break;
                    
            case MRH_Module::FINISHED_APPEND:
                l_Module.emplace_back(p_Current->NextModule());
                break;
            case MRH_Module::FINISHED_REPLACE:
                l_Module.back() = p_Current->NextModule();
                break;
            case MRH_Module::FINISHED_POP:
                l_Module.pop_back();
                break;
                
            default:
                throw MRH_ModuleException(p_Current->GetName(),
                                          "Unknown update result!");
        }
        
        // List valid?
        if (l_Module.size() > 0 && l_Module.back() == NULL)
        {
            l_Module.pop_back();
            throw MRH_ABException("Invalid module at list end! End popped.");
        }
    
        // How to continue?
        return l_Module.size() > 0 ? MRH_MODULESTACK_CONTINUE : MRH_MODULESTACK_CLOSE_APP;
    }
    catch (MRH_ABException& e)
    {
        throw;
    }
    catch (MRH_ModuleException& e)
    {
        throw MRH_ABException("[ " + e.module2() + "]: " + e.what2());
    }
    catch (std::exception& e)
    {
        throw MRH_ABException(e.what());
    }
}

//*************************************************************************************
// Getters
//*************************************************************************************

std::shared_ptr<MRH_Module> MRH_ModuleStack::GetCurrent() noexcept
{
    return l_Module.size() > 0 ? l_Module.back() : NULL;
}
