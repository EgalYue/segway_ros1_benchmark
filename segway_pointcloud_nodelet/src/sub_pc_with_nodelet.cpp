#include <ros/ros.h>
#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>
#include <sensor_msgs/PointCloud2.h>

#include <cinttypes>
namespace segway_pointcloud_nodelet
{

    class Sub_nodelet : public nodelet::Nodelet
    {
    public:
        Sub_nodelet() :
                num(1)
        {}

    private:
        virtual void onInit()
        {
            ros::NodeHandle& nh = getNodeHandle();
            sub = nh.subscribe("segway_pcl", 1, &Sub_nodelet::Callback, this);

            //ros::spin();
        }

        void Callback(const sensor_msgs::PointCloud2::ConstPtr& msg)
        {
            ROS_INFO(" %d, subsrcibe [1]!", num++);
//            ROS_INFO(msg->encoding.c_str());
            printf(" subsrcibe [1] message address: 0x%" PRIXPTR "\n", reinterpret_cast<std::uintptr_t>(msg.get()));
        }

    private:
        ros::Subscriber sub;
        int num;
    };
}

PLUGINLIB_EXPORT_CLASS(segway_pointcloud_nodelet::Sub_nodelet, nodelet::Nodelet)