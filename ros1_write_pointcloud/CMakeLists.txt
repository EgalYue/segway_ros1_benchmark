cmake_minimum_required(VERSION 2.8.3)
project(ros1_write_pointcloud)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        std_msgs
        pcl_ros
)



catkin_package(
        #LIBRARIES pointcloud_nodelet
        CATKIN_DEPENDS roscpp std_msgs pcl_ros
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(writer_pointcloud src/writer.cpp)
target_link_libraries(writer_pointcloud ${catkin_LIBRARIES})
