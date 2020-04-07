#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

#include <iostream>

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
  try
  {
    // cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
    // cv::waitKey(30);

    //get header info
    std_msgs::Header h = msg->header;
    // std::cout<<h<<std::endl; //all at once
    // std::cout<<h.stamp<<std::endl; //specific parts of it
    // std::cout<<h.stamp.sec<<std::endl;
    // std::cout<<h.stamp.nsec<<std::endl;
    // std::cout<<h.seq<<std::endl;
    ROS_INFO("%s, frame _id:  %s", "get it", h.frame_id.c_str());
    // ROS_INFO("%s, frame _id:  %s, image size: %d kb", "get it", h.frame_id.c_str(), (int)(msg->data.size()/1024));
    // std::cout<< msg->step <<std::endl;
    // std::cout<< msg->height << std::endl;

    // ros::Time beginTime = ros::Time::now();
    // std::cout<< beginTime.sec << std::endl;
    // std::cout<< beginTime.nsec << std::endl;
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "image_listener");
  ros::NodeHandle nh;
//   cv::namedWindow("view");
//   cv::startWindowThread();
  // image_transport::ImageTransport it(nh);
  // image_transport::Subscriber sub = it.subscribe("image_topic", 1, imageCallback);

  ros::Subscriber sub = nh.subscribe ("image_topic", 1, imageCallback);
  ros::spin();
//   cv::destroyWindow("view");
}
