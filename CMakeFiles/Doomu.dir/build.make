# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/mayajama/Projects/openGL/doomu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mayajama/Projects/openGL/doomu

# Include any dependencies generated for this target.
include CMakeFiles/Doomu.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Doomu.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Doomu.dir/flags.make

CMakeFiles/Doomu.dir/src/c_3drender.cpp.o: CMakeFiles/Doomu.dir/flags.make
CMakeFiles/Doomu.dir/src/c_3drender.cpp.o: src/c_3drender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mayajama/Projects/openGL/doomu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Doomu.dir/src/c_3drender.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Doomu.dir/src/c_3drender.cpp.o -c /home/mayajama/Projects/openGL/doomu/src/c_3drender.cpp

CMakeFiles/Doomu.dir/src/c_3drender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Doomu.dir/src/c_3drender.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mayajama/Projects/openGL/doomu/src/c_3drender.cpp > CMakeFiles/Doomu.dir/src/c_3drender.cpp.i

CMakeFiles/Doomu.dir/src/c_3drender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Doomu.dir/src/c_3drender.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mayajama/Projects/openGL/doomu/src/c_3drender.cpp -o CMakeFiles/Doomu.dir/src/c_3drender.cpp.s

CMakeFiles/Doomu.dir/src/c_game.cpp.o: CMakeFiles/Doomu.dir/flags.make
CMakeFiles/Doomu.dir/src/c_game.cpp.o: src/c_game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mayajama/Projects/openGL/doomu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Doomu.dir/src/c_game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Doomu.dir/src/c_game.cpp.o -c /home/mayajama/Projects/openGL/doomu/src/c_game.cpp

CMakeFiles/Doomu.dir/src/c_game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Doomu.dir/src/c_game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mayajama/Projects/openGL/doomu/src/c_game.cpp > CMakeFiles/Doomu.dir/src/c_game.cpp.i

CMakeFiles/Doomu.dir/src/c_game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Doomu.dir/src/c_game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mayajama/Projects/openGL/doomu/src/c_game.cpp -o CMakeFiles/Doomu.dir/src/c_game.cpp.s

CMakeFiles/Doomu.dir/src/c_resmanager.cpp.o: CMakeFiles/Doomu.dir/flags.make
CMakeFiles/Doomu.dir/src/c_resmanager.cpp.o: src/c_resmanager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mayajama/Projects/openGL/doomu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Doomu.dir/src/c_resmanager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Doomu.dir/src/c_resmanager.cpp.o -c /home/mayajama/Projects/openGL/doomu/src/c_resmanager.cpp

CMakeFiles/Doomu.dir/src/c_resmanager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Doomu.dir/src/c_resmanager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mayajama/Projects/openGL/doomu/src/c_resmanager.cpp > CMakeFiles/Doomu.dir/src/c_resmanager.cpp.i

CMakeFiles/Doomu.dir/src/c_resmanager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Doomu.dir/src/c_resmanager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mayajama/Projects/openGL/doomu/src/c_resmanager.cpp -o CMakeFiles/Doomu.dir/src/c_resmanager.cpp.s

CMakeFiles/Doomu.dir/src/c_shader.cpp.o: CMakeFiles/Doomu.dir/flags.make
CMakeFiles/Doomu.dir/src/c_shader.cpp.o: src/c_shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mayajama/Projects/openGL/doomu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Doomu.dir/src/c_shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Doomu.dir/src/c_shader.cpp.o -c /home/mayajama/Projects/openGL/doomu/src/c_shader.cpp

CMakeFiles/Doomu.dir/src/c_shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Doomu.dir/src/c_shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mayajama/Projects/openGL/doomu/src/c_shader.cpp > CMakeFiles/Doomu.dir/src/c_shader.cpp.i

CMakeFiles/Doomu.dir/src/c_shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Doomu.dir/src/c_shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mayajama/Projects/openGL/doomu/src/c_shader.cpp -o CMakeFiles/Doomu.dir/src/c_shader.cpp.s

CMakeFiles/Doomu.dir/src/glad.c.o: CMakeFiles/Doomu.dir/flags.make
CMakeFiles/Doomu.dir/src/glad.c.o: src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mayajama/Projects/openGL/doomu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Doomu.dir/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Doomu.dir/src/glad.c.o   -c /home/mayajama/Projects/openGL/doomu/src/glad.c

CMakeFiles/Doomu.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Doomu.dir/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mayajama/Projects/openGL/doomu/src/glad.c > CMakeFiles/Doomu.dir/src/glad.c.i

CMakeFiles/Doomu.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Doomu.dir/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mayajama/Projects/openGL/doomu/src/glad.c -o CMakeFiles/Doomu.dir/src/glad.c.s

CMakeFiles/Doomu.dir/src/main.cpp.o: CMakeFiles/Doomu.dir/flags.make
CMakeFiles/Doomu.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mayajama/Projects/openGL/doomu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Doomu.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Doomu.dir/src/main.cpp.o -c /home/mayajama/Projects/openGL/doomu/src/main.cpp

CMakeFiles/Doomu.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Doomu.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mayajama/Projects/openGL/doomu/src/main.cpp > CMakeFiles/Doomu.dir/src/main.cpp.i

CMakeFiles/Doomu.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Doomu.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mayajama/Projects/openGL/doomu/src/main.cpp -o CMakeFiles/Doomu.dir/src/main.cpp.s

# Object files for target Doomu
Doomu_OBJECTS = \
"CMakeFiles/Doomu.dir/src/c_3drender.cpp.o" \
"CMakeFiles/Doomu.dir/src/c_game.cpp.o" \
"CMakeFiles/Doomu.dir/src/c_resmanager.cpp.o" \
"CMakeFiles/Doomu.dir/src/c_shader.cpp.o" \
"CMakeFiles/Doomu.dir/src/glad.c.o" \
"CMakeFiles/Doomu.dir/src/main.cpp.o"

# External object files for target Doomu
Doomu_EXTERNAL_OBJECTS =

Doomu: CMakeFiles/Doomu.dir/src/c_3drender.cpp.o
Doomu: CMakeFiles/Doomu.dir/src/c_game.cpp.o
Doomu: CMakeFiles/Doomu.dir/src/c_resmanager.cpp.o
Doomu: CMakeFiles/Doomu.dir/src/c_shader.cpp.o
Doomu: CMakeFiles/Doomu.dir/src/glad.c.o
Doomu: CMakeFiles/Doomu.dir/src/main.cpp.o
Doomu: CMakeFiles/Doomu.dir/build.make
Doomu: CMakeFiles/Doomu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mayajama/Projects/openGL/doomu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Doomu"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Doomu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Doomu.dir/build: Doomu

.PHONY : CMakeFiles/Doomu.dir/build

CMakeFiles/Doomu.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Doomu.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Doomu.dir/clean

CMakeFiles/Doomu.dir/depend:
	cd /home/mayajama/Projects/openGL/doomu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mayajama/Projects/openGL/doomu /home/mayajama/Projects/openGL/doomu /home/mayajama/Projects/openGL/doomu /home/mayajama/Projects/openGL/doomu /home/mayajama/Projects/openGL/doomu/CMakeFiles/Doomu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Doomu.dir/depend

