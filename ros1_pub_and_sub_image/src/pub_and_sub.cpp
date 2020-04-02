#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
 
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

  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }
}
 
int main(int argc,char **argv)
{
    ros::init(argc,argv,"pub_and_sub_image");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("channel2/image",1,imageCallback);



    image_transport::ImageTransport it(nh);
    image_transport::Publisher pub = it.advertise("channel1/image", 1);

    cv::Mat image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
    sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();

    ros::Rate loop_rate(10);
    while(ros::ok())
    {
    msg->header.frame_id = std::to_string(id_index++);
    pub.publish(msg);
    ROS_INFO("%s, frame_id: %s", "send it", msg->header.frame_id.c_str());

    loop_rate.sleep();
    }
	return 0;	
}

