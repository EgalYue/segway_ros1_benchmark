#include <ros/ros.h>
#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>
#include <ecl/threads/thread.hpp>

#include <std_msgs/String.h>
#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

#include <cinttypes>
namespace segway_image_nodelet
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

            pub = nh.advertise<sensor_msgs::Image>("segway",1);

            pub_thread_.start(&Pub_nodelet::publish, *this);
        }

        void publish()
        {
            cv::Mat image = cv::imread("/home/yuehu/Downloads/SampleJPGImage_2mbmb.jpg", CV_LOAD_IMAGE_COLOR);
            sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();

            int num = 1;
            ros::Rate r(10);
            while(ros::ok())
            {
                ROS_INFO(" %d ,publish!", num++);
                printf("publish message address: 0x%" PRIXPTR "\n", reinterpret_cast<std::uintptr_t>(msg.get()));
                pub.publish(msg);
                ros::spinOnce();
                r.sleep();
            }
        }

        ros::Publisher pub;
        ecl::Thread pub_thread_;
    };
}

PLUGINLIB_EXPORT_CLASS(segway_image_nodelet::Pub_nodelet, nodelet::Nodelet)