# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = D:\DevelopmentTools\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = D:\DevelopmentTools\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Code\DataStructure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Code\DataStructure\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/flags.make

CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/List/CircularDoublyLinkedListWithHeadNode.c.obj: CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/flags.make
CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/List/CircularDoublyLinkedListWithHeadNode.c.obj: D:/Code/DataStructure/List/CircularDoublyLinkedListWithHeadNode.c
CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/List/CircularDoublyLinkedListWithHeadNode.c.obj: CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Code\DataStructure\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/List/CircularDoublyLinkedListWithHeadNode.c.obj"
	D:\DevelopmentTools\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/List/CircularDoublyLinkedListWithHeadNode.c.obj -MF CMakeFiles\CircularDoublyLinkedListWithHeadNode.dir\List\CircularDoublyLinkedListWithHeadNode.c.obj.d -o CMakeFiles\CircularDoublyLinkedListWithHeadNode.dir\List\CircularDoublyLinkedListWithHeadNode.c.obj -c D:\Code\DataStructure\List\CircularDoublyLinkedListWithHeadNode.c

CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/List/CircularDoublyLinkedListWithHeadNode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/List/CircularDoublyLinkedListWithHeadNode.c.i"
	D:\DevelopmentTools\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Code\DataStructure\List\CircularDoublyLinkedListWithHeadNode.c > CMakeFiles\CircularDoublyLinkedListWithHeadNode.dir\List\CircularDoublyLinkedListWithHeadNode.c.i

CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/List/CircularDoublyLinkedListWithHeadNode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/List/CircularDoublyLinkedListWithHeadNode.c.s"
	D:\DevelopmentTools\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Code\DataStructure\List\CircularDoublyLinkedListWithHeadNode.c -o CMakeFiles\CircularDoublyLinkedListWithHeadNode.dir\List\CircularDoublyLinkedListWithHeadNode.c.s

# Object files for target CircularDoublyLinkedListWithHeadNode
CircularDoublyLinkedListWithHeadNode_OBJECTS = \
"CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/List/CircularDoublyLinkedListWithHeadNode.c.obj"

# External object files for target CircularDoublyLinkedListWithHeadNode
CircularDoublyLinkedListWithHeadNode_EXTERNAL_OBJECTS =

CircularDoublyLinkedListWithHeadNode.exe: CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/List/CircularDoublyLinkedListWithHeadNode.c.obj
CircularDoublyLinkedListWithHeadNode.exe: CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/build.make
CircularDoublyLinkedListWithHeadNode.exe: CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/linkLibs.rsp
CircularDoublyLinkedListWithHeadNode.exe: CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/objects1.rsp
CircularDoublyLinkedListWithHeadNode.exe: CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\Code\DataStructure\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable CircularDoublyLinkedListWithHeadNode.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CircularDoublyLinkedListWithHeadNode.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/build: CircularDoublyLinkedListWithHeadNode.exe
.PHONY : CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/build

CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CircularDoublyLinkedListWithHeadNode.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/clean

CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code\DataStructure D:\Code\DataStructure D:\Code\DataStructure\cmake-build-debug D:\Code\DataStructure\cmake-build-debug D:\Code\DataStructure\cmake-build-debug\CMakeFiles\CircularDoublyLinkedListWithHeadNode.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/CircularDoublyLinkedListWithHeadNode.dir/depend

