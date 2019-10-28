# ROS nodelet transport image test


参考： https://github.com/yangruihan/WustRobot/blob/master/Tank/ROS%E7%9A%84nodelet%E8%AF%A6%E8%A7%A3.markdown  

Terminal1：  
`rosrun nodelet nodelet manager __name:=nodelet_manager`

Terminal2：  
`rosrun nodelet nodelet load segway_image_nodelet/Sub_nodelet nodelet_manager`

Terminal3：  
`rosrun nodelet nodelet load segway_image_nodelet/Sub2_nodelet nodelet_manager`

Terminal4：  
`rosrun nodelet nodelet load segway_image_nodelet/Sub3_nodelet nodelet_manager`

Terminal5：  
`rosrun nodelet nodelet load segway_image_nodelet/Pub_nodelet nodelet_manager`