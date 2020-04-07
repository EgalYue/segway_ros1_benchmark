#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>


#include <algorithm>
#include <random>
#include <functional>
#include <climits>

#include <sensor_msgs/PointField.h>


using random_bytes_engine = std::independent_bits_engine<std::default_random_engine, CHAR_BIT, unsigned char>;
main(int argc, char **argv)
{
    ros::init (argc, argv, "pcl_publisher");

    ROS_INFO("Started PCL read node");

    ros::NodeHandle nh;
    ros::Publisher pcl_pub = nh.advertise<sensor_msgs::PointCloud2> ("/point_cloud_topic", 1);

    sensor_msgs::PointCloud2 msg;
    //pcl::PointCloud<pcl::PointXYZ> cloud;

    //pcl::io::loadPCDFile (argv[1], cloud);
    //pcl::toROSMsg(cloud, msg);
    //msg.header.frame_id = "point_cloud";
    
    std::string size_str = "100kb"; //default
    size_str = argv[1];
    

    int index = 100;
    if("100kb" == size_str){
        index = 100;
    } else if("200kb" == size_str){
        index = 200;
    } else if("500kb" == size_str){
        index = 500;
    } else if("1mb" == size_str){
        index = 1024;
    } else if("1.5mb" == size_str){
        index = 1536;
    } else if("2mb" == size_str){
        index = 2048;
    }


    int data_size = 1024 * index;
    std::vector<sensor_msgs::PointField> point_fields(3);
    for(int i = 0; i< 3;i++){
        sensor_msgs::PointField my_field;
        my_field.name = "x";
        my_field.offset = 0;
        my_field.datatype = 2;
        my_field.count = 1;

        point_fields[i] = my_field;
    }
    msg.fields = point_fields;


    random_bytes_engine rbe;
    std::vector<unsigned char> data(data_size);
    std::generate(begin(data), end(data), std::ref(rbe));
    msg.data = data;
    


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
