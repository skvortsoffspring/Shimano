# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\garik\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5284.51\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\garik\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5284.51\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\GitHub\Shimano\Lab3\ClientU

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\GitHub\Shimano\Lab3\ClientU\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ClientU.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ClientU.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ClientU.dir/flags.make

CMakeFiles/ClientU.dir/main.cpp.obj: CMakeFiles/ClientU.dir/flags.make
CMakeFiles/ClientU.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitHub\Shimano\Lab3\ClientU\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ClientU.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ClientU.dir\main.cpp.obj -c D:\GitHub\Shimano\Lab3\ClientU\main.cpp

CMakeFiles/ClientU.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClientU.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\GitHub\Shimano\Lab3\ClientU\main.cpp > CMakeFiles\ClientU.dir\main.cpp.i

CMakeFiles/ClientU.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClientU.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\GitHub\Shimano\Lab3\ClientU\main.cpp -o CMakeFiles\ClientU.dir\main.cpp.s

CMakeFiles/ClientU.dir/Error.cpp.obj: CMakeFiles/ClientU.dir/flags.make
CMakeFiles/ClientU.dir/Error.cpp.obj: ../Error.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitHub\Shimano\Lab3\ClientU\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ClientU.dir/Error.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ClientU.dir\Error.cpp.obj -c D:\GitHub\Shimano\Lab3\ClientU\Error.cpp

CMakeFiles/ClientU.dir/Error.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClientU.dir/Error.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\GitHub\Shimano\Lab3\ClientU\Error.cpp > CMakeFiles\ClientU.dir\Error.cpp.i

CMakeFiles/ClientU.dir/Error.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClientU.dir/Error.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\GitHub\Shimano\Lab3\ClientU\Error.cpp -o CMakeFiles\ClientU.dir\Error.cpp.s

# Object files for target ClientU
ClientU_OBJECTS = \
"CMakeFiles/ClientU.dir/main.cpp.obj" \
"CMakeFiles/ClientU.dir/Error.cpp.obj"

# External object files for target ClientU
ClientU_EXTERNAL_OBJECTS =

ClientU.exe: CMakeFiles/ClientU.dir/main.cpp.obj
ClientU.exe: CMakeFiles/ClientU.dir/Error.cpp.obj
ClientU.exe: CMakeFiles/ClientU.dir/build.make
ClientU.exe: CMakeFiles/ClientU.dir/linklibs.rsp
ClientU.exe: CMakeFiles/ClientU.dir/objects1.rsp
ClientU.exe: CMakeFiles/ClientU.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\GitHub\Shimano\Lab3\ClientU\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ClientU.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ClientU.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ClientU.dir/build: ClientU.exe
.PHONY : CMakeFiles/ClientU.dir/build

CMakeFiles/ClientU.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ClientU.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ClientU.dir/clean

CMakeFiles/ClientU.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\GitHub\Shimano\Lab3\ClientU D:\GitHub\Shimano\Lab3\ClientU D:\GitHub\Shimano\Lab3\ClientU\cmake-build-debug D:\GitHub\Shimano\Lab3\ClientU\cmake-build-debug D:\GitHub\Shimano\Lab3\ClientU\cmake-build-debug\CMakeFiles\ClientU.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ClientU.dir/depend

