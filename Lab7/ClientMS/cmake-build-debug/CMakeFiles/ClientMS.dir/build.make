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
CMAKE_SOURCE_DIR = D:\GitHub\Shimano\Lab7\ClientMS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\GitHub\Shimano\Lab7\ClientMS\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ClientMS.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ClientMS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ClientMS.dir/flags.make

CMakeFiles/ClientMS.dir/main.cpp.obj: CMakeFiles/ClientMS.dir/flags.make
CMakeFiles/ClientMS.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitHub\Shimano\Lab7\ClientMS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ClientMS.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ClientMS.dir\main.cpp.obj -c D:\GitHub\Shimano\Lab7\ClientMS\main.cpp

CMakeFiles/ClientMS.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClientMS.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\GitHub\Shimano\Lab7\ClientMS\main.cpp > CMakeFiles\ClientMS.dir\main.cpp.i

CMakeFiles/ClientMS.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClientMS.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\GitHub\Shimano\Lab7\ClientMS\main.cpp -o CMakeFiles\ClientMS.dir\main.cpp.s

CMakeFiles/ClientMS.dir/error.cpp.obj: CMakeFiles/ClientMS.dir/flags.make
CMakeFiles/ClientMS.dir/error.cpp.obj: ../error.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitHub\Shimano\Lab7\ClientMS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ClientMS.dir/error.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ClientMS.dir\error.cpp.obj -c D:\GitHub\Shimano\Lab7\ClientMS\error.cpp

CMakeFiles/ClientMS.dir/error.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClientMS.dir/error.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\GitHub\Shimano\Lab7\ClientMS\error.cpp > CMakeFiles\ClientMS.dir\error.cpp.i

CMakeFiles/ClientMS.dir/error.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClientMS.dir/error.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\GitHub\Shimano\Lab7\ClientMS\error.cpp -o CMakeFiles\ClientMS.dir\error.cpp.s

# Object files for target ClientMS
ClientMS_OBJECTS = \
"CMakeFiles/ClientMS.dir/main.cpp.obj" \
"CMakeFiles/ClientMS.dir/error.cpp.obj"

# External object files for target ClientMS
ClientMS_EXTERNAL_OBJECTS =

ClientMS.exe: CMakeFiles/ClientMS.dir/main.cpp.obj
ClientMS.exe: CMakeFiles/ClientMS.dir/error.cpp.obj
ClientMS.exe: CMakeFiles/ClientMS.dir/build.make
ClientMS.exe: CMakeFiles/ClientMS.dir/linklibs.rsp
ClientMS.exe: CMakeFiles/ClientMS.dir/objects1.rsp
ClientMS.exe: CMakeFiles/ClientMS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\GitHub\Shimano\Lab7\ClientMS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ClientMS.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ClientMS.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ClientMS.dir/build: ClientMS.exe
.PHONY : CMakeFiles/ClientMS.dir/build

CMakeFiles/ClientMS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ClientMS.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ClientMS.dir/clean

CMakeFiles/ClientMS.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\GitHub\Shimano\Lab7\ClientMS D:\GitHub\Shimano\Lab7\ClientMS D:\GitHub\Shimano\Lab7\ClientMS\cmake-build-debug D:\GitHub\Shimano\Lab7\ClientMS\cmake-build-debug D:\GitHub\Shimano\Lab7\ClientMS\cmake-build-debug\CMakeFiles\ClientMS.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ClientMS.dir/depend

