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

#ifndef MRH_ModuleException_h
#define MRH_ModuleException_h

// C / C++
#include <string>
#include <exception>

// External

// Project


class MRH_ModuleException : public std::exception
{
public:
    
    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************
    
    /**
     *  std::string constructor.
     *
     *  \param s_Module The module name.
     *  \param s_Message The error message.
     */
    
    MRH_ModuleException(std::string const& s_Module,
                        std::string const& s_Message) : s_Module(s_Module),
                                                        s_Message(s_Message)
    {}
    
    /**
     *  const char* constructor.
     *
     *  \param p_Module The module name.
     *  \param p_Message The error message.
     */
    
    MRH_ModuleException(const char* p_Module,
                        const char* p_Message) : s_Module(p_Module != NULL ? p_Module : ""),
                                                 s_Message(p_Message != NULL ? p_Message : "")
    {}
    
    /**
     *  Default destructor.
     */
    
    ~MRH_ModuleException()
    {}
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Get the exception message as a const char* string.
     *
     *  \return The const char* error message.
     */
    
    const char* what() const throw()
    {
        return s_Message.c_str();
    }
    
    /**
     *  Get the exception message as a std::string string.
     *
     *  \return The std::string error message.
     */
    
    std::string const& what2() const throw()
    {
        return s_Message;
    }
    
    /**
     *  Get the module name as a const char* string.
     *
     *  \return The const char* module name.
     */
    
    const char* module() const throw()
    {
        return s_Module.c_str();
    }
    
    /**
     *  Get the module name as a std::string string.
     *
     *  \return The std::string module name.
     */
    
    std::string const& module2() const throw()
    {
        return s_Module;
    }
    
private:
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    std::string s_Module;
    std::string s_Message;
    
protected:
    
};

#endif /* MRH_ModuleException_h */
