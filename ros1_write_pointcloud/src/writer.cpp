#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <string>
#include <iostream>

int main (int argc, char** argv)
{
  std::string size_str = "100kb"; //default
  size_str = argv[1];
  std::string filepath = "";
  filepath = argv[2];

  int index = 50;
  if("100kb" == size_str){
    index = 50;
  } else if("200kb" == size_str){
    index = 100;
  } else if("500kb" == size_str){
    index = 250;
  } else if("1mb" == size_str){
    index = 500;
  }
 
  pcl::PointCloud<pcl::PointXYZ> cloud;

  // Fill in the cloud data
  cloud.width    = 58;
  cloud.height   = index;
  cloud.is_dense = false;
  cloud.points.resize (cloud.width * cloud.height);

  for (std::size_t i = 0; i < cloud.points.size (); ++i)
  {
    cloud.points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
    cloud.points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
    cloud.points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);
  }
  
  filepath = filepath + "/" + size_str + "_pcd.pcd";
  std::cout<< filepath<<std::endl;
  pcl::io::savePCDFileASCII (filepath, cloud);
  std::cerr << "Saved " << cloud.points.size () << " data points to test_pcd.pcd." << std::endl;

  for (std::size_t i = 0; i < cloud.points.size (); ++i)
    std::cerr << "    " << cloud.points[i].x << " " << cloud.points[i].y << " " << cloud.points[i].z << std::endl;

  return (0);
}
