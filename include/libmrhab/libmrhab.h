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

#ifndef libmrhab_h
#define libmrhab_h

// C / C++
#include <memory>

// External

// Project
#include "./libmrhab/Module/MRH_Module.h"
#include "./libmrhab/MRH_ABException.h"
#include "./libmrhab/MRH_ABRevision.h"

// Pre-defined
#define LIBMRHAB_UPDATE_RESULT bool
#define LIBMRHAB_UPDATE_CLOSE_APP false
#define LIBMRHAB_UPDATE_CONTINUE true


class MRH_ModuleStack;
class MRH_ThreadPool;


class libmrhab
{
public:

    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************

    /**
     *  Default constructor.
     *
     *  \param p_TopModule The initial top level module.
     *  \param us_ThreadCount The amount of update threads to use or 0 for single threaded.
     */

    libmrhab(std::unique_ptr<MRH_Module> p_TopModule,
             size_t us_ThreadCount);
    
    /**
     *  Copy constructor. Disabled for this class.
     *
     *  \param c_libmrhab libmrhab class source.
     */
    
    libmrhab(libmrhab const& c_libmrhab) = delete;
    
    /**
     *  Default destructor.
     */
    
    ~libmrhab() noexcept;
    
    //*************************************************************************************
    // Update
    //*************************************************************************************
    
    /**
     *  Add a job to the application base. This function is thread safe.
     *
     *  \param p_Event The event to add.
     */
    
    void AddJob(const MRH_Event* p_Event);
    
    /**
     *  Update the currently running module.
     *
     *  \return The libmrhab update result.
     */
    
    LIBMRHAB_UPDATE_RESULT Update();
    
private:

    //*************************************************************************************
    // Getters
    //*************************************************************************************

    /**
     *  Check if an event type is valid for a callback. This function is thread safe.
     *
     *  \param u32_Type The event type to check.
     *
     *  \return true if valid, false if not.
     */
    
    bool IsValidEventType(MRH_Uint32 u32_Type) noexcept;
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    MRH_ModuleStack* p_ModuleStack;
    MRH_ThreadPool* p_ThreadPool;
    
protected:
    
};

#endif /* libmrhab_h */
