# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /home/l1nkkk/opt/clion-2021.1.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/l1nkkk/opt/clion-2021.1.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/l1nkkk/project/mime/leetcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/l1nkkk/project/mime/leetcode/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/multiThread.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/multiThread.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/multiThread.dir/flags.make

CMakeFiles/multiThread.dir/multiThread/main.cpp.o: CMakeFiles/multiThread.dir/flags.make
CMakeFiles/multiThread.dir/multiThread/main.cpp.o: ../multiThread/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/l1nkkk/project/mime/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/multiThread.dir/multiThread/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/multiThread.dir/multiThread/main.cpp.o -c /home/l1nkkk/project/mime/leetcode/multiThread/main.cpp

CMakeFiles/multiThread.dir/multiThread/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/multiThread.dir/multiThread/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/l1nkkk/project/mime/leetcode/multiThread/main.cpp > CMakeFiles/multiThread.dir/multiThread/main.cpp.i

CMakeFiles/multiThread.dir/multiThread/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/multiThread.dir/multiThread/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/l1nkkk/project/mime/leetcode/multiThread/main.cpp -o CMakeFiles/multiThread.dir/multiThread/main.cpp.s

# Object files for target multiThread
multiThread_OBJECTS = \
"CMakeFiles/multiThread.dir/multiThread/main.cpp.o"

# External object files for target multiThread
multiThread_EXTERNAL_OBJECTS =

multiThread: CMakeFiles/multiThread.dir/multiThread/main.cpp.o
multiThread: CMakeFiles/multiThread.dir/build.make
multiThread: CMakeFiles/multiThread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/l1nkkk/project/mime/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable multiThread"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/multiThread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/multiThread.dir/build: multiThread

.PHONY : CMakeFiles/multiThread.dir/build

CMakeFiles/multiThread.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/multiThread.dir/cmake_clean.cmake
.PHONY : CMakeFiles/multiThread.dir/clean

CMakeFiles/multiThread.dir/depend:
	cd /home/l1nkkk/project/mime/leetcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/l1nkkk/project/mime/leetcode /home/l1nkkk/project/mime/leetcode /home/l1nkkk/project/mime/leetcode/cmake-build-debug /home/l1nkkk/project/mime/leetcode/cmake-build-debug /home/l1nkkk/project/mime/leetcode/cmake-build-debug/CMakeFiles/multiThread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/multiThread.dir/depend

