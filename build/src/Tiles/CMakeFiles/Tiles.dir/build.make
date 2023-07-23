# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kamil/code/Roguelike

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kamil/code/Roguelike/build

# Include any dependencies generated for this target.
include src/Tiles/CMakeFiles/Tiles.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/Tiles/CMakeFiles/Tiles.dir/compiler_depend.make

# Include the progress variables for this target.
include src/Tiles/CMakeFiles/Tiles.dir/progress.make

# Include the compile flags for this target's objects.
include src/Tiles/CMakeFiles/Tiles.dir/flags.make

src/Tiles/CMakeFiles/Tiles.dir/Decoration.cpp.o: src/Tiles/CMakeFiles/Tiles.dir/flags.make
src/Tiles/CMakeFiles/Tiles.dir/Decoration.cpp.o: ../src/Tiles/Decoration.cpp
src/Tiles/CMakeFiles/Tiles.dir/Decoration.cpp.o: src/Tiles/CMakeFiles/Tiles.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kamil/code/Roguelike/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Tiles/CMakeFiles/Tiles.dir/Decoration.cpp.o"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Tiles/CMakeFiles/Tiles.dir/Decoration.cpp.o -MF CMakeFiles/Tiles.dir/Decoration.cpp.o.d -o CMakeFiles/Tiles.dir/Decoration.cpp.o -c /home/kamil/code/Roguelike/src/Tiles/Decoration.cpp

src/Tiles/CMakeFiles/Tiles.dir/Decoration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tiles.dir/Decoration.cpp.i"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kamil/code/Roguelike/src/Tiles/Decoration.cpp > CMakeFiles/Tiles.dir/Decoration.cpp.i

src/Tiles/CMakeFiles/Tiles.dir/Decoration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tiles.dir/Decoration.cpp.s"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kamil/code/Roguelike/src/Tiles/Decoration.cpp -o CMakeFiles/Tiles.dir/Decoration.cpp.s

src/Tiles/CMakeFiles/Tiles.dir/MapParser.cpp.o: src/Tiles/CMakeFiles/Tiles.dir/flags.make
src/Tiles/CMakeFiles/Tiles.dir/MapParser.cpp.o: ../src/Tiles/MapParser.cpp
src/Tiles/CMakeFiles/Tiles.dir/MapParser.cpp.o: src/Tiles/CMakeFiles/Tiles.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kamil/code/Roguelike/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/Tiles/CMakeFiles/Tiles.dir/MapParser.cpp.o"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Tiles/CMakeFiles/Tiles.dir/MapParser.cpp.o -MF CMakeFiles/Tiles.dir/MapParser.cpp.o.d -o CMakeFiles/Tiles.dir/MapParser.cpp.o -c /home/kamil/code/Roguelike/src/Tiles/MapParser.cpp

src/Tiles/CMakeFiles/Tiles.dir/MapParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tiles.dir/MapParser.cpp.i"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kamil/code/Roguelike/src/Tiles/MapParser.cpp > CMakeFiles/Tiles.dir/MapParser.cpp.i

src/Tiles/CMakeFiles/Tiles.dir/MapParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tiles.dir/MapParser.cpp.s"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kamil/code/Roguelike/src/Tiles/MapParser.cpp -o CMakeFiles/Tiles.dir/MapParser.cpp.s

src/Tiles/CMakeFiles/Tiles.dir/Tile.cpp.o: src/Tiles/CMakeFiles/Tiles.dir/flags.make
src/Tiles/CMakeFiles/Tiles.dir/Tile.cpp.o: ../src/Tiles/Tile.cpp
src/Tiles/CMakeFiles/Tiles.dir/Tile.cpp.o: src/Tiles/CMakeFiles/Tiles.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kamil/code/Roguelike/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/Tiles/CMakeFiles/Tiles.dir/Tile.cpp.o"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Tiles/CMakeFiles/Tiles.dir/Tile.cpp.o -MF CMakeFiles/Tiles.dir/Tile.cpp.o.d -o CMakeFiles/Tiles.dir/Tile.cpp.o -c /home/kamil/code/Roguelike/src/Tiles/Tile.cpp

src/Tiles/CMakeFiles/Tiles.dir/Tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tiles.dir/Tile.cpp.i"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kamil/code/Roguelike/src/Tiles/Tile.cpp > CMakeFiles/Tiles.dir/Tile.cpp.i

src/Tiles/CMakeFiles/Tiles.dir/Tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tiles.dir/Tile.cpp.s"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kamil/code/Roguelike/src/Tiles/Tile.cpp -o CMakeFiles/Tiles.dir/Tile.cpp.s

src/Tiles/CMakeFiles/Tiles.dir/TileChunk.cpp.o: src/Tiles/CMakeFiles/Tiles.dir/flags.make
src/Tiles/CMakeFiles/Tiles.dir/TileChunk.cpp.o: ../src/Tiles/TileChunk.cpp
src/Tiles/CMakeFiles/Tiles.dir/TileChunk.cpp.o: src/Tiles/CMakeFiles/Tiles.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kamil/code/Roguelike/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/Tiles/CMakeFiles/Tiles.dir/TileChunk.cpp.o"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Tiles/CMakeFiles/Tiles.dir/TileChunk.cpp.o -MF CMakeFiles/Tiles.dir/TileChunk.cpp.o.d -o CMakeFiles/Tiles.dir/TileChunk.cpp.o -c /home/kamil/code/Roguelike/src/Tiles/TileChunk.cpp

src/Tiles/CMakeFiles/Tiles.dir/TileChunk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tiles.dir/TileChunk.cpp.i"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kamil/code/Roguelike/src/Tiles/TileChunk.cpp > CMakeFiles/Tiles.dir/TileChunk.cpp.i

src/Tiles/CMakeFiles/Tiles.dir/TileChunk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tiles.dir/TileChunk.cpp.s"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kamil/code/Roguelike/src/Tiles/TileChunk.cpp -o CMakeFiles/Tiles.dir/TileChunk.cpp.s

src/Tiles/CMakeFiles/Tiles.dir/TileLoader.cpp.o: src/Tiles/CMakeFiles/Tiles.dir/flags.make
src/Tiles/CMakeFiles/Tiles.dir/TileLoader.cpp.o: ../src/Tiles/TileLoader.cpp
src/Tiles/CMakeFiles/Tiles.dir/TileLoader.cpp.o: src/Tiles/CMakeFiles/Tiles.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kamil/code/Roguelike/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/Tiles/CMakeFiles/Tiles.dir/TileLoader.cpp.o"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Tiles/CMakeFiles/Tiles.dir/TileLoader.cpp.o -MF CMakeFiles/Tiles.dir/TileLoader.cpp.o.d -o CMakeFiles/Tiles.dir/TileLoader.cpp.o -c /home/kamil/code/Roguelike/src/Tiles/TileLoader.cpp

src/Tiles/CMakeFiles/Tiles.dir/TileLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tiles.dir/TileLoader.cpp.i"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kamil/code/Roguelike/src/Tiles/TileLoader.cpp > CMakeFiles/Tiles.dir/TileLoader.cpp.i

src/Tiles/CMakeFiles/Tiles.dir/TileLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tiles.dir/TileLoader.cpp.s"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kamil/code/Roguelike/src/Tiles/TileLoader.cpp -o CMakeFiles/Tiles.dir/TileLoader.cpp.s

src/Tiles/CMakeFiles/Tiles.dir/WorldGenerator.cpp.o: src/Tiles/CMakeFiles/Tiles.dir/flags.make
src/Tiles/CMakeFiles/Tiles.dir/WorldGenerator.cpp.o: ../src/Tiles/WorldGenerator.cpp
src/Tiles/CMakeFiles/Tiles.dir/WorldGenerator.cpp.o: src/Tiles/CMakeFiles/Tiles.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kamil/code/Roguelike/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/Tiles/CMakeFiles/Tiles.dir/WorldGenerator.cpp.o"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Tiles/CMakeFiles/Tiles.dir/WorldGenerator.cpp.o -MF CMakeFiles/Tiles.dir/WorldGenerator.cpp.o.d -o CMakeFiles/Tiles.dir/WorldGenerator.cpp.o -c /home/kamil/code/Roguelike/src/Tiles/WorldGenerator.cpp

src/Tiles/CMakeFiles/Tiles.dir/WorldGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tiles.dir/WorldGenerator.cpp.i"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kamil/code/Roguelike/src/Tiles/WorldGenerator.cpp > CMakeFiles/Tiles.dir/WorldGenerator.cpp.i

src/Tiles/CMakeFiles/Tiles.dir/WorldGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tiles.dir/WorldGenerator.cpp.s"
	cd /home/kamil/code/Roguelike/build/src/Tiles && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kamil/code/Roguelike/src/Tiles/WorldGenerator.cpp -o CMakeFiles/Tiles.dir/WorldGenerator.cpp.s

# Object files for target Tiles
Tiles_OBJECTS = \
"CMakeFiles/Tiles.dir/Decoration.cpp.o" \
"CMakeFiles/Tiles.dir/MapParser.cpp.o" \
"CMakeFiles/Tiles.dir/Tile.cpp.o" \
"CMakeFiles/Tiles.dir/TileChunk.cpp.o" \
"CMakeFiles/Tiles.dir/TileLoader.cpp.o" \
"CMakeFiles/Tiles.dir/WorldGenerator.cpp.o"

# External object files for target Tiles
Tiles_EXTERNAL_OBJECTS =

lib/libTiles.a: src/Tiles/CMakeFiles/Tiles.dir/Decoration.cpp.o
lib/libTiles.a: src/Tiles/CMakeFiles/Tiles.dir/MapParser.cpp.o
lib/libTiles.a: src/Tiles/CMakeFiles/Tiles.dir/Tile.cpp.o
lib/libTiles.a: src/Tiles/CMakeFiles/Tiles.dir/TileChunk.cpp.o
lib/libTiles.a: src/Tiles/CMakeFiles/Tiles.dir/TileLoader.cpp.o
lib/libTiles.a: src/Tiles/CMakeFiles/Tiles.dir/WorldGenerator.cpp.o
lib/libTiles.a: src/Tiles/CMakeFiles/Tiles.dir/build.make
lib/libTiles.a: src/Tiles/CMakeFiles/Tiles.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kamil/code/Roguelike/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library ../../lib/libTiles.a"
	cd /home/kamil/code/Roguelike/build/src/Tiles && $(CMAKE_COMMAND) -P CMakeFiles/Tiles.dir/cmake_clean_target.cmake
	cd /home/kamil/code/Roguelike/build/src/Tiles && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tiles.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Tiles/CMakeFiles/Tiles.dir/build: lib/libTiles.a
.PHONY : src/Tiles/CMakeFiles/Tiles.dir/build

src/Tiles/CMakeFiles/Tiles.dir/clean:
	cd /home/kamil/code/Roguelike/build/src/Tiles && $(CMAKE_COMMAND) -P CMakeFiles/Tiles.dir/cmake_clean.cmake
.PHONY : src/Tiles/CMakeFiles/Tiles.dir/clean

src/Tiles/CMakeFiles/Tiles.dir/depend:
	cd /home/kamil/code/Roguelike/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kamil/code/Roguelike /home/kamil/code/Roguelike/src/Tiles /home/kamil/code/Roguelike/build /home/kamil/code/Roguelike/build/src/Tiles /home/kamil/code/Roguelike/build/src/Tiles/CMakeFiles/Tiles.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Tiles/CMakeFiles/Tiles.dir/depend

