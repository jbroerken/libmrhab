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

#ifndef MRH_ABException_h
#define MRH_ABException_h

// C / C++
#include <string>
#include <exception>

// External

// Project


class MRH_ABException : public std::exception
{
public:
    
    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************
    
    /**
     *  std::string constructor.
     *
     *  \param s_Message The error message.
     */
    
    MRH_ABException(std::string s_Message) : s_Message(s_Message)
    {}
    
    /**
     *  const char* constructor.
     *
     *  \param p_Message The error message.
     */
    
    MRH_ABException(const char* p_Message) : s_Message(p_Message)
    {}
    
    /**
     *  Default destructor.
     */
    
    ~MRH_ABException()
    {}
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Get the const char* exception string.
     *
     *  \return A const char* string with the error message.
     */
    
    const char* what() const throw()
    {
        return s_Message.c_str();
    }
    
    /**
     *  Get the std::string exception string.
     *
     *  \return A std::string string with the error message.
     */
    
    std::string what2() const throw()
    {
        return s_Message;
    }
    
private:
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    std::string s_Message;
    
protected:
    
};

#endif /* MRH_ABException_h */
