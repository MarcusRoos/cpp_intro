# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Satan\Desktop\Skola\Universitet\Avklarade_kurser\Intro C++\master\NyLabb\Project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Satan\Desktop\Skola\Universitet\Avklarade_kurser\Intro C++\master\NyLabb\Project\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Project-Project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project-Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project-Project.dir/flags.make

CMakeFiles/Project-Project.dir/src/Definitions.obj: CMakeFiles/Project-Project.dir/flags.make
CMakeFiles/Project-Project.dir/src/Definitions.obj: CMakeFiles/Project-Project.dir/includes_CXX.rsp
CMakeFiles/Project-Project.dir/src/Definitions.obj: ../src/Definitions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Satan\Desktop\Skola\Universitet\Avklarade_kurser\Intro C++\master\NyLabb\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project-Project.dir/src/Definitions.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project-Project.dir\src\Definitions.obj -c "C:\Users\Satan\Desktop\Skola\Universitet\Avklarade_kurser\Intro C++\master\NyLabb\Project\src\Definitions.cpp"

CMakeFiles/Project-Project.dir/src/Definitions.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project-Project.dir/src/Definitions.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Satan\Desktop\Skola\Universitet\Avklarade_kurser\Intro C++\master\NyLabb\Project\src\Definitions.cpp" > CMakeFiles\Project-Project.dir\src\Definitions.i

CMakeFiles/Project-Project.dir/src/Definitions.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project-Project.dir/src/Definitions.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Satan\Desktop\Skola\Universitet\Avklarade_kurser\Intro C++\master\NyLabb\Project\src\Definitions.cpp" -o CMakeFiles\Project-Project.dir\src\Definitions.s

CMakeFiles/Project-Project.dir/src/main.obj: CMakeFiles/Project-Project.dir/flags.make
CMakeFiles/Project-Project.dir/src/main.obj: CMakeFiles/Project-Project.dir/includes_CXX.rsp
CMakeFiles/Project-Project.dir/src/main.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Satan\Desktop\Skola\Universitet\Avklarade_kurser\Intro C++\master\NyLabb\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project-Project.dir/src/main.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project-Project.dir\src\main.obj -c "C:\Users\Satan\Desktop\Skola\Universitet\Avklarade_kurser\Intro C++\master\NyLabb\Project\src\main.cpp"

CMakeFiles/Project-Project.dir/src/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project-Project.dir/src/main.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Satan\Desktop\Skola\Universitet\Avklarade_kurser\Intro C++\master\NyLabb\Project\src\main.cpp" > CMakeFiles\Project-Project.dir\src\main.i

CMakeFiles/Project-Project.dir/src/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project-Project.dir/src/main.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Satan\Desktop\Skola\Universitet\Avklarade_kurser\Intro C++\master\NyLabb\Project\src\main.cpp" -o CMakeFiles\Project-Project.dir\src\main.s

# Object files for target Project-Project
Project__Project_OBJECTS = \
"CMakeFiles/Project-Project.dir/src/Definitions.obj" \
"CMakeFiles/Project-Project.dir/src/main.obj"

# External object files for target Project-Project
Project__Project_EXTERNAL_OBJECTS =

Project-Project.exe: CMakeFiles/Project-Project.dir/src/Definitions.obj
Project-Project.exe: CMakeFiles/Project-Project.dir/src/main.obj
Project-Project.exe: CMakeFiles/Project-Project.dir/build.make
Project-Project.exe: CMakeFiles/Project-Project.dir/linklibs.rsp
Project-Project.exe: CMakeFiles/Project-Project.dir/objects1.rsp
Project-Project.exe: CMakeFiles/Project-Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Satan\Desktop\Skola\Universitet\Avklarade_kurser\Intro C++\master\NyLabb\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Project-Project.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Project-Project.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project-Project.dir/build: Project-Project.exe

.PHONY : CMakeFiles/Project-Project.dir/build

CMakeFiles/Project-Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Project-Project.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Project-Project.dir/clean

CMakeFiles/Project-Project.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Satan\Desktop\Skola\Universitet\Avklarade_kurser\Intro C++\master\NyLabb\Project" "C:\Users\Satan\Desktop\Skola\Universitet\Avklarade_kurser\Intro C++\master\NyLabb\Project" "C:\Users\Satan\Desktop\Skola\Universitet\Avklarade_kurser\Intro C++\master\NyLabb\Project\cmake-build-debug" "C:\Users\Satan\Desktop\Skola\Universitet\Avklarade_kurser\Intro C++\master\NyLabb\Project\cmake-build-debug" "C:\Users\Satan\Desktop\Skola\Universitet\Avklarade_kurser\Intro C++\master\NyLabb\Project\cmake-build-debug\CMakeFiles\Project-Project.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Project-Project.dir/depend

