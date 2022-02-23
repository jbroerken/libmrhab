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

#ifndef MRH_SpeechOutputModule_h
#define MRH_SpeechOutputModule_h

// C / C++
#include <atomic>

// External

// Project
#include "../MRH_Module.h"


class MRH_SpeechOutputModule : public MRH_Module
{
public:
    
    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************
    
    /**
     *  String constructor.
     *
     *  \param s_Output The string to perform as speech output.
     *  \param u32_TimeoutMS The time in milliseconds to wait until output is performed.
     *  \param u32_OutputID The output ID to use.
     */
    
    MRH_SpeechOutputModule(std::string s_Output,
                           MRH_Uint32 u32_TimeoutMS,
                           MRH_Uint32 u32_OutputID = (rand() % ((MRH_Uint32) - 1)));
    
    /**
     *  Default destructor.
     */
    
    ~MRH_SpeechOutputModule() noexcept;
    
    //*************************************************************************************
    // Update
    //*************************************************************************************
    
    /**
     *  Hand a recieved event to the module.
     *
     *  \param p_Event The recieved event.
     */
    
    void HandleEvent(const MRH_Event* p_Event) noexcept override;
    
    /**
     *  Perform a module update.
     *
     *  \return The module update result.
     */
    
    MRH_Module::Result Update() override;
    
    /**
     *  Get the module to switch to.
     *
     *  \return The module switch information.
     */
    
    std::shared_ptr<MRH_Module> NextModule() override;
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Check if the module can handle a event.
     *
     *  \param u32_Type The type of the event to handle.
     *
     *  \return true if the event can be used, false if not.
     */
    
    bool CanHandleEvent(MRH_Uint32 u32_Type) noexcept override;
    
private:
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    MRH_ModuleTimer c_Timer;
    
    const MRH_Uint32 u32_SentOutputID;
    std::atomic<MRH_Uint32> u32_RecievedOutputID;
    
protected:
    
};

#endif /* SpeechOutput_h */
