
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

#include <algorithm>
#include <random>
#include <functional>
#include <climits>
#include <sensor_msgs/Image.h>

using random_bytes_engine = std::independent_bits_engine<std::default_random_engine, CHAR_BIT, unsigned char>;

int main(int argc, char** argv)
{
  ros::init(argc, argv, "image_publisher");
  ros::NodeHandle nh;

  // image_transport::ImageTransport it(nh);
  // image_transport::Publisher pub = it.advertise("image_topic", 1);
  // cv::Mat image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
  // sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();


  ros::Publisher pub = nh.advertise<sensor_msgs::Image> ("image_topic", 1);
  sensor_msgs::Image msg;

  std::string size_str = "100kb"; //default
  size_str = argv[1];

  std::string unit = size_str.substr(size_str.length()- 2, 2);
  std::string num_str = size_str.substr(0, size_str.length() -2);
  int index = atoi(num_str.c_str());
  if("mb" == unit){
        index = 1024 * index;
  }
    
  //std::cout<< index << std::endl;

  random_bytes_engine rbe;
  std::vector<unsigned char> data(1); // 1024 * index
  std::generate(begin(data), end(data), std::ref(rbe));
  //msg->data = data;
  msg.data = data;
 
  ros::Rate loop_rate(10);
  int id_index = 0;
  while (nh.ok()) {
    // msg->header.frame_id = std::to_string(id_index++);
    // ROS_INFO("%s, frame_id: %s", "send it", msg->header.frame_id.c_str());

    msg.header.frame_id = std::to_string(id_index++);
    msg.header.stamp = ros::Time::now();
    std::cout<<"Send time: " <<msg.header.stamp<<" frame_id: " << msg.header.frame_id<<std::endl;
    //ROS_INFO("%s, frame_id: %s", "send it", msg.header.frame_id.c_str());

    pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }
}

