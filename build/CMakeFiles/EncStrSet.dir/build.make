# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Maks\Documents\C++\jnp1\zadanie2\EncStrSet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Maks\Documents\C++\jnp1\zadanie2\EncStrSet\build

# Include any dependencies generated for this target.
include CMakeFiles/EncStrSet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EncStrSet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EncStrSet.dir/flags.make

CMakeFiles/EncStrSet.dir/encstrset_test1.c.obj: CMakeFiles/EncStrSet.dir/flags.make
CMakeFiles/EncStrSet.dir/encstrset_test1.c.obj: ../encstrset_test1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Maks\Documents\C++\jnp1\zadanie2\EncStrSet\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/EncStrSet.dir/encstrset_test1.c.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\EncStrSet.dir\encstrset_test1.c.obj -c C:\Users\Maks\Documents\C++\jnp1\zadanie2\EncStrSet\encstrset_test1.c

CMakeFiles/EncStrSet.dir/encstrset_test1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/EncStrSet.dir/encstrset_test1.c.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Maks\Documents\C++\jnp1\zadanie2\EncStrSet\encstrset_test1.c > CMakeFiles\EncStrSet.dir\encstrset_test1.c.i

CMakeFiles/EncStrSet.dir/encstrset_test1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/EncStrSet.dir/encstrset_test1.c.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Maks\Documents\C++\jnp1\zadanie2\EncStrSet\encstrset_test1.c -o CMakeFiles\EncStrSet.dir\encstrset_test1.c.s

CMakeFiles/EncStrSet.dir/encstrset.cc.obj: CMakeFiles/EncStrSet.dir/flags.make
CMakeFiles/EncStrSet.dir/encstrset.cc.obj: ../encstrset.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Maks\Documents\C++\jnp1\zadanie2\EncStrSet\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/EncStrSet.dir/encstrset.cc.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\EncStrSet.dir\encstrset.cc.obj -c C:\Users\Maks\Documents\C++\jnp1\zadanie2\EncStrSet\encstrset.cc

CMakeFiles/EncStrSet.dir/encstrset.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EncStrSet.dir/encstrset.cc.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Maks\Documents\C++\jnp1\zadanie2\EncStrSet\encstrset.cc > CMakeFiles\EncStrSet.dir\encstrset.cc.i

CMakeFiles/EncStrSet.dir/encstrset.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EncStrSet.dir/encstrset.cc.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Maks\Documents\C++\jnp1\zadanie2\EncStrSet\encstrset.cc -o CMakeFiles\EncStrSet.dir\encstrset.cc.s

# Object files for target EncStrSet
EncStrSet_OBJECTS = \
"CMakeFiles/EncStrSet.dir/encstrset_test1.c.obj" \
"CMakeFiles/EncStrSet.dir/encstrset.cc.obj"

# External object files for target EncStrSet
EncStrSet_EXTERNAL_OBJECTS =

EncStrSet.exe: CMakeFiles/EncStrSet.dir/encstrset_test1.c.obj
EncStrSet.exe: CMakeFiles/EncStrSet.dir/encstrset.cc.obj
EncStrSet.exe: CMakeFiles/EncStrSet.dir/build.make
EncStrSet.exe: CMakeFiles/EncStrSet.dir/linklibs.rsp
EncStrSet.exe: CMakeFiles/EncStrSet.dir/objects1.rsp
EncStrSet.exe: CMakeFiles/EncStrSet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Maks\Documents\C++\jnp1\zadanie2\EncStrSet\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable EncStrSet.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\EncStrSet.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EncStrSet.dir/build: EncStrSet.exe

.PHONY : CMakeFiles/EncStrSet.dir/build

CMakeFiles/EncStrSet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\EncStrSet.dir\cmake_clean.cmake
.PHONY : CMakeFiles/EncStrSet.dir/clean

CMakeFiles/EncStrSet.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Maks\Documents\C++\jnp1\zadanie2\EncStrSet C:\Users\Maks\Documents\C++\jnp1\zadanie2\EncStrSet C:\Users\Maks\Documents\C++\jnp1\zadanie2\EncStrSet\build C:\Users\Maks\Documents\C++\jnp1\zadanie2\EncStrSet\build C:\Users\Maks\Documents\C++\jnp1\zadanie2\EncStrSet\build\CMakeFiles\EncStrSet.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EncStrSet.dir/depend

