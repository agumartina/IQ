# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/local/clion-2016.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/clion-2016.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sagus/CLionProjects/IQ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sagus/CLionProjects/IQ/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/IQ.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/IQ.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IQ.dir/flags.make

CMakeFiles/IQ.dir/main.c.o: CMakeFiles/IQ.dir/flags.make
CMakeFiles/IQ.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sagus/CLionProjects/IQ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/IQ.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IQ.dir/main.c.o   -c /home/sagus/CLionProjects/IQ/main.c

CMakeFiles/IQ.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IQ.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sagus/CLionProjects/IQ/main.c > CMakeFiles/IQ.dir/main.c.i

CMakeFiles/IQ.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IQ.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sagus/CLionProjects/IQ/main.c -o CMakeFiles/IQ.dir/main.c.s

CMakeFiles/IQ.dir/main.c.o.requires:

.PHONY : CMakeFiles/IQ.dir/main.c.o.requires

CMakeFiles/IQ.dir/main.c.o.provides: CMakeFiles/IQ.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/IQ.dir/build.make CMakeFiles/IQ.dir/main.c.o.provides.build
.PHONY : CMakeFiles/IQ.dir/main.c.o.provides

CMakeFiles/IQ.dir/main.c.o.provides.build: CMakeFiles/IQ.dir/main.c.o


CMakeFiles/IQ.dir/dataN1_header.c.o: CMakeFiles/IQ.dir/flags.make
CMakeFiles/IQ.dir/dataN1_header.c.o: ../dataN1_header.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sagus/CLionProjects/IQ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/IQ.dir/dataN1_header.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IQ.dir/dataN1_header.c.o   -c /home/sagus/CLionProjects/IQ/dataN1_header.c

CMakeFiles/IQ.dir/dataN1_header.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IQ.dir/dataN1_header.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sagus/CLionProjects/IQ/dataN1_header.c > CMakeFiles/IQ.dir/dataN1_header.c.i

CMakeFiles/IQ.dir/dataN1_header.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IQ.dir/dataN1_header.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sagus/CLionProjects/IQ/dataN1_header.c -o CMakeFiles/IQ.dir/dataN1_header.c.s

CMakeFiles/IQ.dir/dataN1_header.c.o.requires:

.PHONY : CMakeFiles/IQ.dir/dataN1_header.c.o.requires

CMakeFiles/IQ.dir/dataN1_header.c.o.provides: CMakeFiles/IQ.dir/dataN1_header.c.o.requires
	$(MAKE) -f CMakeFiles/IQ.dir/build.make CMakeFiles/IQ.dir/dataN1_header.c.o.provides.build
.PHONY : CMakeFiles/IQ.dir/dataN1_header.c.o.provides

CMakeFiles/IQ.dir/dataN1_header.c.o.provides.build: CMakeFiles/IQ.dir/dataN1_header.c.o


CMakeFiles/IQ.dir/dataN1_read.c.o: CMakeFiles/IQ.dir/flags.make
CMakeFiles/IQ.dir/dataN1_read.c.o: ../dataN1_read.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sagus/CLionProjects/IQ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/IQ.dir/dataN1_read.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IQ.dir/dataN1_read.c.o   -c /home/sagus/CLionProjects/IQ/dataN1_read.c

CMakeFiles/IQ.dir/dataN1_read.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IQ.dir/dataN1_read.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sagus/CLionProjects/IQ/dataN1_read.c > CMakeFiles/IQ.dir/dataN1_read.c.i

CMakeFiles/IQ.dir/dataN1_read.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IQ.dir/dataN1_read.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sagus/CLionProjects/IQ/dataN1_read.c -o CMakeFiles/IQ.dir/dataN1_read.c.s

CMakeFiles/IQ.dir/dataN1_read.c.o.requires:

.PHONY : CMakeFiles/IQ.dir/dataN1_read.c.o.requires

CMakeFiles/IQ.dir/dataN1_read.c.o.provides: CMakeFiles/IQ.dir/dataN1_read.c.o.requires
	$(MAKE) -f CMakeFiles/IQ.dir/build.make CMakeFiles/IQ.dir/dataN1_read.c.o.provides.build
.PHONY : CMakeFiles/IQ.dir/dataN1_read.c.o.provides

CMakeFiles/IQ.dir/dataN1_read.c.o.provides.build: CMakeFiles/IQ.dir/dataN1_read.c.o


CMakeFiles/IQ.dir/libs/list.c.o: CMakeFiles/IQ.dir/flags.make
CMakeFiles/IQ.dir/libs/list.c.o: ../libs/list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sagus/CLionProjects/IQ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/IQ.dir/libs/list.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IQ.dir/libs/list.c.o   -c /home/sagus/CLionProjects/IQ/libs/list.c

CMakeFiles/IQ.dir/libs/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IQ.dir/libs/list.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sagus/CLionProjects/IQ/libs/list.c > CMakeFiles/IQ.dir/libs/list.c.i

CMakeFiles/IQ.dir/libs/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IQ.dir/libs/list.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sagus/CLionProjects/IQ/libs/list.c -o CMakeFiles/IQ.dir/libs/list.c.s

CMakeFiles/IQ.dir/libs/list.c.o.requires:

.PHONY : CMakeFiles/IQ.dir/libs/list.c.o.requires

CMakeFiles/IQ.dir/libs/list.c.o.provides: CMakeFiles/IQ.dir/libs/list.c.o.requires
	$(MAKE) -f CMakeFiles/IQ.dir/build.make CMakeFiles/IQ.dir/libs/list.c.o.provides.build
.PHONY : CMakeFiles/IQ.dir/libs/list.c.o.provides

CMakeFiles/IQ.dir/libs/list.c.o.provides.build: CMakeFiles/IQ.dir/libs/list.c.o


# Object files for target IQ
IQ_OBJECTS = \
"CMakeFiles/IQ.dir/main.c.o" \
"CMakeFiles/IQ.dir/dataN1_header.c.o" \
"CMakeFiles/IQ.dir/dataN1_read.c.o" \
"CMakeFiles/IQ.dir/libs/list.c.o"

# External object files for target IQ
IQ_EXTERNAL_OBJECTS =

IQ: CMakeFiles/IQ.dir/main.c.o
IQ: CMakeFiles/IQ.dir/dataN1_header.c.o
IQ: CMakeFiles/IQ.dir/dataN1_read.c.o
IQ: CMakeFiles/IQ.dir/libs/list.c.o
IQ: CMakeFiles/IQ.dir/build.make
IQ: CMakeFiles/IQ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sagus/CLionProjects/IQ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable IQ"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IQ.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IQ.dir/build: IQ

.PHONY : CMakeFiles/IQ.dir/build

CMakeFiles/IQ.dir/requires: CMakeFiles/IQ.dir/main.c.o.requires
CMakeFiles/IQ.dir/requires: CMakeFiles/IQ.dir/dataN1_header.c.o.requires
CMakeFiles/IQ.dir/requires: CMakeFiles/IQ.dir/dataN1_read.c.o.requires
CMakeFiles/IQ.dir/requires: CMakeFiles/IQ.dir/libs/list.c.o.requires

.PHONY : CMakeFiles/IQ.dir/requires

CMakeFiles/IQ.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IQ.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IQ.dir/clean

CMakeFiles/IQ.dir/depend:
	cd /home/sagus/CLionProjects/IQ/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sagus/CLionProjects/IQ /home/sagus/CLionProjects/IQ /home/sagus/CLionProjects/IQ/cmake-build-debug /home/sagus/CLionProjects/IQ/cmake-build-debug /home/sagus/CLionProjects/IQ/cmake-build-debug/CMakeFiles/IQ.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IQ.dir/depend

