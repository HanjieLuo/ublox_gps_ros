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
include examples/CMakeFiles/example-MagneticCircle.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/example-MagneticCircle.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/example-MagneticCircle.dir/flags.make

examples/CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.o: examples/CMakeFiles/example-MagneticCircle.dir/flags.make
examples/CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.o: ../examples/example-MagneticCircle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object examples/CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.o"
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/examples && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.o -c /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/examples/example-MagneticCircle.cpp

examples/CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.i"
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/examples/example-MagneticCircle.cpp > CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.i

examples/CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.s"
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/examples/example-MagneticCircle.cpp -o CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.s

examples/CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.o.requires:
.PHONY : examples/CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.o.requires

examples/CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.o.provides: examples/CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.o.requires
	$(MAKE) -f examples/CMakeFiles/example-MagneticCircle.dir/build.make examples/CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.o.provides.build
.PHONY : examples/CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.o.provides

examples/CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.o.provides.build: examples/CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.o

# Object files for target example-MagneticCircle
example__MagneticCircle_OBJECTS = \
"CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.o"

# External object files for target example-MagneticCircle
example__MagneticCircle_EXTERNAL_OBJECTS =

examples/example-MagneticCircle: examples/CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.o
examples/example-MagneticCircle: examples/CMakeFiles/example-MagneticCircle.dir/build.make
examples/example-MagneticCircle: src/libGeographic.so.17.1.1
examples/example-MagneticCircle: examples/CMakeFiles/example-MagneticCircle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable example-MagneticCircle"
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example-MagneticCircle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/example-MagneticCircle.dir/build: examples/example-MagneticCircle
.PHONY : examples/CMakeFiles/example-MagneticCircle.dir/build

examples/CMakeFiles/example-MagneticCircle.dir/requires: examples/CMakeFiles/example-MagneticCircle.dir/example-MagneticCircle.cpp.o.requires
.PHONY : examples/CMakeFiles/example-MagneticCircle.dir/requires

examples/CMakeFiles/example-MagneticCircle.dir/clean:
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/example-MagneticCircle.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/example-MagneticCircle.dir/clean

examples/CMakeFiles/example-MagneticCircle.dir/depend:
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48 /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/examples /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/examples /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/examples/CMakeFiles/example-MagneticCircle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/example-MagneticCircle.dir/depend

