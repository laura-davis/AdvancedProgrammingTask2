# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lda49/Projects/AdvancedProgrammingTask2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug

# Include any dependencies generated for this target.
include Client/CMakeFiles/Client.dir/depend.make
# Include the progress variables for this target.
include Client/CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include Client/CMakeFiles/Client.dir/flags.make

Client/CMakeFiles/Client.dir/Client.cpp.o: Client/CMakeFiles/Client.dir/flags.make
Client/CMakeFiles/Client.dir/Client.cpp.o: ../Client/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Client/CMakeFiles/Client.dir/Client.cpp.o"
	cd /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/Client && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Client.cpp.o -c /Users/lda49/Projects/AdvancedProgrammingTask2/Client/Client.cpp

Client/CMakeFiles/Client.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Client.cpp.i"
	cd /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/Client && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lda49/Projects/AdvancedProgrammingTask2/Client/Client.cpp > CMakeFiles/Client.dir/Client.cpp.i

Client/CMakeFiles/Client.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Client.cpp.s"
	cd /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/Client && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lda49/Projects/AdvancedProgrammingTask2/Client/Client.cpp -o CMakeFiles/Client.dir/Client.cpp.s

Client/CMakeFiles/Client.dir/main.cpp.o: Client/CMakeFiles/Client.dir/flags.make
Client/CMakeFiles/Client.dir/main.cpp.o: ../Client/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Client/CMakeFiles/Client.dir/main.cpp.o"
	cd /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/Client && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/main.cpp.o -c /Users/lda49/Projects/AdvancedProgrammingTask2/Client/main.cpp

Client/CMakeFiles/Client.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/main.cpp.i"
	cd /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/Client && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lda49/Projects/AdvancedProgrammingTask2/Client/main.cpp > CMakeFiles/Client.dir/main.cpp.i

Client/CMakeFiles/Client.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/main.cpp.s"
	cd /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/Client && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lda49/Projects/AdvancedProgrammingTask2/Client/main.cpp -o CMakeFiles/Client.dir/main.cpp.s

Client/CMakeFiles/Client.dir/Server.cpp.o: Client/CMakeFiles/Client.dir/flags.make
Client/CMakeFiles/Client.dir/Server.cpp.o: ../Client/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Client/CMakeFiles/Client.dir/Server.cpp.o"
	cd /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/Client && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Server.cpp.o -c /Users/lda49/Projects/AdvancedProgrammingTask2/Client/Server.cpp

Client/CMakeFiles/Client.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Server.cpp.i"
	cd /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/Client && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lda49/Projects/AdvancedProgrammingTask2/Client/Server.cpp > CMakeFiles/Client.dir/Server.cpp.i

Client/CMakeFiles/Client.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Server.cpp.s"
	cd /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/Client && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lda49/Projects/AdvancedProgrammingTask2/Client/Server.cpp -o CMakeFiles/Client.dir/Server.cpp.s

Client/CMakeFiles/Client.dir/Comms.cpp.o: Client/CMakeFiles/Client.dir/flags.make
Client/CMakeFiles/Client.dir/Comms.cpp.o: ../Client/Comms.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Client/CMakeFiles/Client.dir/Comms.cpp.o"
	cd /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/Client && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Comms.cpp.o -c /Users/lda49/Projects/AdvancedProgrammingTask2/Client/Comms.cpp

Client/CMakeFiles/Client.dir/Comms.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Comms.cpp.i"
	cd /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/Client && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lda49/Projects/AdvancedProgrammingTask2/Client/Comms.cpp > CMakeFiles/Client.dir/Comms.cpp.i

Client/CMakeFiles/Client.dir/Comms.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Comms.cpp.s"
	cd /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/Client && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lda49/Projects/AdvancedProgrammingTask2/Client/Comms.cpp -o CMakeFiles/Client.dir/Comms.cpp.s

# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/Client.cpp.o" \
"CMakeFiles/Client.dir/main.cpp.o" \
"CMakeFiles/Client.dir/Server.cpp.o" \
"CMakeFiles/Client.dir/Comms.cpp.o"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

Client/Client: Client/CMakeFiles/Client.dir/Client.cpp.o
Client/Client: Client/CMakeFiles/Client.dir/main.cpp.o
Client/Client: Client/CMakeFiles/Client.dir/Server.cpp.o
Client/Client: Client/CMakeFiles/Client.dir/Comms.cpp.o
Client/Client: Client/CMakeFiles/Client.dir/build.make
Client/Client: Client/CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Client"
	cd /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/Client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Client/CMakeFiles/Client.dir/build: Client/Client
.PHONY : Client/CMakeFiles/Client.dir/build

Client/CMakeFiles/Client.dir/clean:
	cd /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/Client && $(CMAKE_COMMAND) -P CMakeFiles/Client.dir/cmake_clean.cmake
.PHONY : Client/CMakeFiles/Client.dir/clean

Client/CMakeFiles/Client.dir/depend:
	cd /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lda49/Projects/AdvancedProgrammingTask2 /Users/lda49/Projects/AdvancedProgrammingTask2/Client /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/Client /Users/lda49/Projects/AdvancedProgrammingTask2/cmake-build-debug/Client/CMakeFiles/Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Client/CMakeFiles/Client.dir/depend

