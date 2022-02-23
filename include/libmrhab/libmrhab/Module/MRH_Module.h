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

#ifndef MRH_Module_h
#define MRH_Module_h

// C / C++
#include <memory>

// External
#include <libmrhevdata.h>

// Project
#include "./Tools/MRH_ModuleLogger.h"
#include "./Tools/MRH_ModuleTimer.h"
#include "../MRH_EventStorage.h"
#include "./MRH_ModuleException.h"


class MRH_Module
{
public:
    
    //*************************************************************************************
    // Types
    //*************************************************************************************
    
    enum Result
    {
        IN_PROGRESS = 0, // Keep updating
        
        FINISHED_APPEND = 1, // Finished updating, append a new module level
        FINISHED_REPLACE = 2, // Finished updating, replace current module
        FINISHED_POP = 3, // Finished updating, go back one level
        
        RESULT_MAX = FINISHED_POP,
        
        RESULT_COUNT = RESULT_MAX + 1
    };
    
    //*************************************************************************************
    // Destructor
    //*************************************************************************************
    
    /**
     *  Default destructor.
     */
    
    virtual ~MRH_Module() noexcept;
    
    //*************************************************************************************
    // Update
    //*************************************************************************************
    
    /**
     *  Hand a recieved event to the module.
     *
     *  \param p_Event The recieved event.
     */
    
    virtual void HandleEvent(const MRH_Event* p_Event) noexcept;
    
    /**
     *  Perform a module update.
     *
     *  \return The module update result.
     */
    
    virtual Result Update();
    
    /**
     *  Get the module to switch to.
     *
     *  \return The module switch information.
     */
    
    virtual std::shared_ptr<MRH_Module> NextModule();
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Get the module name.
     *
     *  \return The module name.
     */
    
    std::string GetName() noexcept;
    
    /**
     *  Check if the module can handle a event.
     *
     *  \param u32_Type The type of the event to handle.
     *
     *  \return true if the event can be used, false if not.
     */
    
    virtual bool CanHandleEvent(MRH_Uint32 u32_Type) noexcept;
    
private:
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    std::string s_Name;
    
protected:

    //*************************************************************************************
    // Constructor
    //*************************************************************************************
    
    /**
     *  Default constructor.
     *
     *  \param s_Name The module name.
     */
    
    MRH_Module(std::string const& s_Name);
};

#endif /* MRH_Module_h */
