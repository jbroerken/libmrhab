#########################################################################
#
#  CMAKE
#
#########################################################################

###
#  Minimum Version
#  ---------------
#  The CMake version required.
###
cmake_minimum_required(VERSION 3.1)

###
#  CMake Configuration
#  -------------------
#  Configuration settings for CMake.
#
#  NOTE:
#  These settings have to be applied before the project() setting!
###
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 14)

###
#  Project Info
#  ------------
#  General simple information about our project.
###
project(libmrhab VERSION 1.0.0
                 DESCRIPTION "Multithreaded module based library for MRH platform applications"
                 LANGUAGES CXX)
set(LIB_SO_VERSION 1)

#########################################################################
#
#  PATHS
#
#########################################################################

###
#  Install Paths
#  -------------
#  GNU system paths for installation.
###
include(GNUInstallDirs)

###
#  Build Paths
#  -----------
#  The paths for the cmake build.
###
set(BUILD_DIR_PATH "${CMAKE_SOURCE_DIR}/build/")
file(MAKE_DIRECTORY ${BUILD_DIR_PATH})

###
#  Source Paths
#  ------------
#  The paths to the source files to use.
###
set(SRC_DIR_PATH "${CMAKE_SOURCE_DIR}/src/")
set(INCLUDE_DIR_PATH "${CMAKE_SOURCE_DIR}/include/")

set(SRC_LIST_COMMON_MODULE "${SRC_DIR_PATH}/libmrhab/Module/Common/MRH_CheckServiceModule.cpp"
                           "${SRC_DIR_PATH}/libmrhab/Module/Common/MRH_SpeechInputModule.cpp"
                           "${SRC_DIR_PATH}/libmrhab/Module/Common/MRH_SpeechOutputModule.cpp"
                           "${INCLUDE_DIR_PATH}/libmrhab/libmrhab/Module/Common/MRH_CheckServiceModule.h"
                           "${INCLUDE_DIR_PATH}/libmrhab/libmrhab/Module/Common/MRH_SpeechInputModule.h"
                           "${INCLUDE_DIR_PATH}/libmrhab/libmrhab/Module/Common/MRH_SpeechOutputModule.h")
						  
set(SRC_LIST_MODULE_TOOLS "${SRC_DIR_PATH}/libmrhab/Module/Tools/MRH_ModuleLogger.cpp"
                          "${SRC_DIR_PATH}/libmrhab/Module/Tools/MRH_ModuleTimer.cpp"
                          "${INCLUDE_DIR_PATH}/libmrhab/libmrhab/Module/Tools/MRH_ModuleLogger.h"
                          "${INCLUDE_DIR_PATH}/libmrhab/libmrhab/Module/Tools/MRH_ModuleTimer.h")
                    
set(SRC_LIST_MODULE "${SRC_DIR_PATH}/libmrhab/Module/MRH_ModuleStack.cpp"
                    "${SRC_DIR_PATH}/libmrhab/Module/MRH_ModuleStack.h"
                    "${SRC_DIR_PATH}/libmrhab/Module/MRH_Module.cpp"
                    "${INCLUDE_DIR_PATH}/libmrhab/libmrhab/Module/MRH_Module.h"
                    "${INCLUDE_DIR_PATH}/libmrhab/libmrhab/Module/MRH_ModuleException.h")
                    
set(SRC_LIST_THREAD_POOL "${SRC_DIR_PATH}/libmrhab/ThreadPool/MRH_ThreadPool.cpp"
                         "${SRC_DIR_PATH}/libmrhab/ThreadPool/MRH_ThreadPool.h")
                    
set(SRC_LIST_BASE "${SRC_DIR_PATH}/libmrhab/MRH_EventStorage.cpp"
                  "${SRC_DIR_PATH}/libmrhab/MRH_ABRevision.cpp"
                  "${SRC_DIR_PATH}/libmrhab.cpp"
                  "${INCLUDE_DIR_PATH}/libmrhab/libmrhab/MRH_EventStorage.h"
                  "${INCLUDE_DIR_PATH}/libmrhab/libmrhab/MRH_ABException.h"
                  "${INCLUDE_DIR_PATH}/libmrhab/libmrhab/MRH_ABRevision.h"
                  "${INCLUDE_DIR_PATH}/libmrhab/libmrhab.h")

###
#  Public API Path
#  ---------------
#  The path to the public api include folder.
###
set(PUBLIC_API_DIR_PATH "${INCLUDE_DIR_PATH}/libmrhab")
					 
#########################################################################
#
#  TARGET
#
#########################################################################

###
#  Target
#  ------
#  The target(s) to build.
###
add_library(libmrhab_Shared SHARED ${SRC_LIST_COMMON_MODULE}
								   ${SRC_LIST_MODULE_TOOLS}
                                   ${SRC_LIST_MODULE}
                                   ${SRC_LIST_THREAD_POOL}
                                   ${SRC_LIST_BASE})
set_target_properties(libmrhab_Shared
                      PROPERTIES
                      PREFIX "lib"
                      OUTPUT_NAME "mrhab"
                      SUFFIX ".so"
                      VERSION ${PROJECT_VERSION}
                      SOVERSION ${LIB_SO_VERSION})

###
#  Required Libraries
#  ------------------
#  Libraries and / or headers required by this library.
###
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

find_package(Threads REQUIRED)
find_library(libmrhevdata NAMES mrhevdata REQUIRED)

target_link_libraries(libmrhab_Shared PUBLIC Threads::Threads)
target_link_libraries(libmrhab_Shared PUBLIC mrhevdata)

###
#  Source Definitions
#  ------------------
#  Preprocessor source definitions.
###
target_compile_definitions(libmrhab_Shared PRIVATE MRH_EVENT_STORAGE_RESERVE_STEP=100)
target_compile_definitions(libmrhab_Shared PRIVATE LOGGER_PRINT_CLI=1)

###
#  Install
#  -------
#  Library installation.
###
install(TARGETS libmrhab_Shared
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY "${PUBLIC_API_DIR_PATH}/"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING
        PATTERN "*.h")