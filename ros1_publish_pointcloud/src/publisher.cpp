#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>

main(int argc, char **argv)
{
    ros::init (argc, argv, "pcl_publisher");

    ROS_INFO("Started PCL read node");

    ros::NodeHandle nh;
    ros::Publisher pcl_pub = nh.advertise<sensor_msgs::PointCloud2> ("pcl_topic", 1);

    sensor_msgs::PointCloud2 msg;
    pcl::PointCloud<pcl::PointXYZ> cloud;

    pcl::io::loadPCDFile (argv[1], cloud);

    pcl::toROSMsg(cloud, msg);
    // output.header.frame_id = "point_cloud";

    ros::Rate loop_rate(10);
    int id_index = 0;
    while (ros::ok()){
        msg.header.frame_id = std::to_string(id_index++);
        ROS_INFO("%s, frame_id: %s", "send it", msg.header.frame_id.c_str());
        pcl_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
