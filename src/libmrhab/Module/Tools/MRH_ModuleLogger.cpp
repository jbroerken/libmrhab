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
#include <iostream>

// External

// Project
#include "../../../../include/libmrhab/libmrhab/Module/Tools/MRH_ModuleLogger.h"

// Pre-defined
#ifndef LOGGER_PRINT_CLI
    #define LOGGER_PRINT_CLI 0
#endif
#define LOGGER_FILE "latest.log"


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_ModuleLogger::MRH_ModuleLogger() noexcept
{
    f_File.open(LOGGER_FILE, std::ios::out | std::ios::trunc);
    
    if (f_File.is_open() == false)
    {
        Log("Logger", "Failed to open log file: " LOGGER_FILE,
            "Logger.cpp", __LINE__);
    }
}

MRH_ModuleLogger::~MRH_ModuleLogger() noexcept
{
    if (f_File.is_open() == true)
    {
        f_File.close();
    }
}

//*************************************************************************************
// Singleton
//*************************************************************************************

MRH_ModuleLogger& MRH_ModuleLogger::Singleton() noexcept
{
    static MRH_ModuleLogger c_Logger;
    return c_Logger;
}

//*************************************************************************************
// Log
//*************************************************************************************

void MRH_ModuleLogger::Log(std::string const& s_Module, std::string const& s_Message, std::string const& s_File, size_t us_Line) noexcept
{
    c_Mutex.lock();
    
    if (f_File.is_open() == true)
    {
        f_File << "[" << s_Module << "][" << s_File << "][" << std::to_string(us_Line) << "]: " << s_Message << std::endl;
    }
    
    if (LOGGER_PRINT_CLI > 0)
    {
        std::cout << "[" << s_Module << "][" << s_File << "][" << std::to_string(us_Line) << "]: " << s_Message << std::endl;
    }
    
    c_Mutex.unlock();
}

void MRH_ModuleLogger::Log(MRH_ModuleException const& c_Exception, std::string const& s_File, size_t us_Line) noexcept
{
    Log(c_Exception.module2(), c_Exception.what2(), s_File, us_Line);
}
