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
CMAKE_COMMAND = /snap/cmake/1005/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1005/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/usr/Desktop/FOP_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/usr/Desktop/FOP_Project/build

# Include any dependencies generated for this target.
include CMakeFiles/FOP_Project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/FOP_Project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FOP_Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FOP_Project.dir/flags.make

CMakeFiles/FOP_Project.dir/main.c.o: CMakeFiles/FOP_Project.dir/flags.make
CMakeFiles/FOP_Project.dir/main.c.o: ../main.c
CMakeFiles/FOP_Project.dir/main.c.o: CMakeFiles/FOP_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usr/Desktop/FOP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/FOP_Project.dir/main.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FOP_Project.dir/main.c.o -MF CMakeFiles/FOP_Project.dir/main.c.o.d -o CMakeFiles/FOP_Project.dir/main.c.o -c /home/usr/Desktop/FOP_Project/main.c

CMakeFiles/FOP_Project.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FOP_Project.dir/main.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/usr/Desktop/FOP_Project/main.c > CMakeFiles/FOP_Project.dir/main.c.i

CMakeFiles/FOP_Project.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FOP_Project.dir/main.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/usr/Desktop/FOP_Project/main.c -o CMakeFiles/FOP_Project.dir/main.c.s

CMakeFiles/FOP_Project.dir/NameAndInit.c.o: CMakeFiles/FOP_Project.dir/flags.make
CMakeFiles/FOP_Project.dir/NameAndInit.c.o: ../NameAndInit.c
CMakeFiles/FOP_Project.dir/NameAndInit.c.o: CMakeFiles/FOP_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usr/Desktop/FOP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/FOP_Project.dir/NameAndInit.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FOP_Project.dir/NameAndInit.c.o -MF CMakeFiles/FOP_Project.dir/NameAndInit.c.o.d -o CMakeFiles/FOP_Project.dir/NameAndInit.c.o -c /home/usr/Desktop/FOP_Project/NameAndInit.c

CMakeFiles/FOP_Project.dir/NameAndInit.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FOP_Project.dir/NameAndInit.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/usr/Desktop/FOP_Project/NameAndInit.c > CMakeFiles/FOP_Project.dir/NameAndInit.c.i

CMakeFiles/FOP_Project.dir/NameAndInit.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FOP_Project.dir/NameAndInit.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/usr/Desktop/FOP_Project/NameAndInit.c -o CMakeFiles/FOP_Project.dir/NameAndInit.c.s

CMakeFiles/FOP_Project.dir/MenuPage.c.o: CMakeFiles/FOP_Project.dir/flags.make
CMakeFiles/FOP_Project.dir/MenuPage.c.o: ../MenuPage.c
CMakeFiles/FOP_Project.dir/MenuPage.c.o: CMakeFiles/FOP_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usr/Desktop/FOP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/FOP_Project.dir/MenuPage.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FOP_Project.dir/MenuPage.c.o -MF CMakeFiles/FOP_Project.dir/MenuPage.c.o.d -o CMakeFiles/FOP_Project.dir/MenuPage.c.o -c /home/usr/Desktop/FOP_Project/MenuPage.c

CMakeFiles/FOP_Project.dir/MenuPage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FOP_Project.dir/MenuPage.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/usr/Desktop/FOP_Project/MenuPage.c > CMakeFiles/FOP_Project.dir/MenuPage.c.i

CMakeFiles/FOP_Project.dir/MenuPage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FOP_Project.dir/MenuPage.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/usr/Desktop/FOP_Project/MenuPage.c -o CMakeFiles/FOP_Project.dir/MenuPage.c.s

CMakeFiles/FOP_Project.dir/CreateNewGame.c.o: CMakeFiles/FOP_Project.dir/flags.make
CMakeFiles/FOP_Project.dir/CreateNewGame.c.o: ../CreateNewGame.c
CMakeFiles/FOP_Project.dir/CreateNewGame.c.o: CMakeFiles/FOP_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usr/Desktop/FOP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/FOP_Project.dir/CreateNewGame.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FOP_Project.dir/CreateNewGame.c.o -MF CMakeFiles/FOP_Project.dir/CreateNewGame.c.o.d -o CMakeFiles/FOP_Project.dir/CreateNewGame.c.o -c /home/usr/Desktop/FOP_Project/CreateNewGame.c

CMakeFiles/FOP_Project.dir/CreateNewGame.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FOP_Project.dir/CreateNewGame.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/usr/Desktop/FOP_Project/CreateNewGame.c > CMakeFiles/FOP_Project.dir/CreateNewGame.c.i

CMakeFiles/FOP_Project.dir/CreateNewGame.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FOP_Project.dir/CreateNewGame.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/usr/Desktop/FOP_Project/CreateNewGame.c -o CMakeFiles/FOP_Project.dir/CreateNewGame.c.s

CMakeFiles/FOP_Project.dir/GameGraphic.c.o: CMakeFiles/FOP_Project.dir/flags.make
CMakeFiles/FOP_Project.dir/GameGraphic.c.o: ../GameGraphic.c
CMakeFiles/FOP_Project.dir/GameGraphic.c.o: CMakeFiles/FOP_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usr/Desktop/FOP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/FOP_Project.dir/GameGraphic.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FOP_Project.dir/GameGraphic.c.o -MF CMakeFiles/FOP_Project.dir/GameGraphic.c.o.d -o CMakeFiles/FOP_Project.dir/GameGraphic.c.o -c /home/usr/Desktop/FOP_Project/GameGraphic.c

CMakeFiles/FOP_Project.dir/GameGraphic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FOP_Project.dir/GameGraphic.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/usr/Desktop/FOP_Project/GameGraphic.c > CMakeFiles/FOP_Project.dir/GameGraphic.c.i

CMakeFiles/FOP_Project.dir/GameGraphic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FOP_Project.dir/GameGraphic.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/usr/Desktop/FOP_Project/GameGraphic.c -o CMakeFiles/FOP_Project.dir/GameGraphic.c.s

CMakeFiles/FOP_Project.dir/Logic.c.o: CMakeFiles/FOP_Project.dir/flags.make
CMakeFiles/FOP_Project.dir/Logic.c.o: ../Logic.c
CMakeFiles/FOP_Project.dir/Logic.c.o: CMakeFiles/FOP_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usr/Desktop/FOP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/FOP_Project.dir/Logic.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FOP_Project.dir/Logic.c.o -MF CMakeFiles/FOP_Project.dir/Logic.c.o.d -o CMakeFiles/FOP_Project.dir/Logic.c.o -c /home/usr/Desktop/FOP_Project/Logic.c

CMakeFiles/FOP_Project.dir/Logic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FOP_Project.dir/Logic.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/usr/Desktop/FOP_Project/Logic.c > CMakeFiles/FOP_Project.dir/Logic.c.i

CMakeFiles/FOP_Project.dir/Logic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FOP_Project.dir/Logic.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/usr/Desktop/FOP_Project/Logic.c -o CMakeFiles/FOP_Project.dir/Logic.c.s

CMakeFiles/FOP_Project.dir/SoldierLogic.c.o: CMakeFiles/FOP_Project.dir/flags.make
CMakeFiles/FOP_Project.dir/SoldierLogic.c.o: ../SoldierLogic.c
CMakeFiles/FOP_Project.dir/SoldierLogic.c.o: CMakeFiles/FOP_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usr/Desktop/FOP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/FOP_Project.dir/SoldierLogic.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FOP_Project.dir/SoldierLogic.c.o -MF CMakeFiles/FOP_Project.dir/SoldierLogic.c.o.d -o CMakeFiles/FOP_Project.dir/SoldierLogic.c.o -c /home/usr/Desktop/FOP_Project/SoldierLogic.c

CMakeFiles/FOP_Project.dir/SoldierLogic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FOP_Project.dir/SoldierLogic.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/usr/Desktop/FOP_Project/SoldierLogic.c > CMakeFiles/FOP_Project.dir/SoldierLogic.c.i

CMakeFiles/FOP_Project.dir/SoldierLogic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FOP_Project.dir/SoldierLogic.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/usr/Desktop/FOP_Project/SoldierLogic.c -o CMakeFiles/FOP_Project.dir/SoldierLogic.c.s

CMakeFiles/FOP_Project.dir/PotionLogic.c.o: CMakeFiles/FOP_Project.dir/flags.make
CMakeFiles/FOP_Project.dir/PotionLogic.c.o: ../PotionLogic.c
CMakeFiles/FOP_Project.dir/PotionLogic.c.o: CMakeFiles/FOP_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usr/Desktop/FOP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/FOP_Project.dir/PotionLogic.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FOP_Project.dir/PotionLogic.c.o -MF CMakeFiles/FOP_Project.dir/PotionLogic.c.o.d -o CMakeFiles/FOP_Project.dir/PotionLogic.c.o -c /home/usr/Desktop/FOP_Project/PotionLogic.c

CMakeFiles/FOP_Project.dir/PotionLogic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FOP_Project.dir/PotionLogic.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/usr/Desktop/FOP_Project/PotionLogic.c > CMakeFiles/FOP_Project.dir/PotionLogic.c.i

CMakeFiles/FOP_Project.dir/PotionLogic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FOP_Project.dir/PotionLogic.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/usr/Desktop/FOP_Project/PotionLogic.c -o CMakeFiles/FOP_Project.dir/PotionLogic.c.s

CMakeFiles/FOP_Project.dir/WinOrLose.c.o: CMakeFiles/FOP_Project.dir/flags.make
CMakeFiles/FOP_Project.dir/WinOrLose.c.o: ../WinOrLose.c
CMakeFiles/FOP_Project.dir/WinOrLose.c.o: CMakeFiles/FOP_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usr/Desktop/FOP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/FOP_Project.dir/WinOrLose.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FOP_Project.dir/WinOrLose.c.o -MF CMakeFiles/FOP_Project.dir/WinOrLose.c.o.d -o CMakeFiles/FOP_Project.dir/WinOrLose.c.o -c /home/usr/Desktop/FOP_Project/WinOrLose.c

CMakeFiles/FOP_Project.dir/WinOrLose.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FOP_Project.dir/WinOrLose.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/usr/Desktop/FOP_Project/WinOrLose.c > CMakeFiles/FOP_Project.dir/WinOrLose.c.i

CMakeFiles/FOP_Project.dir/WinOrLose.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FOP_Project.dir/WinOrLose.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/usr/Desktop/FOP_Project/WinOrLose.c -o CMakeFiles/FOP_Project.dir/WinOrLose.c.s

# Object files for target FOP_Project
FOP_Project_OBJECTS = \
"CMakeFiles/FOP_Project.dir/main.c.o" \
"CMakeFiles/FOP_Project.dir/NameAndInit.c.o" \
"CMakeFiles/FOP_Project.dir/MenuPage.c.o" \
"CMakeFiles/FOP_Project.dir/CreateNewGame.c.o" \
"CMakeFiles/FOP_Project.dir/GameGraphic.c.o" \
"CMakeFiles/FOP_Project.dir/Logic.c.o" \
"CMakeFiles/FOP_Project.dir/SoldierLogic.c.o" \
"CMakeFiles/FOP_Project.dir/PotionLogic.c.o" \
"CMakeFiles/FOP_Project.dir/WinOrLose.c.o"

# External object files for target FOP_Project
FOP_Project_EXTERNAL_OBJECTS =

FOP_Project: CMakeFiles/FOP_Project.dir/main.c.o
FOP_Project: CMakeFiles/FOP_Project.dir/NameAndInit.c.o
FOP_Project: CMakeFiles/FOP_Project.dir/MenuPage.c.o
FOP_Project: CMakeFiles/FOP_Project.dir/CreateNewGame.c.o
FOP_Project: CMakeFiles/FOP_Project.dir/GameGraphic.c.o
FOP_Project: CMakeFiles/FOP_Project.dir/Logic.c.o
FOP_Project: CMakeFiles/FOP_Project.dir/SoldierLogic.c.o
FOP_Project: CMakeFiles/FOP_Project.dir/PotionLogic.c.o
FOP_Project: CMakeFiles/FOP_Project.dir/WinOrLose.c.o
FOP_Project: CMakeFiles/FOP_Project.dir/build.make
FOP_Project: CMakeFiles/FOP_Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/usr/Desktop/FOP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable FOP_Project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FOP_Project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FOP_Project.dir/build: FOP_Project
.PHONY : CMakeFiles/FOP_Project.dir/build

CMakeFiles/FOP_Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FOP_Project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FOP_Project.dir/clean

CMakeFiles/FOP_Project.dir/depend:
	cd /home/usr/Desktop/FOP_Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/usr/Desktop/FOP_Project /home/usr/Desktop/FOP_Project /home/usr/Desktop/FOP_Project/build /home/usr/Desktop/FOP_Project/build /home/usr/Desktop/FOP_Project/build/CMakeFiles/FOP_Project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FOP_Project.dir/depend

