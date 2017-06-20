# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_SOURCE_DIR = /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/example-Geodesic-small.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/example-Geodesic-small.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/example-Geodesic-small.dir/flags.make

examples/CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.o: examples/CMakeFiles/example-Geodesic-small.dir/flags.make
examples/CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.o: ../examples/example-Geodesic-small.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object examples/CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.o"
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/examples && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.o -c /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/examples/example-Geodesic-small.cpp

examples/CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.i"
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/examples/example-Geodesic-small.cpp > CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.i

examples/CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.s"
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/examples/example-Geodesic-small.cpp -o CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.s

examples/CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.o.requires:
.PHONY : examples/CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.o.requires

examples/CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.o.provides: examples/CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.o.requires
	$(MAKE) -f examples/CMakeFiles/example-Geodesic-small.dir/build.make examples/CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.o.provides.build
.PHONY : examples/CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.o.provides

examples/CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.o.provides.build: examples/CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.o

# Object files for target example-Geodesic-small
example__Geodesic__small_OBJECTS = \
"CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.o"

# External object files for target example-Geodesic-small
example__Geodesic__small_EXTERNAL_OBJECTS =

examples/example-Geodesic-small: examples/CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.o
examples/example-Geodesic-small: examples/CMakeFiles/example-Geodesic-small.dir/build.make
examples/example-Geodesic-small: src/libGeographic.so.17.1.1
examples/example-Geodesic-small: examples/CMakeFiles/example-Geodesic-small.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable example-Geodesic-small"
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example-Geodesic-small.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/example-Geodesic-small.dir/build: examples/example-Geodesic-small
.PHONY : examples/CMakeFiles/example-Geodesic-small.dir/build

examples/CMakeFiles/example-Geodesic-small.dir/requires: examples/CMakeFiles/example-Geodesic-small.dir/example-Geodesic-small.cpp.o.requires
.PHONY : examples/CMakeFiles/example-Geodesic-small.dir/requires

examples/CMakeFiles/example-Geodesic-small.dir/clean:
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/example-Geodesic-small.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/example-Geodesic-small.dir/clean

examples/CMakeFiles/example-Geodesic-small.dir/depend:
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48 /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/examples /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/examples /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/examples/CMakeFiles/example-Geodesic-small.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/example-Geodesic-small.dir/depend
