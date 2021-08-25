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
project(libmrhab VERSION 1.0
                 DESCRIPTION "Multithreaded module based library for MRH platform applications"
                 LANGUAGES CXX)

#########################################################################
#
#  PATHS
#
#########################################################################

###
#  Binary Paths
#  ------------
#  The paths for our created binary file(s).
###
set(BIN_DIR_PATH "${CMAKE_SOURCE_DIR}/lib/")
file(MAKE_DIRECTORY ${BIN_DIR_PATH})

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
#  Library Paths
#  -------------
#  The paths to the external libraries to use. 
#  Both the binary and include paths should be set here.
#  Add OS specific libraries in their own lists.
###
set(LIB_DIR_PATH "${CMAKE_SOURCE_DIR}/lib/")
# Include dir path is defined with the sources!

set(LIB_BIN_LIST "${LIB_DIR_PATH}/libmrhcevs.a")
set(LIB_INCLUDE_LIST "${INCLUDE_DIR_PATH}/mrhshared"
                     "${INCLUDE_DIR_PATH}/libmrhcevs")
					 
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
add_library(libmrhab_Shared SHARED ${SRC_LIST_MODULE_TOOLS}
                                   ${SRC_LIST_MODULE}
                                   ${SRC_LIST_THREAD_POOL}
                                   ${SRC_LIST_BASE})
set_target_properties(libmrhab_Shared
                      PROPERTIES
                      PREFIX ""
                      OUTPUT_NAME "libmrhab"
                      SUFFIX ".so"
                      ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR_PATH}
                      LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR_PATH}
                      RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR_PATH})
					  
add_library(libmrhab_Static STATIC ${SRC_LIST_MODULE_TOOLS}
                                   ${SRC_LIST_MODULE}
                                   ${SRC_LIST_THREAD_POOL}
                                   ${SRC_LIST_BASE})
set_target_properties(libmrhab_Static
                      PROPERTIES
                      PREFIX ""
                      OUTPUT_NAME "libmrhab"
                      SUFFIX ".a"
                      ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR_PATH}
                      LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR_PATH}
                      RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR_PATH})

###
#  Required Libraries
#  ------------------
#  Libraries and / or headers required by this library.
###
target_link_libraries(libmrhab_Shared PUBLIC ${LIB_BIN_LIST})
target_link_libraries(libmrhab_Static PUBLIC ${LIB_BIN_LIST})
include_directories(${LIB_INCLUDE_LIST})

###
#  Source Definitions
#  ------------------
#  Preprocessor source definitions.
###
target_compile_definitions(libmrhab_Shared PRIVATE MRH_EVENT_STORAGE_RESERVE_STEP=100)
target_compile_definitions(libmrhab_Shared PRIVATE LOGGER_PRINT_CLI=0)

target_compile_definitions(libmrhab_Static PRIVATE MRH_EVENT_STORAGE_RESERVE_STEP=100)
target_compile_definitions(libmrhab_Static PRIVATE LOGGER_PRINT_CLI=0)