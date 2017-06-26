#include <ros/ros.h>
#include "gps_msgs/gps_msg.h"

void checkGPSCallback(const gps_msgs::gps_msg::ConstPtr & msg)
{
  ROS_INFO("========================");
  ROS_INFO("Stamp: %d", msg->stamp);
  ROS_INFO("Fix type: %d", msg->fix_type);
  ROS_INFO("Latitude: %f", msg->lat);
  ROS_INFO("Longitude: %f", msg->lon);
  ROS_INFO("Height: %f", msg->height);
  ROS_INFO("X: %f", msg->x);
  ROS_INFO("Y: %f", msg->y);
  ROS_INFO("Z: %f", msg->z);
  ROS_INFO("X velocity: %f", msg->vel_x);
  ROS_INFO("Y velocity: %f", msg->vel_y);
  ROS_INFO("Z velocity: %f", msg->vel_z);
  // ROS_INFO("Heading of vehicle: %f", msg->head_vehicle);
  ROS_INFO("Heading of motion: %f", msg->head_motion);
  ROS_INFO("Ground Speed: %f", msg->ground_speed);
  ROS_INFO("========================");
}
 
int main(int argc, char **argv)
{

  ros::init(argc, argv, "subscriber");
 
  ros::NodeHandle n;
 
  ros::Subscriber sub = n.subscribe("/gps/data", 1000, checkGPSCallback);
 
  ros::spin();
 
  return 0;
}