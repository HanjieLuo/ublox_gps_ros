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
foreach(_expectedTarget GeographicLib CartConvert ConicProj GeodesicProj GeoConvert GeodSolve GeoidEval Gravity MagneticField Planimeter RhumbSolve TransverseMercatorProj)
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


# Create imported target GeographicLib
add_library(GeographicLib SHARED IMPORTED)

set_target_properties(GeographicLib PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/include;/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/include"
)

# Create imported target CartConvert
add_executable(CartConvert IMPORTED)

# Create imported target ConicProj
add_executable(ConicProj IMPORTED)

# Create imported target GeodesicProj
add_executable(GeodesicProj IMPORTED)

# Create imported target GeoConvert
add_executable(GeoConvert IMPORTED)

# Create imported target GeodSolve
add_executable(GeodSolve IMPORTED)

# Create imported target GeoidEval
add_executable(GeoidEval IMPORTED)

# Create imported target Gravity
add_executable(Gravity IMPORTED)

# Create imported target MagneticField
add_executable(MagneticField IMPORTED)

# Create imported target Planimeter
add_executable(Planimeter IMPORTED)

# Create imported target RhumbSolve
add_executable(RhumbSolve IMPORTED)

# Create imported target TransverseMercatorProj
add_executable(TransverseMercatorProj IMPORTED)

# Import target "GeographicLib" for configuration "Release"
set_property(TARGET GeographicLib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/src/libGeographic.so.17.1.1"
  IMPORTED_SONAME_RELEASE "libGeographic.so.17"
  )

# Import target "CartConvert" for configuration "Release"
set_property(TARGET CartConvert APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(CartConvert PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/CartConvert"
  )

# Import target "ConicProj" for configuration "Release"
set_property(TARGET ConicProj APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ConicProj PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/ConicProj"
  )

# Import target "GeodesicProj" for configuration "Release"
set_property(TARGET GeodesicProj APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeodesicProj PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/GeodesicProj"
  )

# Import target "GeoConvert" for configuration "Release"
set_property(TARGET GeoConvert APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeoConvert PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/GeoConvert"
  )

# Import target "GeodSolve" for configuration "Release"
set_property(TARGET GeodSolve APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeodSolve PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/GeodSolve"
  )

# Import target "GeoidEval" for configuration "Release"
set_property(TARGET GeoidEval APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeoidEval PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/GeoidEval"
  )

# Import target "Gravity" for configuration "Release"
set_property(TARGET Gravity APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Gravity PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/Gravity"
  )

# Import target "MagneticField" for configuration "Release"
set_property(TARGET MagneticField APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(MagneticField PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/MagneticField"
  )

# Import target "Planimeter" for configuration "Release"
set_property(TARGET Planimeter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Planimeter PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/Planimeter"
  )

# Import target "RhumbSolve" for configuration "Release"
set_property(TARGET RhumbSolve APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(RhumbSolve PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/RhumbSolve"
  )

# Import target "TransverseMercatorProj" for configuration "Release"
set_property(TARGET TransverseMercatorProj APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(TransverseMercatorProj PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/TransverseMercatorProj"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)