#include<ros/ros.h>
#include<pcl/point_cloud.h>
#include<pcl_conversions/pcl_conversions.h>
#include<sensor_msgs/PointCloud2.h>
#include<pcl/io/pcd_io.h>//which contains the required definitions to load and store point clouds to PCD and other file formats.


#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>
#include <ecl/threads/thread.hpp>

#include <std_msgs/String.h>
#include <stdio.h>

#include <cinttypes>
#include <iostream>

namespace segway_pointcloud_nodelet
{
    class Pub_nodelet : public nodelet::Nodelet
    {
    public:
        Pub_nodelet()
        {
        }
        ~Pub_nodelet()
        {
            pub_thread_.join();
        }
    private:
        virtual void onInit()
        {
            ros::NodeHandle& nh = getNodeHandle();

            pub = nh.advertise<sensor_msgs::PointCloud2>("segway_pcl",1);

            pub_thread_.start(&Pub_nodelet::publish, *this);
        }

        void publish()
        {
            pcl::PointCloud<pcl::PointXYZ> cloud;
            sensor_msgs::PointCloud2 msg;
            pcl::io::loadPCDFile ("/home/yuehu/Desktop/catkin_ws/src/segway_pointcloud_nodelet/src/test_pcd.pcd", cloud);
            pcl::toROSMsg(cloud, msg);
            msg.header.frame_id = "odom";//this has been done in order to be able to visualize our PointCloud2 message on the RViz visualizer

            sensor_msgs::PointCloud2Ptr msgPtr = boost::make_shared<sensor_msgs::PointCloud2>(msg);
            int num = 1;
            ros::Rate r(10);
            while(ros::ok())
            {
                ROS_INFO(" %d ,publish!", num++);
                printf("publish message address: 0x%" PRIXPTR "\n", reinterpret_cast<std::uintptr_t>(msgPtr.get()));
//                std::cout<< msg.width<<std::endl;
                pub.publish(msgPtr);
                ros::spinOnce();
                r.sleep();
            }
        }

        ros::Publisher pub;
        ecl::Thread pub_thread_;
    };
}

PLUGINLIB_EXPORT_CLASS(segway_pointcloud_nodelet::Pub_nodelet, nodelet::Nodelet)