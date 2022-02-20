/**
 *  MRH_SpeechOutputModule.h
 *
 *  This file is part of the MRH project.
 *  See the AUTHORS file for Copyright information.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
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
