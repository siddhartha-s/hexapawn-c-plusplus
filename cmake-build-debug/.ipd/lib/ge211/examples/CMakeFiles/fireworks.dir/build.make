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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/sid/my git/ipd/hw/07"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/sid/my git/ipd/hw/07/cmake-build-debug"

# Include any dependencies generated for this target.
include .ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/depend.make

# Include the progress variables for this target.
include .ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/progress.make

# Include the compile flags for this target's objects.
include .ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/flags.make

.ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/fireworks.cpp.o: .ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/flags.make
.ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/fireworks.cpp.o: ../.ipd/lib/ge211/examples/fireworks.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/sid/my git/ipd/hw/07/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object .ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/fireworks.cpp.o"
	cd "/Users/sid/my git/ipd/hw/07/cmake-build-debug/.ipd/lib/ge211/examples" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fireworks.dir/fireworks.cpp.o -c "/Users/sid/my git/ipd/hw/07/.ipd/lib/ge211/examples/fireworks.cpp"

.ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/fireworks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fireworks.dir/fireworks.cpp.i"
	cd "/Users/sid/my git/ipd/hw/07/cmake-build-debug/.ipd/lib/ge211/examples" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/sid/my git/ipd/hw/07/.ipd/lib/ge211/examples/fireworks.cpp" > CMakeFiles/fireworks.dir/fireworks.cpp.i

.ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/fireworks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fireworks.dir/fireworks.cpp.s"
	cd "/Users/sid/my git/ipd/hw/07/cmake-build-debug/.ipd/lib/ge211/examples" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/sid/my git/ipd/hw/07/.ipd/lib/ge211/examples/fireworks.cpp" -o CMakeFiles/fireworks.dir/fireworks.cpp.s

# Object files for target fireworks
fireworks_OBJECTS = \
"CMakeFiles/fireworks.dir/fireworks.cpp.o"

# External object files for target fireworks
fireworks_EXTERNAL_OBJECTS =

.ipd/lib/ge211/examples/fireworks: .ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/fireworks.cpp.o
.ipd/lib/ge211/examples/fireworks: .ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/build.make
.ipd/lib/ge211/examples/fireworks: .ipd/lib/ge211/libge211.a
.ipd/lib/ge211/examples/fireworks: .ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/sid/my git/ipd/hw/07/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fireworks"
	cd "/Users/sid/my git/ipd/hw/07/cmake-build-debug/.ipd/lib/ge211/examples" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fireworks.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
.ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/build: .ipd/lib/ge211/examples/fireworks

.PHONY : .ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/build

.ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/clean:
	cd "/Users/sid/my git/ipd/hw/07/cmake-build-debug/.ipd/lib/ge211/examples" && $(CMAKE_COMMAND) -P CMakeFiles/fireworks.dir/cmake_clean.cmake
.PHONY : .ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/clean

.ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/depend:
	cd "/Users/sid/my git/ipd/hw/07/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/sid/my git/ipd/hw/07" "/Users/sid/my git/ipd/hw/07/.ipd/lib/ge211/examples" "/Users/sid/my git/ipd/hw/07/cmake-build-debug" "/Users/sid/my git/ipd/hw/07/cmake-build-debug/.ipd/lib/ge211/examples" "/Users/sid/my git/ipd/hw/07/cmake-build-debug/.ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : .ipd/lib/ge211/examples/CMakeFiles/fireworks.dir/depend

