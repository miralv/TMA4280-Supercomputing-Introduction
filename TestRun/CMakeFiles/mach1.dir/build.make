# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/miralv/Documents/TMA4280-Supercomputing-Introduction

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/miralv/Documents/TMA4280-Supercomputing-Introduction/TestRun

# Include any dependencies generated for this target.
include CMakeFiles/mach1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mach1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mach1.dir/flags.make

CMakeFiles/mach1.dir/mach1/main.cpp.o: CMakeFiles/mach1.dir/flags.make
CMakeFiles/mach1.dir/mach1/main.cpp.o: ../mach1/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/miralv/Documents/TMA4280-Supercomputing-Introduction/TestRun/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mach1.dir/mach1/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mach1.dir/mach1/main.cpp.o -c /home/miralv/Documents/TMA4280-Supercomputing-Introduction/mach1/main.cpp

CMakeFiles/mach1.dir/mach1/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mach1.dir/mach1/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/miralv/Documents/TMA4280-Supercomputing-Introduction/mach1/main.cpp > CMakeFiles/mach1.dir/mach1/main.cpp.i

CMakeFiles/mach1.dir/mach1/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mach1.dir/mach1/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/miralv/Documents/TMA4280-Supercomputing-Introduction/mach1/main.cpp -o CMakeFiles/mach1.dir/mach1/main.cpp.s

# Object files for target mach1
mach1_OBJECTS = \
"CMakeFiles/mach1.dir/mach1/main.cpp.o"

# External object files for target mach1
mach1_EXTERNAL_OBJECTS =

mach1: CMakeFiles/mach1.dir/mach1/main.cpp.o
mach1: CMakeFiles/mach1.dir/build.make
mach1: /usr/lib/x86_64-linux-gnu/openmpi/lib/libmpi_cxx.so
mach1: /usr/lib/x86_64-linux-gnu/openmpi/lib/libmpi.so
mach1: CMakeFiles/mach1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/miralv/Documents/TMA4280-Supercomputing-Introduction/TestRun/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mach1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mach1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mach1.dir/build: mach1

.PHONY : CMakeFiles/mach1.dir/build

CMakeFiles/mach1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mach1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mach1.dir/clean

CMakeFiles/mach1.dir/depend:
	cd /home/miralv/Documents/TMA4280-Supercomputing-Introduction/TestRun && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/miralv/Documents/TMA4280-Supercomputing-Introduction /home/miralv/Documents/TMA4280-Supercomputing-Introduction /home/miralv/Documents/TMA4280-Supercomputing-Introduction/TestRun /home/miralv/Documents/TMA4280-Supercomputing-Introduction/TestRun /home/miralv/Documents/TMA4280-Supercomputing-Introduction/TestRun/CMakeFiles/mach1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mach1.dir/depend

