# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/jefferson/games/tetris

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jefferson/games/tetris/buid

# Include any dependencies generated for this target.
include CMakeFiles/tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests.dir/flags.make

CMakeFiles/tests.dir/test/block.spec.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/test/block.spec.cpp.o: ../test/block.spec.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jefferson/games/tetris/buid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests.dir/test/block.spec.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/test/block.spec.cpp.o -c /home/jefferson/games/tetris/test/block.spec.cpp

CMakeFiles/tests.dir/test/block.spec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/test/block.spec.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jefferson/games/tetris/test/block.spec.cpp > CMakeFiles/tests.dir/test/block.spec.cpp.i

CMakeFiles/tests.dir/test/block.spec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/test/block.spec.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jefferson/games/tetris/test/block.spec.cpp -o CMakeFiles/tests.dir/test/block.spec.cpp.s

CMakeFiles/tests.dir/test/block.spec.cpp.o.requires:

.PHONY : CMakeFiles/tests.dir/test/block.spec.cpp.o.requires

CMakeFiles/tests.dir/test/block.spec.cpp.o.provides: CMakeFiles/tests.dir/test/block.spec.cpp.o.requires
	$(MAKE) -f CMakeFiles/tests.dir/build.make CMakeFiles/tests.dir/test/block.spec.cpp.o.provides.build
.PHONY : CMakeFiles/tests.dir/test/block.spec.cpp.o.provides

CMakeFiles/tests.dir/test/block.spec.cpp.o.provides.build: CMakeFiles/tests.dir/test/block.spec.cpp.o


CMakeFiles/tests.dir/test/tests-main.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/test/tests-main.cpp.o: ../test/tests-main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jefferson/games/tetris/buid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tests.dir/test/tests-main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/test/tests-main.cpp.o -c /home/jefferson/games/tetris/test/tests-main.cpp

CMakeFiles/tests.dir/test/tests-main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/test/tests-main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jefferson/games/tetris/test/tests-main.cpp > CMakeFiles/tests.dir/test/tests-main.cpp.i

CMakeFiles/tests.dir/test/tests-main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/test/tests-main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jefferson/games/tetris/test/tests-main.cpp -o CMakeFiles/tests.dir/test/tests-main.cpp.s

CMakeFiles/tests.dir/test/tests-main.cpp.o.requires:

.PHONY : CMakeFiles/tests.dir/test/tests-main.cpp.o.requires

CMakeFiles/tests.dir/test/tests-main.cpp.o.provides: CMakeFiles/tests.dir/test/tests-main.cpp.o.requires
	$(MAKE) -f CMakeFiles/tests.dir/build.make CMakeFiles/tests.dir/test/tests-main.cpp.o.provides.build
.PHONY : CMakeFiles/tests.dir/test/tests-main.cpp.o.provides

CMakeFiles/tests.dir/test/tests-main.cpp.o.provides.build: CMakeFiles/tests.dir/test/tests-main.cpp.o


CMakeFiles/tests.dir/src/block.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/src/block.cpp.o: ../src/block.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jefferson/games/tetris/buid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tests.dir/src/block.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/src/block.cpp.o -c /home/jefferson/games/tetris/src/block.cpp

CMakeFiles/tests.dir/src/block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/src/block.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jefferson/games/tetris/src/block.cpp > CMakeFiles/tests.dir/src/block.cpp.i

CMakeFiles/tests.dir/src/block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/src/block.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jefferson/games/tetris/src/block.cpp -o CMakeFiles/tests.dir/src/block.cpp.s

CMakeFiles/tests.dir/src/block.cpp.o.requires:

.PHONY : CMakeFiles/tests.dir/src/block.cpp.o.requires

CMakeFiles/tests.dir/src/block.cpp.o.provides: CMakeFiles/tests.dir/src/block.cpp.o.requires
	$(MAKE) -f CMakeFiles/tests.dir/build.make CMakeFiles/tests.dir/src/block.cpp.o.provides.build
.PHONY : CMakeFiles/tests.dir/src/block.cpp.o.provides

CMakeFiles/tests.dir/src/block.cpp.o.provides.build: CMakeFiles/tests.dir/src/block.cpp.o


# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/test/block.spec.cpp.o" \
"CMakeFiles/tests.dir/test/tests-main.cpp.o" \
"CMakeFiles/tests.dir/src/block.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests: CMakeFiles/tests.dir/test/block.spec.cpp.o
tests: CMakeFiles/tests.dir/test/tests-main.cpp.o
tests: CMakeFiles/tests.dir/src/block.cpp.o
tests: CMakeFiles/tests.dir/build.make
tests: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
tests: /usr/lib/x86_64-linux-gnu/libsfml-window.so
tests: /usr/lib/x86_64-linux-gnu/libsfml-system.so
tests: CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jefferson/games/tetris/buid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests.dir/build: tests

.PHONY : CMakeFiles/tests.dir/build

CMakeFiles/tests.dir/requires: CMakeFiles/tests.dir/test/block.spec.cpp.o.requires
CMakeFiles/tests.dir/requires: CMakeFiles/tests.dir/test/tests-main.cpp.o.requires
CMakeFiles/tests.dir/requires: CMakeFiles/tests.dir/src/block.cpp.o.requires

.PHONY : CMakeFiles/tests.dir/requires

CMakeFiles/tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tests.dir/clean

CMakeFiles/tests.dir/depend:
	cd /home/jefferson/games/tetris/buid && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jefferson/games/tetris /home/jefferson/games/tetris /home/jefferson/games/tetris/buid /home/jefferson/games/tetris/buid /home/jefferson/games/tetris/buid/CMakeFiles/tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tests.dir/depend
