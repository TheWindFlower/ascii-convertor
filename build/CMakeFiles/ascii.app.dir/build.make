# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/rflower/Documents/dev/DEV/c/ascii

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rflower/Documents/dev/DEV/c/ascii/build

# Include any dependencies generated for this target.
include CMakeFiles/ascii.app.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ascii.app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ascii.app.dir/flags.make

CMakeFiles/ascii.app.dir/mina.cpp.o: CMakeFiles/ascii.app.dir/flags.make
CMakeFiles/ascii.app.dir/mina.cpp.o: ../mina.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rflower/Documents/dev/DEV/c/ascii/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ascii.app.dir/mina.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ascii.app.dir/mina.cpp.o -c /home/rflower/Documents/dev/DEV/c/ascii/mina.cpp

CMakeFiles/ascii.app.dir/mina.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ascii.app.dir/mina.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rflower/Documents/dev/DEV/c/ascii/mina.cpp > CMakeFiles/ascii.app.dir/mina.cpp.i

CMakeFiles/ascii.app.dir/mina.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ascii.app.dir/mina.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rflower/Documents/dev/DEV/c/ascii/mina.cpp -o CMakeFiles/ascii.app.dir/mina.cpp.s

# Object files for target ascii.app
ascii_app_OBJECTS = \
"CMakeFiles/ascii.app.dir/mina.cpp.o"

# External object files for target ascii.app
ascii_app_EXTERNAL_OBJECTS =

ascii.app: CMakeFiles/ascii.app.dir/mina.cpp.o
ascii.app: CMakeFiles/ascii.app.dir/build.make
ascii.app: /usr/local/lib/libopencv_gapi.so.4.6.0
ascii.app: /usr/local/lib/libopencv_highgui.so.4.6.0
ascii.app: /usr/local/lib/libopencv_ml.so.4.6.0
ascii.app: /usr/local/lib/libopencv_objdetect.so.4.6.0
ascii.app: /usr/local/lib/libopencv_photo.so.4.6.0
ascii.app: /usr/local/lib/libopencv_stitching.so.4.6.0
ascii.app: /usr/local/lib/libopencv_video.so.4.6.0
ascii.app: /usr/local/lib/libopencv_videoio.so.4.6.0
ascii.app: /usr/local/lib/libopencv_imgcodecs.so.4.6.0
ascii.app: /usr/local/lib/libopencv_dnn.so.4.6.0
ascii.app: /usr/local/lib/libopencv_calib3d.so.4.6.0
ascii.app: /usr/local/lib/libopencv_features2d.so.4.6.0
ascii.app: /usr/local/lib/libopencv_flann.so.4.6.0
ascii.app: /usr/local/lib/libopencv_imgproc.so.4.6.0
ascii.app: /usr/local/lib/libopencv_core.so.4.6.0
ascii.app: CMakeFiles/ascii.app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rflower/Documents/dev/DEV/c/ascii/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ascii.app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ascii.app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ascii.app.dir/build: ascii.app

.PHONY : CMakeFiles/ascii.app.dir/build

CMakeFiles/ascii.app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ascii.app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ascii.app.dir/clean

CMakeFiles/ascii.app.dir/depend:
	cd /home/rflower/Documents/dev/DEV/c/ascii/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rflower/Documents/dev/DEV/c/ascii /home/rflower/Documents/dev/DEV/c/ascii /home/rflower/Documents/dev/DEV/c/ascii/build /home/rflower/Documents/dev/DEV/c/ascii/build /home/rflower/Documents/dev/DEV/c/ascii/build/CMakeFiles/ascii.app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ascii.app.dir/depend

