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
include tools/CMakeFiles/ConicProj.dir/depend.make

# Include the progress variables for this target.
include tools/CMakeFiles/ConicProj.dir/progress.make

# Include the compile flags for this target's objects.
include tools/CMakeFiles/ConicProj.dir/flags.make

tools/CMakeFiles/ConicProj.dir/ConicProj.cpp.o: tools/CMakeFiles/ConicProj.dir/flags.make
tools/CMakeFiles/ConicProj.dir/ConicProj.cpp.o: ../tools/ConicProj.cpp
tools/CMakeFiles/ConicProj.dir/ConicProj.cpp.o: man/ConicProj.usage
	$(CMAKE_COMMAND) -E cmake_progress_report /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object tools/CMakeFiles/ConicProj.dir/ConicProj.cpp.o"
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ConicProj.dir/ConicProj.cpp.o -c /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/tools/ConicProj.cpp

tools/CMakeFiles/ConicProj.dir/ConicProj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ConicProj.dir/ConicProj.cpp.i"
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/tools/ConicProj.cpp > CMakeFiles/ConicProj.dir/ConicProj.cpp.i

tools/CMakeFiles/ConicProj.dir/ConicProj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ConicProj.dir/ConicProj.cpp.s"
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/tools/ConicProj.cpp -o CMakeFiles/ConicProj.dir/ConicProj.cpp.s

tools/CMakeFiles/ConicProj.dir/ConicProj.cpp.o.requires:
.PHONY : tools/CMakeFiles/ConicProj.dir/ConicProj.cpp.o.requires

tools/CMakeFiles/ConicProj.dir/ConicProj.cpp.o.provides: tools/CMakeFiles/ConicProj.dir/ConicProj.cpp.o.requires
	$(MAKE) -f tools/CMakeFiles/ConicProj.dir/build.make tools/CMakeFiles/ConicProj.dir/ConicProj.cpp.o.provides.build
.PHONY : tools/CMakeFiles/ConicProj.dir/ConicProj.cpp.o.provides

tools/CMakeFiles/ConicProj.dir/ConicProj.cpp.o.provides.build: tools/CMakeFiles/ConicProj.dir/ConicProj.cpp.o

# Object files for target ConicProj
ConicProj_OBJECTS = \
"CMakeFiles/ConicProj.dir/ConicProj.cpp.o"

# External object files for target ConicProj
ConicProj_EXTERNAL_OBJECTS =

tools/ConicProj: tools/CMakeFiles/ConicProj.dir/ConicProj.cpp.o
tools/ConicProj: tools/CMakeFiles/ConicProj.dir/build.make
tools/ConicProj: src/libGeographic.so.17.1.1
tools/ConicProj: tools/CMakeFiles/ConicProj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ConicProj"
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ConicProj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/CMakeFiles/ConicProj.dir/build: tools/ConicProj
.PHONY : tools/CMakeFiles/ConicProj.dir/build

tools/CMakeFiles/ConicProj.dir/requires: tools/CMakeFiles/ConicProj.dir/ConicProj.cpp.o.requires
.PHONY : tools/CMakeFiles/ConicProj.dir/requires

tools/CMakeFiles/ConicProj.dir/clean:
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools && $(CMAKE_COMMAND) -P CMakeFiles/ConicProj.dir/cmake_clean.cmake
.PHONY : tools/CMakeFiles/ConicProj.dir/clean

tools/CMakeFiles/ConicProj.dir/depend:
	cd /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48 /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/tools /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/CMakeFiles/ConicProj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/CMakeFiles/ConicProj.dir/depend

