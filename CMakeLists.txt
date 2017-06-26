cmake_minimum_required(VERSION 2.8.3)
project(ublox_gps_ros)

# Check C++11 or C++0x support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
 add_definitions(-DCOMPILEDWITHC11)
 message(STATUS "Using flag -std=c++11.")
elseif(COMPILER_SUPPORTS_CXX0X)
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
 add_definitions(-DCOMPILEDWITHC0X)
 message(STATUS "Using flag -std=c++0x.")
else()
 message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


# find_package(PkgConfig)
# pkg_check_modules(OpenCV REQUIRED opencv=2.4.10)
find_package(OpenCV 2.4.10)
if(OpenCV_FOUND)
  message(${OpenCV_INCLUDE_DIRS})
  message(${OpenCV_LIBRARIES})
else(OpenCV_FOUND)
  set(OpenCV_DIR "/home/luohanjie/Documents/Software/opencv-2.4.10/build")
  find_package(OpenCV REQUIRED)
endif(OpenCV_FOUND)

find_package(CURL REQUIRED)

# find_package (GeographicLib REQUIRED)

find_package(catkin REQUIRED
  COMPONENTS
  cmake_modules
  roscpp
  std_msgs
  gps_msgs
  message_generation
  )

generate_messages(
  DEPENDENCIES
  std_msgs
  gps_msgs
)

catkin_package(
  # LIBRARIES
  CATKIN_DEPENDS message_runtime std_msgs gps_msgs
  )

# add_definitions (${GeographicLib_DEFINITIONS})

link_directories(${catkin_LIBRARY_DIRS})

set(LINK_LIBRARIES
  ${CURL_LIBRARY}
  ${OpenCV_LIBS}
  ${catkin_LIBRARIES}
  # ${GeographicLib_LIBRARIES}
  )



include_directories(
  ${catkin_INCLUDE_DIRS}
  "include"
  ${CURL_INCLUDE_DIR}
  ${OpenCV_INCLUDE_DIRS}
  # ${GeographicLib_INCLUDE_DIRS}
  )


add_executable(subscriber src/subscriber.cpp)
add_dependencies(subscriber ${catkin_EXPORTED_TARGETS})
target_link_libraries(subscriber ${LINK_LIBRARIES})

add_executable(data_analyse src/data_analyse.cpp)
target_link_libraries(data_analyse ${LINK_LIBRARIES})

add_library(gps SHARED src/gps.cpp)
add_dependencies(gps ${catkin_EXPORTED_TARGETS})
target_link_libraries(gps ${LINK_LIBRARIES})

add_executable(ublox_gps_ros_node src/ublox_gps_ros_node.cpp)
target_link_libraries(ublox_gps_ros_node gps ${LINK_LIBRARIES})





