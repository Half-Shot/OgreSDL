# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/will/GitRepos/OgreSDL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/will/GitRepos/OgreSDL

# Include any dependencies generated for this target.
include CMakeFiles/OgreSDL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OgreSDL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OgreSDL.dir/flags.make

CMakeFiles/OgreSDL.dir/src/Program.cpp.o: CMakeFiles/OgreSDL.dir/flags.make
CMakeFiles/OgreSDL.dir/src/Program.cpp.o: src/Program.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/will/GitRepos/OgreSDL/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/OgreSDL.dir/src/Program.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/OgreSDL.dir/src/Program.cpp.o -c /home/will/GitRepos/OgreSDL/src/Program.cpp

CMakeFiles/OgreSDL.dir/src/Program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OgreSDL.dir/src/Program.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/will/GitRepos/OgreSDL/src/Program.cpp > CMakeFiles/OgreSDL.dir/src/Program.cpp.i

CMakeFiles/OgreSDL.dir/src/Program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OgreSDL.dir/src/Program.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/will/GitRepos/OgreSDL/src/Program.cpp -o CMakeFiles/OgreSDL.dir/src/Program.cpp.s

CMakeFiles/OgreSDL.dir/src/Program.cpp.o.requires:
.PHONY : CMakeFiles/OgreSDL.dir/src/Program.cpp.o.requires

CMakeFiles/OgreSDL.dir/src/Program.cpp.o.provides: CMakeFiles/OgreSDL.dir/src/Program.cpp.o.requires
	$(MAKE) -f CMakeFiles/OgreSDL.dir/build.make CMakeFiles/OgreSDL.dir/src/Program.cpp.o.provides.build
.PHONY : CMakeFiles/OgreSDL.dir/src/Program.cpp.o.provides

CMakeFiles/OgreSDL.dir/src/Program.cpp.o.provides.build: CMakeFiles/OgreSDL.dir/src/Program.cpp.o

CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.o: CMakeFiles/OgreSDL.dir/flags.make
CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.o: src/OgreSDL.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/will/GitRepos/OgreSDL/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.o -c /home/will/GitRepos/OgreSDL/src/OgreSDL.cpp

CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/will/GitRepos/OgreSDL/src/OgreSDL.cpp > CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.i

CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/will/GitRepos/OgreSDL/src/OgreSDL.cpp -o CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.s

CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.o.requires:
.PHONY : CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.o.requires

CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.o.provides: CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.o.requires
	$(MAKE) -f CMakeFiles/OgreSDL.dir/build.make CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.o.provides.build
.PHONY : CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.o.provides

CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.o.provides.build: CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.o

CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.o: CMakeFiles/OgreSDL.dir/flags.make
CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.o: src/ExampleGame.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/will/GitRepos/OgreSDL/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.o -c /home/will/GitRepos/OgreSDL/src/ExampleGame.cpp

CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/will/GitRepos/OgreSDL/src/ExampleGame.cpp > CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.i

CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/will/GitRepos/OgreSDL/src/ExampleGame.cpp -o CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.s

CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.o.requires:
.PHONY : CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.o.requires

CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.o.provides: CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.o.requires
	$(MAKE) -f CMakeFiles/OgreSDL.dir/build.make CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.o.provides.build
.PHONY : CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.o.provides

CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.o.provides.build: CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.o

# Object files for target OgreSDL
OgreSDL_OBJECTS = \
"CMakeFiles/OgreSDL.dir/src/Program.cpp.o" \
"CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.o" \
"CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.o"

# External object files for target OgreSDL
OgreSDL_EXTERNAL_OBJECTS =

dist/bin/OgreSDL_d: CMakeFiles/OgreSDL.dir/src/Program.cpp.o
dist/bin/OgreSDL_d: CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.o
dist/bin/OgreSDL_d: CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.o
dist/bin/OgreSDL_d: CMakeFiles/OgreSDL.dir/build.make
dist/bin/OgreSDL_d: /usr/lib64/libOgreMain.so
dist/bin/OgreSDL_d: /usr/lib64/libboost_thread.so
dist/bin/OgreSDL_d: /usr/lib64/libboost_date_time.so
dist/bin/OgreSDL_d: /usr/lib64/libboost_system.so
dist/bin/OgreSDL_d: /usr/lib64/libboost_atomic.so
dist/bin/OgreSDL_d: /usr/lib64/libboost_chrono.so
dist/bin/OgreSDL_d: /usr/lib64/libboost_thread.so
dist/bin/OgreSDL_d: /usr/lib64/libboost_date_time.so
dist/bin/OgreSDL_d: /usr/lib64/libboost_system.so
dist/bin/OgreSDL_d: /usr/lib64/libboost_chrono.so
dist/bin/OgreSDL_d: /usr/lib64/libOIS.so
dist/bin/OgreSDL_d: /usr/lib64/libSDL2_mixer.so
dist/bin/OgreSDL_d: /usr/lib64/libOgreOverlay.so
dist/bin/OgreSDL_d: /usr/lib64/libboost_atomic.so
dist/bin/OgreSDL_d: /usr/lib64/libOIS.so
dist/bin/OgreSDL_d: /usr/lib64/libSDL2_mixer.so
dist/bin/OgreSDL_d: /usr/lib64/libOgreOverlay.so
dist/bin/OgreSDL_d: CMakeFiles/OgreSDL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable dist/bin/OgreSDL_d"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OgreSDL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OgreSDL.dir/build: dist/bin/OgreSDL_d
.PHONY : CMakeFiles/OgreSDL.dir/build

CMakeFiles/OgreSDL.dir/requires: CMakeFiles/OgreSDL.dir/src/Program.cpp.o.requires
CMakeFiles/OgreSDL.dir/requires: CMakeFiles/OgreSDL.dir/src/OgreSDL.cpp.o.requires
CMakeFiles/OgreSDL.dir/requires: CMakeFiles/OgreSDL.dir/src/ExampleGame.cpp.o.requires
.PHONY : CMakeFiles/OgreSDL.dir/requires

CMakeFiles/OgreSDL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OgreSDL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OgreSDL.dir/clean

CMakeFiles/OgreSDL.dir/depend:
	cd /home/will/GitRepos/OgreSDL && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/will/GitRepos/OgreSDL /home/will/GitRepos/OgreSDL /home/will/GitRepos/OgreSDL /home/will/GitRepos/OgreSDL /home/will/GitRepos/OgreSDL/CMakeFiles/OgreSDL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OgreSDL.dir/depend
