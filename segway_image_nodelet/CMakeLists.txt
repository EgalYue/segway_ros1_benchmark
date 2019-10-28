cmake_minimum_required(VERSION 2.8.3)
project(segway_image_nodelet)

find_package(catkin REQUIRED COMPONENTS
             nodelet
             roscpp
             std_msgs
             ecl_threads
             cv_bridge)

## Setup include directories
include_directories(${catkin_INCLUDE_DIRS})

catkin_package(
        LIBRARIES image_nodelet
        CATKIN_DEPENDS nodelet roscpp std_msgs
)

## Create the nodelet tutorial library
add_library(image_nodelet src/pub_with_nodelet.cpp src/sub_with_nodelet.cpp src/sub2_with_nodelet.cpp src/sub3_with_nodelet.cpp)

target_link_libraries(image_nodelet ${catkin_LIBRARIES})
if(catkin_EXPORTED_LIBRARIES)
    add_dependencies(image_nodelet ${catkin_EXPORTED_LIBRARIES})
endif()

## Mark the nodelet library for installations
install(TARGETS image_nodelet
        ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

## Mark other files for installation (e.g. launch and bag files, etc.)
install(FILES pub_nodelet.xml sub_nodelet.xml sub2_nodelet.xml
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})