# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\TEMP\CLionProjects\graph-puzzle-game-pelinsupehlevan

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\TEMP\CLionProjects\graph-puzzle-game-pelinsupehlevan\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/flags.make

CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/src/main.cpp.obj: CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/flags.make
CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/src/main.cpp.obj: C:/Users/TEMP/CLionProjects/graph-puzzle-game-pelinsupehlevan/src/main.cpp
CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/src/main.cpp.obj: CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\TEMP\CLionProjects\graph-puzzle-game-pelinsupehlevan\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/src/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/src/main.cpp.obj -MF CMakeFiles\graph-puzzle-game-pelinsupehlevan.dir\src\main.cpp.obj.d -o CMakeFiles\graph-puzzle-game-pelinsupehlevan.dir\src\main.cpp.obj -c C:\Users\TEMP\CLionProjects\graph-puzzle-game-pelinsupehlevan\src\main.cpp

CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/src/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\TEMP\CLionProjects\graph-puzzle-game-pelinsupehlevan\src\main.cpp > CMakeFiles\graph-puzzle-game-pelinsupehlevan.dir\src\main.cpp.i

CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/src/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\TEMP\CLionProjects\graph-puzzle-game-pelinsupehlevan\src\main.cpp -o CMakeFiles\graph-puzzle-game-pelinsupehlevan.dir\src\main.cpp.s

# Object files for target graph-puzzle-game-pelinsupehlevan
graph__puzzle__game__pelinsupehlevan_OBJECTS = \
"CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/src/main.cpp.obj"

# External object files for target graph-puzzle-game-pelinsupehlevan
graph__puzzle__game__pelinsupehlevan_EXTERNAL_OBJECTS =

libgraph-puzzle-game-pelinsupehlevan.a: CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/src/main.cpp.obj
libgraph-puzzle-game-pelinsupehlevan.a: CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/build.make
libgraph-puzzle-game-pelinsupehlevan.a: CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\TEMP\CLionProjects\graph-puzzle-game-pelinsupehlevan\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgraph-puzzle-game-pelinsupehlevan.a"
	$(CMAKE_COMMAND) -P CMakeFiles\graph-puzzle-game-pelinsupehlevan.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\graph-puzzle-game-pelinsupehlevan.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/build: libgraph-puzzle-game-pelinsupehlevan.a
.PHONY : CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/build

CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\graph-puzzle-game-pelinsupehlevan.dir\cmake_clean.cmake
.PHONY : CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/clean

CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\TEMP\CLionProjects\graph-puzzle-game-pelinsupehlevan C:\Users\TEMP\CLionProjects\graph-puzzle-game-pelinsupehlevan C:\Users\TEMP\CLionProjects\graph-puzzle-game-pelinsupehlevan\cmake-build-debug C:\Users\TEMP\CLionProjects\graph-puzzle-game-pelinsupehlevan\cmake-build-debug C:\Users\TEMP\CLionProjects\graph-puzzle-game-pelinsupehlevan\cmake-build-debug\CMakeFiles\graph-puzzle-game-pelinsupehlevan.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/graph-puzzle-game-pelinsupehlevan.dir/depend
