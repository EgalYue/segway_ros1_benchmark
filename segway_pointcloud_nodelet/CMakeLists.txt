cmake_minimum_required(VERSION 2.8.3)
project(segway_pointcloud_nodelet)

find_package(catkin REQUIRED COMPONENTS
        nodelet
        roscpp
        std_msgs
        ecl_threads
        pcl_ros
        pcl_conversions)

## Setup include directories
include_directories(${catkin_INCLUDE_DIRS})

catkin_package(
        LIBRARIES pointcloud_nodelet
        CATKIN_DEPENDS nodelet roscpp std_msgs pcl_ros pcl_conversions
)

## Create the nodelet tutorial library
add_library(pointcloud_nodelet src/pub_pc_with_nodelet.cpp src/sub_pc_with_nodelet.cpp src/sub2_pc_with_nodelet.cpp src/sub3_pc_with_nodelet.cpp) #

target_link_libraries(pointcloud_nodelet ${catkin_LIBRARIES})
if(catkin_EXPORTED_LIBRARIES)
    add_dependencies(pointcloud_nodelet ${catkin_EXPORTED_LIBRARIES})
endif()

## Mark the nodelet library for installations
install(TARGETS pointcloud_nodelet
        ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

## Mark other files for installation (e.g. launch and bag files, etc.)
install(FILES pub_nodelet.xml sub_nodelet.xml sub2_nodelet.xml
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})