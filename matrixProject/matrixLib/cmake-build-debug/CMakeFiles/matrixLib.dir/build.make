# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/IhoreQ/Documents/CLion-2021.2.2/clion-2021.2.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/IhoreQ/Documents/CLion-2021.2.2/clion-2021.2.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/IhoreQ/CLionProjects/JiPP2/matrixProject/matrixLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/IhoreQ/CLionProjects/JiPP2/matrixProject/matrixLib/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/matrixLib.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/matrixLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/matrixLib.dir/flags.make

CMakeFiles/matrixLib.dir/library.cpp.o: CMakeFiles/matrixLib.dir/flags.make
CMakeFiles/matrixLib.dir/library.cpp.o: ../library.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/IhoreQ/CLionProjects/JiPP2/matrixProject/matrixLib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/matrixLib.dir/library.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/matrixLib.dir/library.cpp.o -c /home/IhoreQ/CLionProjects/JiPP2/matrixProject/matrixLib/library.cpp

CMakeFiles/matrixLib.dir/library.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/matrixLib.dir/library.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/IhoreQ/CLionProjects/JiPP2/matrixProject/matrixLib/library.cpp > CMakeFiles/matrixLib.dir/library.cpp.i

CMakeFiles/matrixLib.dir/library.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/matrixLib.dir/library.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/IhoreQ/CLionProjects/JiPP2/matrixProject/matrixLib/library.cpp -o CMakeFiles/matrixLib.dir/library.cpp.s

# Object files for target matrixLib
matrixLib_OBJECTS = \
"CMakeFiles/matrixLib.dir/library.cpp.o"

# External object files for target matrixLib
matrixLib_EXTERNAL_OBJECTS =

libmatrixLib.a: CMakeFiles/matrixLib.dir/library.cpp.o
libmatrixLib.a: CMakeFiles/matrixLib.dir/build.make
libmatrixLib.a: CMakeFiles/matrixLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/IhoreQ/CLionProjects/JiPP2/matrixProject/matrixLib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmatrixLib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/matrixLib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/matrixLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/matrixLib.dir/build: libmatrixLib.a
.PHONY : CMakeFiles/matrixLib.dir/build

CMakeFiles/matrixLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/matrixLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/matrixLib.dir/clean

CMakeFiles/matrixLib.dir/depend:
	cd /home/IhoreQ/CLionProjects/JiPP2/matrixProject/matrixLib/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/IhoreQ/CLionProjects/JiPP2/matrixProject/matrixLib /home/IhoreQ/CLionProjects/JiPP2/matrixProject/matrixLib /home/IhoreQ/CLionProjects/JiPP2/matrixProject/matrixLib/cmake-build-debug /home/IhoreQ/CLionProjects/JiPP2/matrixProject/matrixLib/cmake-build-debug /home/IhoreQ/CLionProjects/JiPP2/matrixProject/matrixLib/cmake-build-debug/CMakeFiles/matrixLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/matrixLib.dir/depend
