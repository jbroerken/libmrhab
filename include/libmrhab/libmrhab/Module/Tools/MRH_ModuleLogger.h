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

#ifndef MRH_ModuleLogger_h
#define MRH_ModuleLogger_h

// C / C++
#include <string>
#include <mutex>
#include <fstream>

// External

// Project
#include "../MRH_ModuleException.h"


class MRH_ModuleLogger
{
public:
    
    //*************************************************************************************
    // Singleton
    //*************************************************************************************
    
    /**
     *  Get the singleton class instance.
     *
     *  \return The class instance.
     */
    
    static MRH_ModuleLogger& Singleton() noexcept;
    
    //*************************************************************************************
    // Log
    //*************************************************************************************
    
    /**
     *  Log a message.
     *
     *  \param s_Module The module to log for.
     *  \param s_Message The message to log.
     *  \param s_File The file for this log message.
     *  \param us_Line The line in the file for this log message.
     */
    
    void Log(std::string const& s_Module, std::string const& s_Message, std::string const& s_File, size_t us_Line) noexcept;
    
    /**
     *  Log a exception.
     *
     *  \param c_Exception The exception to log.
     *  \param s_File The file for this logged exception.
     *  \param us_Line The line in the file for this logged exception.
     */
    
    void Log(MRH_ModuleException const& c_Exception, std::string const& s_File, size_t us_Line) noexcept;
    
private:
    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************
    
    /**
     *  Default constructor.
     */
    
    MRH_ModuleLogger() noexcept;
    
    /**
     *  Default destructor.
     */
    
    ~MRH_ModuleLogger() noexcept;
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    std::mutex c_Mutex;
    std::ofstream f_File;
    
protected:

};

#endif /* MRH_ModuleLogger_h */
