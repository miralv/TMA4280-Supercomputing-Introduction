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
include CMakeFiles/mach0.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mach0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mach0.dir/flags.make

CMakeFiles/mach0.dir/mach0/main.cpp.o: CMakeFiles/mach0.dir/flags.make
CMakeFiles/mach0.dir/mach0/main.cpp.o: ../mach0/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/miralv/Documents/TMA4280-Supercomputing-Introduction/TestRun/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mach0.dir/mach0/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mach0.dir/mach0/main.cpp.o -c /home/miralv/Documents/TMA4280-Supercomputing-Introduction/mach0/main.cpp

CMakeFiles/mach0.dir/mach0/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mach0.dir/mach0/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/miralv/Documents/TMA4280-Supercomputing-Introduction/mach0/main.cpp > CMakeFiles/mach0.dir/mach0/main.cpp.i

CMakeFiles/mach0.dir/mach0/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mach0.dir/mach0/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/miralv/Documents/TMA4280-Supercomputing-Introduction/mach0/main.cpp -o CMakeFiles/mach0.dir/mach0/main.cpp.s

# Object files for target mach0
mach0_OBJECTS = \
"CMakeFiles/mach0.dir/mach0/main.cpp.o"

# External object files for target mach0
mach0_EXTERNAL_OBJECTS =

mach0: CMakeFiles/mach0.dir/mach0/main.cpp.o
mach0: CMakeFiles/mach0.dir/build.make
mach0: /usr/lib/x86_64-linux-gnu/openmpi/lib/libmpi_cxx.so
mach0: /usr/lib/x86_64-linux-gnu/openmpi/lib/libmpi.so
mach0: CMakeFiles/mach0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/miralv/Documents/TMA4280-Supercomputing-Introduction/TestRun/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mach0"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mach0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mach0.dir/build: mach0

.PHONY : CMakeFiles/mach0.dir/build

CMakeFiles/mach0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mach0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mach0.dir/clean

CMakeFiles/mach0.dir/depend:
	cd /home/miralv/Documents/TMA4280-Supercomputing-Introduction/TestRun && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/miralv/Documents/TMA4280-Supercomputing-Introduction /home/miralv/Documents/TMA4280-Supercomputing-Introduction /home/miralv/Documents/TMA4280-Supercomputing-Introduction/TestRun /home/miralv/Documents/TMA4280-Supercomputing-Introduction/TestRun /home/miralv/Documents/TMA4280-Supercomputing-Introduction/TestRun/CMakeFiles/mach0.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mach0.dir/depend

