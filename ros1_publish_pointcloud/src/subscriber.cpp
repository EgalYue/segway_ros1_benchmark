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
    ros::Time this_t = ros::Time::now();
    std::cout<< "sub time:"<<this_t <<" time Diff: " << this_t - h.stamp << " frame_id: " << h.frame_id <<std::endl;
    //ROS_INFO("%s, frame _id:  %s", "get it", h.frame_id.c_str());
    
// std::cout<<msg->fields.size()<<std::endl;
    // std::cout<<msg->data.size()<<std::endl;
    // std::cout<<msg->fields[0].name<<std::endl;
    // std::cout<<msg->fields[0].offset<<std::endl;
    // std::cout<<(int)msg->fields[0].datatype<<std::endl;
    // std::cout<<msg->fields[0].count<<std::endl;


    //     std::cout<<"==========="<<std::endl;
    //     std::cout<<msg->fields[1].name<<std::endl;
    // std::cout<<msg->fields[1].offset<<std::endl;
    // std::cout<<(int)msg->fields[1].datatype<<std::endl;
    // std::cout<<msg->fields[1].count<<std::endl;

    //     std::cout<<"==========="<<std::endl;
    //     std::cout<<msg->fields[2].name<<std::endl;
    // std::cout<<msg->fields[2].offset<<std::endl;
    // std::cout<<(int)msg->fields[2].datatype<<std::endl;
    // std::cout<<msg->fields[2].count<<std::endl;

}


int main(int argc,char** argv){
  ros::init (argc, argv, "sub_pointcloud");
  ros::NodeHandle nh;

// Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe ("/point_cloud_topic", 1, call_back);
  ros::spin ();
}
