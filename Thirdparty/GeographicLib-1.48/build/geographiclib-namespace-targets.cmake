# Generated by CMake 3.0.2

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget GeographicLib::GeographicLib GeographicLib::CartConvert GeographicLib::ConicProj GeographicLib::GeodesicProj GeographicLib::GeoConvert GeographicLib::GeodSolve GeographicLib::GeoidEval GeographicLib::Gravity GeographicLib::MagneticField GeographicLib::Planimeter GeographicLib::RhumbSolve GeographicLib::TransverseMercatorProj)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target GeographicLib::GeographicLib
add_library(GeographicLib::GeographicLib SHARED IMPORTED)

set_target_properties(GeographicLib::GeographicLib PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/include;/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/include"
)

# Create imported target GeographicLib::CartConvert
add_executable(GeographicLib::CartConvert IMPORTED)

# Create imported target GeographicLib::ConicProj
add_executable(GeographicLib::ConicProj IMPORTED)

# Create imported target GeographicLib::GeodesicProj
add_executable(GeographicLib::GeodesicProj IMPORTED)

# Create imported target GeographicLib::GeoConvert
add_executable(GeographicLib::GeoConvert IMPORTED)

# Create imported target GeographicLib::GeodSolve
add_executable(GeographicLib::GeodSolve IMPORTED)

# Create imported target GeographicLib::GeoidEval
add_executable(GeographicLib::GeoidEval IMPORTED)

# Create imported target GeographicLib::Gravity
add_executable(GeographicLib::Gravity IMPORTED)

# Create imported target GeographicLib::MagneticField
add_executable(GeographicLib::MagneticField IMPORTED)

# Create imported target GeographicLib::Planimeter
add_executable(GeographicLib::Planimeter IMPORTED)

# Create imported target GeographicLib::RhumbSolve
add_executable(GeographicLib::RhumbSolve IMPORTED)

# Create imported target GeographicLib::TransverseMercatorProj
add_executable(GeographicLib::TransverseMercatorProj IMPORTED)

# Import target "GeographicLib::GeographicLib" for configuration "Release"
set_property(TARGET GeographicLib::GeographicLib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::GeographicLib PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/src/libGeographic.so.17.1.1"
  IMPORTED_SONAME_RELEASE "libGeographic.so.17"
  )

# Import target "GeographicLib::CartConvert" for configuration "Release"
set_property(TARGET GeographicLib::CartConvert APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::CartConvert PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/CartConvert"
  )

# Import target "GeographicLib::ConicProj" for configuration "Release"
set_property(TARGET GeographicLib::ConicProj APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::ConicProj PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/ConicProj"
  )

# Import target "GeographicLib::GeodesicProj" for configuration "Release"
set_property(TARGET GeographicLib::GeodesicProj APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::GeodesicProj PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/GeodesicProj"
  )

# Import target "GeographicLib::GeoConvert" for configuration "Release"
set_property(TARGET GeographicLib::GeoConvert APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::GeoConvert PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/GeoConvert"
  )

# Import target "GeographicLib::GeodSolve" for configuration "Release"
set_property(TARGET GeographicLib::GeodSolve APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::GeodSolve PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/GeodSolve"
  )

# Import target "GeographicLib::GeoidEval" for configuration "Release"
set_property(TARGET GeographicLib::GeoidEval APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::GeoidEval PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/GeoidEval"
  )

# Import target "GeographicLib::Gravity" for configuration "Release"
set_property(TARGET GeographicLib::Gravity APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::Gravity PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/Gravity"
  )

# Import target "GeographicLib::MagneticField" for configuration "Release"
set_property(TARGET GeographicLib::MagneticField APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::MagneticField PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/MagneticField"
  )

# Import target "GeographicLib::Planimeter" for configuration "Release"
set_property(TARGET GeographicLib::Planimeter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::Planimeter PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/Planimeter"
  )

# Import target "GeographicLib::RhumbSolve" for configuration "Release"
set_property(TARGET GeographicLib::RhumbSolve APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::RhumbSolve PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/RhumbSolve"
  )

# Import target "GeographicLib::TransverseMercatorProj" for configuration "Release"
set_property(TARGET GeographicLib::TransverseMercatorProj APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::TransverseMercatorProj PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/TransverseMercatorProj"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
