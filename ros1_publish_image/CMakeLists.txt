cmake_minimum_required(VERSION 2.8.3)
project(ros1_publish_image)

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
add_executable(publisher_image src/publisher.cpp)
target_link_libraries(publisher_image ${catkin_LIBRARIES})

add_executable(subscriber src/subscriber.cpp)
target_link_libraries(subscriber ${catkin_LIBRARIES})

