# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.12.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.12.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yumaowangluokejiyouxiangongsi/Desktop/Practice-algorithm/163/01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yumaowangluokejiyouxiangongsi/Desktop/Practice-algorithm/163/01

# Include any dependencies generated for this target.
include CMakeFiles/hello.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello.dir/flags.make

CMakeFiles/hello.dir/arrayTable.cpp.o: CMakeFiles/hello.dir/flags.make
CMakeFiles/hello.dir/arrayTable.cpp.o: arrayTable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yumaowangluokejiyouxiangongsi/Desktop/Practice-algorithm/163/01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hello.dir/arrayTable.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hello.dir/arrayTable.cpp.o -c /Users/yumaowangluokejiyouxiangongsi/Desktop/Practice-algorithm/163/01/arrayTable.cpp

CMakeFiles/hello.dir/arrayTable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello.dir/arrayTable.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yumaowangluokejiyouxiangongsi/Desktop/Practice-algorithm/163/01/arrayTable.cpp > CMakeFiles/hello.dir/arrayTable.cpp.i

CMakeFiles/hello.dir/arrayTable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello.dir/arrayTable.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yumaowangluokejiyouxiangongsi/Desktop/Practice-algorithm/163/01/arrayTable.cpp -o CMakeFiles/hello.dir/arrayTable.cpp.s

CMakeFiles/hello.dir/Revse.cpp.o: CMakeFiles/hello.dir/flags.make
CMakeFiles/hello.dir/Revse.cpp.o: Revse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yumaowangluokejiyouxiangongsi/Desktop/Practice-algorithm/163/01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hello.dir/Revse.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hello.dir/Revse.cpp.o -c /Users/yumaowangluokejiyouxiangongsi/Desktop/Practice-algorithm/163/01/Revse.cpp

CMakeFiles/hello.dir/Revse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello.dir/Revse.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yumaowangluokejiyouxiangongsi/Desktop/Practice-algorithm/163/01/Revse.cpp > CMakeFiles/hello.dir/Revse.cpp.i

CMakeFiles/hello.dir/Revse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello.dir/Revse.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yumaowangluokejiyouxiangongsi/Desktop/Practice-algorithm/163/01/Revse.cpp -o CMakeFiles/hello.dir/Revse.cpp.s

# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/arrayTable.cpp.o" \
"CMakeFiles/hello.dir/Revse.cpp.o"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

hello: CMakeFiles/hello.dir/arrayTable.cpp.o
hello: CMakeFiles/hello.dir/Revse.cpp.o
hello: CMakeFiles/hello.dir/build.make
hello: CMakeFiles/hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yumaowangluokejiyouxiangongsi/Desktop/Practice-algorithm/163/01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable hello"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello.dir/build: hello

.PHONY : CMakeFiles/hello.dir/build

CMakeFiles/hello.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello.dir/clean

CMakeFiles/hello.dir/depend:
	cd /Users/yumaowangluokejiyouxiangongsi/Desktop/Practice-algorithm/163/01 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yumaowangluokejiyouxiangongsi/Desktop/Practice-algorithm/163/01 /Users/yumaowangluokejiyouxiangongsi/Desktop/Practice-algorithm/163/01 /Users/yumaowangluokejiyouxiangongsi/Desktop/Practice-algorithm/163/01 /Users/yumaowangluokejiyouxiangongsi/Desktop/Practice-algorithm/163/01 /Users/yumaowangluokejiyouxiangongsi/Desktop/Practice-algorithm/163/01/CMakeFiles/hello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello.dir/depend

