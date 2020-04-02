#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
ros::Publisher chatter_pub;
ros::Subscriber sub;

void function(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s] from channel1 ", msg->data.c_str());
    chatter_pub.publish(msg);
    ROS_INFO("%s", msg->data.c_str());
}
 
int main(int argc, char **argv)
{
 
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    chatter_pub = n.advertise<std_msgs::String>("channel2", 1000);
    sub = n.subscribe("channel1", 1, &function);
    ros::Rate loop_rate(10);
    ROS_INFO("Please send message!");
    ros::spin();
	
    return 0;
}
