# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mayajama/Projects/openGL/doomu/CMakeFiles /home/mayajama/Projects/openGL/doomu/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mayajama/Projects/openGL/doomu/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Doomu

# Build rule for target.
Doomu: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Doomu
.PHONY : Doomu

# fast build rule for target.
Doomu/fast:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/build
.PHONY : Doomu/fast

src/c_3drender.o: src/c_3drender.cpp.o

.PHONY : src/c_3drender.o

# target to build an object file
src/c_3drender.cpp.o:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_3drender.cpp.o
.PHONY : src/c_3drender.cpp.o

src/c_3drender.i: src/c_3drender.cpp.i

.PHONY : src/c_3drender.i

# target to preprocess a source file
src/c_3drender.cpp.i:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_3drender.cpp.i
.PHONY : src/c_3drender.cpp.i

src/c_3drender.s: src/c_3drender.cpp.s

.PHONY : src/c_3drender.s

# target to generate assembly for a file
src/c_3drender.cpp.s:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_3drender.cpp.s
.PHONY : src/c_3drender.cpp.s

src/c_camera.o: src/c_camera.cpp.o

.PHONY : src/c_camera.o

# target to build an object file
src/c_camera.cpp.o:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_camera.cpp.o
.PHONY : src/c_camera.cpp.o

src/c_camera.i: src/c_camera.cpp.i

.PHONY : src/c_camera.i

# target to preprocess a source file
src/c_camera.cpp.i:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_camera.cpp.i
.PHONY : src/c_camera.cpp.i

src/c_camera.s: src/c_camera.cpp.s

.PHONY : src/c_camera.s

# target to generate assembly for a file
src/c_camera.cpp.s:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_camera.cpp.s
.PHONY : src/c_camera.cpp.s

src/c_colmanager.o: src/c_colmanager.cpp.o

.PHONY : src/c_colmanager.o

# target to build an object file
src/c_colmanager.cpp.o:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_colmanager.cpp.o
.PHONY : src/c_colmanager.cpp.o

src/c_colmanager.i: src/c_colmanager.cpp.i

.PHONY : src/c_colmanager.i

# target to preprocess a source file
src/c_colmanager.cpp.i:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_colmanager.cpp.i
.PHONY : src/c_colmanager.cpp.i

src/c_colmanager.s: src/c_colmanager.cpp.s

.PHONY : src/c_colmanager.s

# target to generate assembly for a file
src/c_colmanager.cpp.s:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_colmanager.cpp.s
.PHONY : src/c_colmanager.cpp.s

src/c_enemyobject.o: src/c_enemyobject.cpp.o

.PHONY : src/c_enemyobject.o

# target to build an object file
src/c_enemyobject.cpp.o:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_enemyobject.cpp.o
.PHONY : src/c_enemyobject.cpp.o

src/c_enemyobject.i: src/c_enemyobject.cpp.i

.PHONY : src/c_enemyobject.i

# target to preprocess a source file
src/c_enemyobject.cpp.i:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_enemyobject.cpp.i
.PHONY : src/c_enemyobject.cpp.i

src/c_enemyobject.s: src/c_enemyobject.cpp.s

.PHONY : src/c_enemyobject.s

# target to generate assembly for a file
src/c_enemyobject.cpp.s:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_enemyobject.cpp.s
.PHONY : src/c_enemyobject.cpp.s

src/c_game.o: src/c_game.cpp.o

.PHONY : src/c_game.o

# target to build an object file
src/c_game.cpp.o:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_game.cpp.o
.PHONY : src/c_game.cpp.o

src/c_game.i: src/c_game.cpp.i

.PHONY : src/c_game.i

# target to preprocess a source file
src/c_game.cpp.i:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_game.cpp.i
.PHONY : src/c_game.cpp.i

src/c_game.s: src/c_game.cpp.s

.PHONY : src/c_game.s

# target to generate assembly for a file
src/c_game.cpp.s:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_game.cpp.s
.PHONY : src/c_game.cpp.s

src/c_gameobject.o: src/c_gameobject.cpp.o

.PHONY : src/c_gameobject.o

# target to build an object file
src/c_gameobject.cpp.o:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_gameobject.cpp.o
.PHONY : src/c_gameobject.cpp.o

src/c_gameobject.i: src/c_gameobject.cpp.i

.PHONY : src/c_gameobject.i

# target to preprocess a source file
src/c_gameobject.cpp.i:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_gameobject.cpp.i
.PHONY : src/c_gameobject.cpp.i

src/c_gameobject.s: src/c_gameobject.cpp.s

.PHONY : src/c_gameobject.s

# target to generate assembly for a file
src/c_gameobject.cpp.s:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_gameobject.cpp.s
.PHONY : src/c_gameobject.cpp.s

src/c_playerobject.o: src/c_playerobject.cpp.o

.PHONY : src/c_playerobject.o

# target to build an object file
src/c_playerobject.cpp.o:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_playerobject.cpp.o
.PHONY : src/c_playerobject.cpp.o

src/c_playerobject.i: src/c_playerobject.cpp.i

.PHONY : src/c_playerobject.i

# target to preprocess a source file
src/c_playerobject.cpp.i:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_playerobject.cpp.i
.PHONY : src/c_playerobject.cpp.i

src/c_playerobject.s: src/c_playerobject.cpp.s

.PHONY : src/c_playerobject.s

# target to generate assembly for a file
src/c_playerobject.cpp.s:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_playerobject.cpp.s
.PHONY : src/c_playerobject.cpp.s

src/c_resmanager.o: src/c_resmanager.cpp.o

.PHONY : src/c_resmanager.o

# target to build an object file
src/c_resmanager.cpp.o:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_resmanager.cpp.o
.PHONY : src/c_resmanager.cpp.o

src/c_resmanager.i: src/c_resmanager.cpp.i

.PHONY : src/c_resmanager.i

# target to preprocess a source file
src/c_resmanager.cpp.i:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_resmanager.cpp.i
.PHONY : src/c_resmanager.cpp.i

src/c_resmanager.s: src/c_resmanager.cpp.s

.PHONY : src/c_resmanager.s

# target to generate assembly for a file
src/c_resmanager.cpp.s:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_resmanager.cpp.s
.PHONY : src/c_resmanager.cpp.s

src/c_shader.o: src/c_shader.cpp.o

.PHONY : src/c_shader.o

# target to build an object file
src/c_shader.cpp.o:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_shader.cpp.o
.PHONY : src/c_shader.cpp.o

src/c_shader.i: src/c_shader.cpp.i

.PHONY : src/c_shader.i

# target to preprocess a source file
src/c_shader.cpp.i:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_shader.cpp.i
.PHONY : src/c_shader.cpp.i

src/c_shader.s: src/c_shader.cpp.s

.PHONY : src/c_shader.s

# target to generate assembly for a file
src/c_shader.cpp.s:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_shader.cpp.s
.PHONY : src/c_shader.cpp.s

src/c_sprite.o: src/c_sprite.cpp.o

.PHONY : src/c_sprite.o

# target to build an object file
src/c_sprite.cpp.o:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_sprite.cpp.o
.PHONY : src/c_sprite.cpp.o

src/c_sprite.i: src/c_sprite.cpp.i

.PHONY : src/c_sprite.i

# target to preprocess a source file
src/c_sprite.cpp.i:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_sprite.cpp.i
.PHONY : src/c_sprite.cpp.i

src/c_sprite.s: src/c_sprite.cpp.s

.PHONY : src/c_sprite.s

# target to generate assembly for a file
src/c_sprite.cpp.s:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_sprite.cpp.s
.PHONY : src/c_sprite.cpp.s

src/c_texture.o: src/c_texture.cpp.o

.PHONY : src/c_texture.o

# target to build an object file
src/c_texture.cpp.o:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_texture.cpp.o
.PHONY : src/c_texture.cpp.o

src/c_texture.i: src/c_texture.cpp.i

.PHONY : src/c_texture.i

# target to preprocess a source file
src/c_texture.cpp.i:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_texture.cpp.i
.PHONY : src/c_texture.cpp.i

src/c_texture.s: src/c_texture.cpp.s

.PHONY : src/c_texture.s

# target to generate assembly for a file
src/c_texture.cpp.s:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/c_texture.cpp.s
.PHONY : src/c_texture.cpp.s

src/glad.o: src/glad.c.o

.PHONY : src/glad.o

# target to build an object file
src/glad.c.o:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/glad.c.o
.PHONY : src/glad.c.o

src/glad.i: src/glad.c.i

.PHONY : src/glad.i

# target to preprocess a source file
src/glad.c.i:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/glad.c.i
.PHONY : src/glad.c.i

src/glad.s: src/glad.c.s

.PHONY : src/glad.s

# target to generate assembly for a file
src/glad.c.s:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/glad.c.s
.PHONY : src/glad.c.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/Doomu.dir/build.make CMakeFiles/Doomu.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... Doomu"
	@echo "... src/c_3drender.o"
	@echo "... src/c_3drender.i"
	@echo "... src/c_3drender.s"
	@echo "... src/c_camera.o"
	@echo "... src/c_camera.i"
	@echo "... src/c_camera.s"
	@echo "... src/c_colmanager.o"
	@echo "... src/c_colmanager.i"
	@echo "... src/c_colmanager.s"
	@echo "... src/c_enemyobject.o"
	@echo "... src/c_enemyobject.i"
	@echo "... src/c_enemyobject.s"
	@echo "... src/c_game.o"
	@echo "... src/c_game.i"
	@echo "... src/c_game.s"
	@echo "... src/c_gameobject.o"
	@echo "... src/c_gameobject.i"
	@echo "... src/c_gameobject.s"
	@echo "... src/c_playerobject.o"
	@echo "... src/c_playerobject.i"
	@echo "... src/c_playerobject.s"
	@echo "... src/c_resmanager.o"
	@echo "... src/c_resmanager.i"
	@echo "... src/c_resmanager.s"
	@echo "... src/c_shader.o"
	@echo "... src/c_shader.i"
	@echo "... src/c_shader.s"
	@echo "... src/c_sprite.o"
	@echo "... src/c_sprite.i"
	@echo "... src/c_sprite.s"
	@echo "... src/c_texture.o"
	@echo "... src/c_texture.i"
	@echo "... src/c_texture.s"
	@echo "... src/glad.o"
	@echo "... src/glad.i"
	@echo "... src/glad.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

