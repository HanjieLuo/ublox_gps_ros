#include "gps.h"
#include <iostream>

int main(int argc, char** argv) {
	ros::init(argc, argv, "ublox_gps_ros_node");
	ros::NodeHandle nh;

	GPS my_gps;
	my_gps.Run();

	ros::spin();
	ros::shutdown();

	return(0);
}