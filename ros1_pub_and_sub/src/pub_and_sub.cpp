#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
 
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}
 
int main(int argc,char **argv)
{
    ros::init(argc,argv,"pub_and_sub");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("helloworld",1,object_detectedCallback);
    ros::Publisher identify_pub = n.advertise<std_msgs::String>("helloworld",1000);/
    ros::Rate loop_rate(10);
    while(ros::ok())
    {
        std_msgs::String msg;

        std::stringstream ss;
        ss << "hello world ";
        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());
        identify_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
	return 0;	
}

