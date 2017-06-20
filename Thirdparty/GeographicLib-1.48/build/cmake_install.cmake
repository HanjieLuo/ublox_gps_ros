# Install script for directory: /home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/src/cmake_install.cmake")
  include("/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/include/GeographicLib/cmake_install.cmake")
  include("/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/tools/cmake_install.cmake")
  include("/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/man/cmake_install.cmake")
  include("/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/doc/cmake_install.cmake")
  include("/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/js/cmake_install.cmake")
  include("/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/matlab/cmake_install.cmake")
  include("/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/python/geographiclib/cmake_install.cmake")
  include("/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/examples/cmake_install.cmake")
  include("/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/cmake/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

file(WRITE "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/${CMAKE_INSTALL_MANIFEST}" "")
foreach(file ${CMAKE_INSTALL_MANIFEST_FILES})
  file(APPEND "/home/luohanjie/Documents/SLAM/Code/catkin_ws_SaveMap/src/ublox_gps_ros/Thirdparty/GeographicLib-1.48/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
endforeach()
