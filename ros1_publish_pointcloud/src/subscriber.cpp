#include <ros/ros.h>
//#include <pcl/point_cloud.h>
//msgs type and conversion
#include <sensor_msgs/PointCloud2.h>
//#include <pcl_conversions/pcl_conversions.h>
//pcd io
//#include <pcl/io/pcd_io.h>
//point types
//#include <pcl/point_types.h>

void call_back(const sensor_msgs::PointCloud2ConstPtr& msg){
    std_msgs::Header h = msg->header;
    ROS_INFO("%s, frame _id:  %s", "get it", h.frame_id.c_str());
}


int main(int argc,char** argv){
  ros::init (argc, argv, "sub_pointcloud");
  ros::NodeHandle nh;

// Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe ("pcl_topic", 1, call_back);
  ros::spin ();
}
