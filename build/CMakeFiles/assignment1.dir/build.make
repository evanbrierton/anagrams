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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.16.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.16.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/build"

# Include any dependencies generated for this target.
include CMakeFiles/assignment1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/assignment1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/assignment1.dir/flags.make

CMakeFiles/assignment1.dir/main.c.o: CMakeFiles/assignment1.dir/flags.make
CMakeFiles/assignment1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/assignment1.dir/main.c.o"
	/usr/local/bin/x86_64-apple-darwin19-gcc-9.2.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/assignment1.dir/main.c.o   -c "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/main.c"

CMakeFiles/assignment1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/assignment1.dir/main.c.i"
	/usr/local/bin/x86_64-apple-darwin19-gcc-9.2.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/main.c" > CMakeFiles/assignment1.dir/main.c.i

CMakeFiles/assignment1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/assignment1.dir/main.c.s"
	/usr/local/bin/x86_64-apple-darwin19-gcc-9.2.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/main.c" -o CMakeFiles/assignment1.dir/main.c.s

CMakeFiles/assignment1.dir/io.c.o: CMakeFiles/assignment1.dir/flags.make
CMakeFiles/assignment1.dir/io.c.o: ../io.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/assignment1.dir/io.c.o"
	/usr/local/bin/x86_64-apple-darwin19-gcc-9.2.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/assignment1.dir/io.c.o   -c "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/io.c"

CMakeFiles/assignment1.dir/io.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/assignment1.dir/io.c.i"
	/usr/local/bin/x86_64-apple-darwin19-gcc-9.2.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/io.c" > CMakeFiles/assignment1.dir/io.c.i

CMakeFiles/assignment1.dir/io.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/assignment1.dir/io.c.s"
	/usr/local/bin/x86_64-apple-darwin19-gcc-9.2.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/io.c" -o CMakeFiles/assignment1.dir/io.c.s

CMakeFiles/assignment1.dir/sort.c.o: CMakeFiles/assignment1.dir/flags.make
CMakeFiles/assignment1.dir/sort.c.o: ../sort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/assignment1.dir/sort.c.o"
	/usr/local/bin/x86_64-apple-darwin19-gcc-9.2.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/assignment1.dir/sort.c.o   -c "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/sort.c"

CMakeFiles/assignment1.dir/sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/assignment1.dir/sort.c.i"
	/usr/local/bin/x86_64-apple-darwin19-gcc-9.2.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/sort.c" > CMakeFiles/assignment1.dir/sort.c.i

CMakeFiles/assignment1.dir/sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/assignment1.dir/sort.c.s"
	/usr/local/bin/x86_64-apple-darwin19-gcc-9.2.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/sort.c" -o CMakeFiles/assignment1.dir/sort.c.s

CMakeFiles/assignment1.dir/anagrams.c.o: CMakeFiles/assignment1.dir/flags.make
CMakeFiles/assignment1.dir/anagrams.c.o: ../anagrams.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/assignment1.dir/anagrams.c.o"
	/usr/local/bin/x86_64-apple-darwin19-gcc-9.2.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/assignment1.dir/anagrams.c.o   -c "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/anagrams.c"

CMakeFiles/assignment1.dir/anagrams.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/assignment1.dir/anagrams.c.i"
	/usr/local/bin/x86_64-apple-darwin19-gcc-9.2.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/anagrams.c" > CMakeFiles/assignment1.dir/anagrams.c.i

CMakeFiles/assignment1.dir/anagrams.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/assignment1.dir/anagrams.c.s"
	/usr/local/bin/x86_64-apple-darwin19-gcc-9.2.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/anagrams.c" -o CMakeFiles/assignment1.dir/anagrams.c.s

CMakeFiles/assignment1.dir/utils.c.o: CMakeFiles/assignment1.dir/flags.make
CMakeFiles/assignment1.dir/utils.c.o: ../utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/assignment1.dir/utils.c.o"
	/usr/local/bin/x86_64-apple-darwin19-gcc-9.2.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/assignment1.dir/utils.c.o   -c "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/utils.c"

CMakeFiles/assignment1.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/assignment1.dir/utils.c.i"
	/usr/local/bin/x86_64-apple-darwin19-gcc-9.2.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/utils.c" > CMakeFiles/assignment1.dir/utils.c.i

CMakeFiles/assignment1.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/assignment1.dir/utils.c.s"
	/usr/local/bin/x86_64-apple-darwin19-gcc-9.2.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/utils.c" -o CMakeFiles/assignment1.dir/utils.c.s

# Object files for target assignment1
assignment1_OBJECTS = \
"CMakeFiles/assignment1.dir/main.c.o" \
"CMakeFiles/assignment1.dir/io.c.o" \
"CMakeFiles/assignment1.dir/sort.c.o" \
"CMakeFiles/assignment1.dir/anagrams.c.o" \
"CMakeFiles/assignment1.dir/utils.c.o"

# External object files for target assignment1
assignment1_EXTERNAL_OBJECTS =

assignment1: CMakeFiles/assignment1.dir/main.c.o
assignment1: CMakeFiles/assignment1.dir/io.c.o
assignment1: CMakeFiles/assignment1.dir/sort.c.o
assignment1: CMakeFiles/assignment1.dir/anagrams.c.o
assignment1: CMakeFiles/assignment1.dir/utils.c.o
assignment1: CMakeFiles/assignment1.dir/build.make
assignment1: CMakeFiles/assignment1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable assignment1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/assignment1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/assignment1.dir/build: assignment1

.PHONY : CMakeFiles/assignment1.dir/build

CMakeFiles/assignment1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/assignment1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/assignment1.dir/clean

CMakeFiles/assignment1.dir/depend:
	cd "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1" "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1" "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/build" "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/build" "/Users/evanbrierton/Desktop/Computer Science/Stage 1/Spring/Software Engineering Project 1/assignment1/build/CMakeFiles/assignment1.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/assignment1.dir/depend

