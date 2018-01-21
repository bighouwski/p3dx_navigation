#include <ros/ros.h>

// http://wiki.ros.org/dynamic_reconfigure/Tutorials/SettingUpDynamicReconfigureForANode%28cpp%29

#include <dynamic_reconfigure/server.h>
#include <p3dx_navigation/DynamicConfig.h>

void callback(p3dx_navigation::DynamicConfig &config, uint32_t level) {
  ROS_INFO("Reconfigure Request: %f %f", 
            config.linear_vel, 
            config.angular_vel);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "p3dx_navigation_dynamic");

  dynamic_reconfigure::Server<p3dx_navigation::DynamicConfig> server;
  dynamic_reconfigure::Server<p3dx_navigation::DynamicConfig>::CallbackType f;

  f = boost::bind(&callback, _1, _2);
  server.setCallback(f);

  ROS_INFO("Spinning node");
  ros::spin();
  return 0;
}