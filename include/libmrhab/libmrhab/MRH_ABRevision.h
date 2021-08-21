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

#ifndef MRH_ABRevision_h
#define MRH_ABRevision_h

// C / C++

// External

// Project


namespace MRH_AppBaseRevision
{

    //*************************************************************************************
    // Version
    //*************************************************************************************

    /**
     *  Get the library major version number.
     *
     *  \return The library major version number.
     */

    int MRH_GetLibraryVersionMajor() noexcept;

    /**
     *  Get the library minor version number.
     *
     *  \return The library minor version number.
     */

    int MRH_GetLibraryVersionMinor() noexcept;

    /**
     *  Get the library patch version number.
     *
     *  \return The library patch version number.
     */

    int MRH_GetLibraryVersionPatch() noexcept;
}

//*************************************************************************************
// Revision
//*************************************************************************************

#define MRH_APP_BASE_LIB_VERSION_MAJOR 1
#define MRH_APP_BASE_LIB_VERSION_MINOR 0
#define MRH_APP_BASE_LIB_VERSION_PATCH 0


#endif /* MRH_ABRevision_h */
