cmake_minimum_required(VERSION 2.8.3)
project(ros1_pub_and_sub_image)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
)


find_package(OpenCV)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES ros1_publish_image
#  CATKIN_DEPENDS cv_bridge image_transport
#  DEPENDS system_lib
)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


include_directories(include ${OpenCV_INCLUDE_DIRS})
#build my_publisher and my_subscriber
add_executable(pub_and_sub src/pub_and_sub.cpp)
target_link_libraries(pub_and_sub ${catkin_LIBRARIES})

add_executable(sub_and_pub src/sub_and_pub.cpp)
target_link_libraries(sub_and_pub ${catkin_LIBRARIES})

