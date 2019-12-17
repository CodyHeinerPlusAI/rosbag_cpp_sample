cmake_minimum_required(VERSION 2.8.3)
project(write_rosbag_sample)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3")

# Location  of include files for this package
set(INCLUDE_DIRNAME "include")

# Find catkin macros and libraries
# If COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
# is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  rosbag
  roscpp
  topic_tools
)

find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(PCL 1.2 REQUIRED)
list(REMOVE_ITEM PCL_LIBRARIES "vtkproj4")  # fix pcl build error
# find_package(Threads REQUIRED)

###################################
## catkin specific configuration ##
###################################
# The catkin_package macro generates cmake config files for your package
# Declare things to be passed to dependent projects
# INCLUDE_DIRS: uncomment this if you package contains header files
# LIBRARIES: libraries you create in this project that dependent projects also need
# CATKIN_DEPENDS: catkin_packages dependent projects also need
# DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS ${INCLUDE_DIRNAME}
  CATKIN_DEPENDS rosbag roscpp topic_tools
#  DEPENDS system_lib
)

###########
## Build ##
###########

# Specify additional locations of header files
# Your package locations should be listed before other locations
include_directories(${INCLUDE_DIRNAME} ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIR} ${PCL_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIR} ${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

set(SRCS "src/rosbag_write_sample.cpp")
add_executable(rosbag_write_sample ${SRCS})

target_link_libraries(rosbag_write_sample ${catkin_LIBRARIES} ${Boost_LIBRARIES} ${PCL_LIBRARIES})

# Don't build until necessary msgs are finished
add_dependencies(rosbag_write_sample ${catkin_EXPORTED_TARGETS})

