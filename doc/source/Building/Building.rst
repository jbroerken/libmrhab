********
Building
********
The project files are already prepared and include everything except the 
required dependencies. This document lists both dependencies as well as the 
build process to create the library from source.

Supported Platforms
-------------------
The supported platforms for libmrhab are UNIX-likes, primarily 
Debian-based GNU/Linux Distributions like the Rapsberry Pi OS.

Dependencies
------------
This library has the following dependencies:

* mrhshared: https://github.com/jbroerken/mrhshared/
* libmrhevdata: https://github.com/jbroerken/libmrhevdata/

Build Tools
-----------
This release includes a CMake script (CMakeLists.txt) for a simplified build 
process. The minimal required version for CMake is 3.1.
Also needed is the GNU C++ Compiler. Full C++14 support is required.

Changing Pre-defined Settings
-----------------------------
The space reserve step for the event storage is handled by using preprocessor 
macros. These are listed in the CMakeLists.txt file and can easily be changed 
there to fit the requirements of the target use case.

Build Process
-------------
The build process should be relatively straightforward:

1. Aqquire dependencies.
2. Move into the project "build" folder.
3. Compile Makefiles with the included CMakeLists.txt.
4. Run "make" to compile the library.
5. Install the compiled library and its header files.

Shell Commands
--------------
The following shell commands will create makefiles with the 
provided CMakeLists.txt, compile the project with the created 
makefiles and install the library and headers:

.. code-block::

    cd <Project Root Folder>/build
    cmake ..
    make
    sudo make install
