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

#ifndef MRH_ModuleStack_h
#define MRH_ModuleStack_h

// C / C++
#include <list>

// External

// Project
#include "../../../include/libmrhab/libmrhab/Module/MRH_Module.h"
#include "../../../include/libmrhab/libmrhab/MRH_ABRevision.h"

// Pre-defined
#define MRH_MODULESTACK_RESULT bool
#define MRH_MODULESTACK_CLOSE_APP false
#define MRH_MODULESTACK_CONTINUE true


class MRH_ModuleStack
{
public:

    //*************************************************************************************
    // Destructor
    //*************************************************************************************

    /**
     *  Default constructor.
     *
     *  \param p_TopModule The initial top level module.
     */
    
    MRH_ModuleStack(std::unique_ptr<MRH_Module>& p_TopModule);
    
    /**
     *  Copy constructor. Disabled for this class.
     *
     *  \param c_ModuleStack ModuleStack class source.
     */

    MRH_ModuleStack(MRH_ModuleStack const& c_ModuleStack) = delete;
    
    /**
     *  Default destructor.
     */

    ~MRH_ModuleStack() noexcept;
    
    //*************************************************************************************
    // Update
    //*************************************************************************************
    
    /**
     *  Update the current module.
     *
     *  \return The module stack update result.
     */
    
    MRH_MODULESTACK_RESULT UpdateCurrent();
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Get the current module.
     *
     *  \return The module currently in use.
     */
    
    std::shared_ptr<MRH_Module> GetCurrent() noexcept;
    
private:
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    std::list<std::shared_ptr<MRH_Module>> l_Module;
    
protected:

};

#endif /* MRH_ModuleStack_h */
