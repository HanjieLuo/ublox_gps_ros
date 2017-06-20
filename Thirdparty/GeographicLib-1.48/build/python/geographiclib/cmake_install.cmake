# Install script for directory: /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/python/geographiclib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python/site-packages/geographiclib" TYPE FILE FILES
    "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/python/geographiclib/geodesicline.py"
    "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/python/geographiclib/polygonarea.py"
    "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/python/geographiclib/constants.py"
    "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/python/geographiclib/accumulator.py"
    "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/python/geographiclib/geodesiccapability.py"
    "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/python/geographiclib/geomath.py"
    "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/python/geographiclib/geodesic.py"
    "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/python/geographiclib/__init__.py"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python/site-packages/geographiclib/test" TYPE FILE FILES
    "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/python/geographiclib/test/test_geodesic.py"
    "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/python/geographiclib/test/__init__.py"
    )
endif()

