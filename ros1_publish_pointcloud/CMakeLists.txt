cmake_minimum_required(VERSION 2.8.3)
project(ros1_publish_pointcloud)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        std_msgs
        pcl_ros
        pcl_conversions
)



catkin_package(
        #LIBRARIES pointcloud_nodelet
        CATKIN_DEPENDS roscpp std_msgs pcl_ros pcl_conversions
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(publisher_pointcloud src/publisher.cpp)
target_link_libraries(publisher_pointcloud ${catkin_LIBRARIES})

add_executable(subscriber_pointcloud src/subscriber.cpp)
target_link_libraries(subscriber_pointcloud ${catkin_LIBRARIES})
