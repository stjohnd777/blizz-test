# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\jetbrains\apps\CLion\ch-0\203.7148.70\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\jetbrains\apps\CLion\ch-0\203.7148.70\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\dev\github\blizz-test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\dev\github\blizz-test\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\blizzard.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\blizzard.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\blizzard.dir\flags.make

CMakeFiles\blizzard.dir\UniqueDigitsQuestion.cpp.obj: CMakeFiles\blizzard.dir\flags.make
CMakeFiles\blizzard.dir\UniqueDigitsQuestion.cpp.obj: ..\UniqueDigitsQuestion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\dev\github\blizz-test\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/blizzard.dir/UniqueDigitsQuestion.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\blizzard.dir\UniqueDigitsQuestion.cpp.obj /FdCMakeFiles\blizzard.dir\ /FS -c C:\dev\github\blizz-test\UniqueDigitsQuestion.cpp
<<

CMakeFiles\blizzard.dir\UniqueDigitsQuestion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blizzard.dir/UniqueDigitsQuestion.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\blizzard.dir\UniqueDigitsQuestion.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\dev\github\blizz-test\UniqueDigitsQuestion.cpp
<<

CMakeFiles\blizzard.dir\UniqueDigitsQuestion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blizzard.dir/UniqueDigitsQuestion.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\blizzard.dir\UniqueDigitsQuestion.cpp.s /c C:\dev\github\blizz-test\UniqueDigitsQuestion.cpp
<<

CMakeFiles\blizzard.dir\test\TimeMetric.cpp.obj: CMakeFiles\blizzard.dir\flags.make
CMakeFiles\blizzard.dir\test\TimeMetric.cpp.obj: ..\test\TimeMetric.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\dev\github\blizz-test\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/blizzard.dir/test/TimeMetric.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\blizzard.dir\test\TimeMetric.cpp.obj /FdCMakeFiles\blizzard.dir\ /FS -c C:\dev\github\blizz-test\test\TimeMetric.cpp
<<

CMakeFiles\blizzard.dir\test\TimeMetric.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blizzard.dir/test/TimeMetric.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\blizzard.dir\test\TimeMetric.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\dev\github\blizz-test\test\TimeMetric.cpp
<<

CMakeFiles\blizzard.dir\test\TimeMetric.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blizzard.dir/test/TimeMetric.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\blizzard.dir\test\TimeMetric.cpp.s /c C:\dev\github\blizz-test\test\TimeMetric.cpp
<<

CMakeFiles\blizzard.dir\main.cpp.obj: CMakeFiles\blizzard.dir\flags.make
CMakeFiles\blizzard.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\dev\github\blizz-test\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/blizzard.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\blizzard.dir\main.cpp.obj /FdCMakeFiles\blizzard.dir\ /FS -c C:\dev\github\blizz-test\main.cpp
<<

CMakeFiles\blizzard.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blizzard.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\blizzard.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\dev\github\blizz-test\main.cpp
<<

CMakeFiles\blizzard.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blizzard.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\blizzard.dir\main.cpp.s /c C:\dev\github\blizz-test\main.cpp
<<

# Object files for target blizzard
blizzard_OBJECTS = \
"CMakeFiles\blizzard.dir\UniqueDigitsQuestion.cpp.obj" \
"CMakeFiles\blizzard.dir\test\TimeMetric.cpp.obj" \
"CMakeFiles\blizzard.dir\main.cpp.obj"

# External object files for target blizzard
blizzard_EXTERNAL_OBJECTS =

blizzard.exe: CMakeFiles\blizzard.dir\UniqueDigitsQuestion.cpp.obj
blizzard.exe: CMakeFiles\blizzard.dir\test\TimeMetric.cpp.obj
blizzard.exe: CMakeFiles\blizzard.dir\main.cpp.obj
blizzard.exe: CMakeFiles\blizzard.dir\build.make
blizzard.exe: CMakeFiles\blizzard.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\dev\github\blizz-test\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable blizzard.exe"
	C:\jetbrains\apps\CLion\ch-0\203.7148.70\bin\cmake\win\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\blizzard.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\10.0.18362.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\10.0.18362.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\blizzard.dir\objects1.rsp @<<
 /out:blizzard.exe /implib:blizzard.lib /pdb:C:\dev\github\blizz-test\cmake-build-debug\blizzard.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\blizzard.dir\build: blizzard.exe

.PHONY : CMakeFiles\blizzard.dir\build

CMakeFiles\blizzard.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\blizzard.dir\cmake_clean.cmake
.PHONY : CMakeFiles\blizzard.dir\clean

CMakeFiles\blizzard.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\dev\github\blizz-test C:\dev\github\blizz-test C:\dev\github\blizz-test\cmake-build-debug C:\dev\github\blizz-test\cmake-build-debug C:\dev\github\blizz-test\cmake-build-debug\CMakeFiles\blizzard.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\blizzard.dir\depend

