# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = "/Users/overman/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/overman/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/overman/CLionProjects/blizzard

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/overman/CLionProjects/blizzard/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Question1Test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Question1Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Question1Test.dir/flags.make

CMakeFiles/Question1Test.dir/Question1.cpp.o: CMakeFiles/Question1Test.dir/flags.make
CMakeFiles/Question1Test.dir/Question1.cpp.o: ../Question1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/overman/CLionProjects/blizzard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Question1Test.dir/Question1.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Question1Test.dir/Question1.cpp.o -c /Users/overman/CLionProjects/blizzard/Question1.cpp

CMakeFiles/Question1Test.dir/Question1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Question1Test.dir/Question1.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/overman/CLionProjects/blizzard/Question1.cpp > CMakeFiles/Question1Test.dir/Question1.cpp.i

CMakeFiles/Question1Test.dir/Question1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Question1Test.dir/Question1.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/overman/CLionProjects/blizzard/Question1.cpp -o CMakeFiles/Question1Test.dir/Question1.cpp.s

# Object files for target Question1Test
Question1Test_OBJECTS = \
"CMakeFiles/Question1Test.dir/Question1.cpp.o"

# External object files for target Question1Test
Question1Test_EXTERNAL_OBJECTS =

Question1Test: CMakeFiles/Question1Test.dir/Question1.cpp.o
Question1Test: CMakeFiles/Question1Test.dir/build.make
Question1Test: CMakeFiles/Question1Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/overman/CLionProjects/blizzard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Question1Test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Question1Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Question1Test.dir/build: Question1Test

.PHONY : CMakeFiles/Question1Test.dir/build

CMakeFiles/Question1Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Question1Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Question1Test.dir/clean

CMakeFiles/Question1Test.dir/depend:
	cd /Users/overman/CLionProjects/blizzard/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/overman/CLionProjects/blizzard /Users/overman/CLionProjects/blizzard /Users/overman/CLionProjects/blizzard/cmake-build-debug /Users/overman/CLionProjects/blizzard/cmake-build-debug /Users/overman/CLionProjects/blizzard/cmake-build-debug/CMakeFiles/Question1Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Question1Test.dir/depend
