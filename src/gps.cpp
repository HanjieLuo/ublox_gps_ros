#include "gps.h"


GPS::GPS(void) {
	step_ = 0;
	cksum_A_ = 0;
	cksum_B_ = 0;
	msg_cksum_A_ = 0;
	msg_cksum_B_ = 0;
	msg_index_ = 0;
	stamp_ = -1;
	// data_reday_ = false;

	// proj_ = NULL;
	device_ = -1;
	img_map_ = NULL;

	is_align_ = false;

	getParams();
	OpenDevice();

	gps_pub_ = nh_.advertise<gps_msgs::gps_msg>("/gps/data", 100);
	
}

GPS::~GPS() {
	if (device_ != -1) {
		close(device_);
	}

	if(!output_data_file_.empty()) {
		out_.close();
	}

	if(img_map_ != NULL) {
		img_map_->release();
		delete img_map_;
	}

	// if (proj_ != NULL) {
	// 	delete proj_;
	// }
}

void GPS::Run() {
	// ros::Rate loop_rate(1);
	unsigned char buffer[1024];
	int read_n;

	ROS_INFO("Star advertising GPS data on /gps/data ...");

	while (ros::ok()) {
		read_n = read(device_, buffer, 1024);
		if (read_n < 1) {
			continue;
		}

		getData(buffer, read_n);

		ros::spinOnce();

		// ROS_INFO("OK");
		// std::cout << read_n << std::endl;
		// std::cout << buffer << std::endl;
		// std::cout << "============" << std::endl;
		// loop_rate.sleep();
	}
}

void GPS::getData(unsigned char buffer[], int buffer_size) {
	int i, msg_index;
	unsigned char data;
	// std::cout << buffer_size << std::endl;
	for (i = 0; i < buffer_size; i++) {
		// std::cout<<buffer[i]<<",";
		// std::cout<<(unsigned char)buffer[i]<<std::endl;

		switch (step_) {
			case 0: {
				if (buffer[i] == MSG_HEAD1) {
					cksum_A_ = cksum_B_ = 0;
					step_ = 1;
				}
				continue;
			}

			case 1: {
				if (buffer[i] == MSG_HEAD2) {
					step_ = 2;
				} else {
					step_ = 0;
				}
				continue;
			}

			case 2: {
				msg_class_ = buffer[i];

				cksum_A_ += msg_class_;
				cksum_B_ += cksum_A_;

				// std::cout<<HEX(msg_class_)<<std::endl;
				// std::cout<<HEX(cksum_A_)<<std::endl;
				// std::cout<<HEX(cksum_B_)<<std::endl<<std::endl;

				step_ = 3;
				continue;
			}

			case 3: {
				msg_id_ = buffer[i];

				cksum_A_ += msg_id_;
				cksum_B_ += cksum_A_;

				// std::cout<<HEX(msg_id_)<<std::endl;
				// std::cout<<HEX(cksum_A_)<<std::endl;
				// std::cout<<HEX(cksum_B_)<<std::endl<<std::endl;

				step_ = 4;
				continue;
			}

			case 4: {
				data  = buffer[i];
				payload_length_ = data;

				cksum_A_ += data;
				cksum_B_ += cksum_A_;

				// std::cout<<HEX(data)<<std::endl;
				// std::cout<<HEX(cksum_A_)<<std::endl;
				// std::cout<<HEX(cksum_B_)<<std::endl<<std::endl;

				step_ = 5;
				continue;
			}

			case 5: {
				data = buffer[i];

				cksum_A_ += data;
				cksum_B_ += cksum_A_;

				payload_length_ += (data<<8);

				// std::cout<<"payload_length_:"<<payload_length_<<std::endl;

				// std::cout<<HEX(data)<<std::endl;
				// std::cout<<HEX(cksum_A_)<<std::endl;
				// std::cout<<HEX(cksum_B_)<<std::endl<<std::endl;

				msg_index_ = 0;
				step_ = 6;
				continue;
			}

			case 6: {
				if (msg_index_ < payload_length_) {
					// std::cout<<"=========="<<std::endl;
					// std::cout<<i<<std::endl;
					data = buffer[i];
					payload_[msg_index_] = data;

					cksum_A_ += data;
					cksum_B_ += cksum_A_;

					// std::cout<<HEX(data)<<std::endl;
					// std::cout<<HEX(cksum_A_)<<std::endl;
					// std::cout<<HEX(cksum_B_)<<std::endl<<std::endl;
					// std::cout<<"=========="<<std::endl;

					msg_index_++;

				} else {
					i--;
					step_ = 7;
				}
				continue;
			}

			case 7: {
				msg_cksum_A_ = buffer[i];
				step_ = 8;
				continue;
			}

			case 8: {
				msg_cksum_B_ = buffer[i];

				if (msg_cksum_A_ == cksum_A_ && msg_cksum_B_ == cksum_B_) {
					ProcessData();
				}
				// } else {
				// 	// std::cout<<"msg_cksum_A_:"<<HEX(msg_cksum_A_)<<std::endl;
				// 	// std::cout<<"cksum_A_:"<<HEX(cksum_A_)<<std::endl;

				// 	// std::cout<<"msg_cksum_B_:"<<HEX(msg_cksum_B_)<<std::endl;
				// 	// std::cout<<"cksum_B_:"<<HEX(cksum_B_)<<std::endl<<std::endl;
				// }
				step_ = 0;
			}
		}
	}
}

void GPS::ProcessData() {
	if (msg_class_ == 0x01 && msg_id_ == 0x07 && payload_length_ == 92) {
		ParseUbxNavPvt(payload_, pvt_data_);
		stamp_ = pvt_data_.iTOW;

		// if (pvt_data_.iTOW > stamp_) {
		// 	stamp_ = pvt_data_.iTOW;
		// }

		// std::cout<<"UbxNavPvt: "<<std::setprecision(10)<<pvt_data_.iTOW<<std::endl;
		// double x, y, z;
		// Map2Cartesian(pvt_data_.lat, pvt_data_.lon, pvt_data_.height, x, y, z);

		// std::cout <<std::setprecision(10)<< pvt_data_.lat << " " << pvt_data_.lon << " " << pvt_data_.height << "\n";
		// std::cout <<std::setprecision(3)<< x << " " << y << " " << z << "\n" << "\n";
		// ShowMap(pvt_data_);
		if (show_gps_data_) {
			PrintUbxNavPvt(pvt_data_);
		}
	} else if (msg_class_ == 0x01 && msg_id_ == 0x3c && payload_length_ == 40) {
		ParseUbxNavRelPosNED(payload_, relposned_data_);

		if (stamp_ == relposned_data_.iTOW) {
			lat_ = pvt_data_.lat;
			lon_ = pvt_data_.lon;
			height_ = pvt_data_.height;
			vel_x_ = pvt_data_.velN;
			vel_y_ = pvt_data_.velE;
			vel_z_ = pvt_data_.velD;
			ground_speed_ = pvt_data_.gSpeed;
			head_motion_ = pvt_data_.headMot;
		  	// head_vehicle_ = pvt_data_.headVeh;
			fix_type_ = pvt_data_.fixType;


		  	// head_motion = (90 - head_motion);
	        // head_motion = fmod(head_motion + 180, 360);
	        // if (head_motion < 0)
	        //     head_motion += 360;
	        // head_motion -= 180;
	        // head_motion = head_motion * M_PI / 180;

			head_motion_ = 90 - head_motion_;
			if (head_motion_ < -180) head_motion_ += 360;
			head_motion_ *= 0.01745329251;

			y_ = relposned_data_.relPosN + relposned_data_.relPosHPN;
			x_ = relposned_data_.relPosE + relposned_data_.relPosHPE;
			z_ = relposned_data_.relPosD + relposned_data_.relPosHPD;

			Publish();

			if(!output_data_file_.empty()) {
				out_<<stamp_<<","<<fix_type_<<","<<std::fixed<<std::setprecision(32)
				<<lat_<<","<<lon_<<","<<height_<<","
				<<x_<<","<<y_<<","<<z_<<","
				<<vel_x_<<","<<vel_y_<<","<<vel_z_<<","   
				<<","<<head_motion_<<","<<ground_speed_<<std::endl;
			}

			if (show_google_map_) {
				ShowGoogleMap(lat_, lon_);
			}

			if (show_2d_map_) {
				Show2dMap(x_, y_, head_motion_, ground_speed_);
			}

			if (show_gps_data_) {		
				PrintUbxNavRelPosNED(relposned_data_);
			}
		}
		// } else {
		// 	std::cout<<"==========="<<std::endl;
		// 	std::cout<<std::setprecision(10)<<stamp_<<std::endl;
		// 	std::cout<<std::setprecision(10)<<relposned_data_.iTOW<<std::endl;
		// 	std::cout<<"==========="<<std::endl;

		// }
		// std::cout<<"UbxNavRelPosNED: "<<std::setprecision(10)<<relposned_data_.iTOW<<std::endl;
	}
}

void GPS::Publish() {
	if (ros::ok()) {
		gps_msgs::gps_msg msg;
		msg.header.stamp = ros::Time::now();
		msg.header.frame_id = "gps";
		msg.stamp = stamp_;
		msg.lat = lat_;
		msg.lon = lon_;
		msg.height = height_;
		msg.x = x_;
		msg.y = y_;
		msg.z = z_;
		msg.vel_x = vel_x_;
		msg.vel_y = vel_y_;
		msg.vel_z = vel_z_;
		msg.ground_speed = ground_speed_;
		msg.head_motion = head_motion_;
		// msg.head_vehicle = head_vehicle_;
		msg.fix_type = fix_type_;

		if (is_align_) {
			msg.x_align = cos_s_ * x_ - sin_s_ * y_ + px_;
			msg.y_align = sin_s_ * x_ + cos_s_ * y_ + py_;
		} else {
			msg.x_align = x_;
			msg.y_align = y_;
		}

		gps_pub_.publish(msg);
		// std::cout<<stamp_<<std::endl;
		// ROS_INFO("Publish %f", stamp_);
	}
	
}

void GPS::getParams() {
	ros::NodeHandle private_nh("~");
	private_nh.param("port", port_, std::string("/dev/ttyACM0"));
	private_nh.param("baudrate", baud_rate_, 19200);
	baud_rate_ = BaudrateEnum(baud_rate_);

	// private_nh.param("base_lat", base_lat_, -1.0);
	// private_nh.param("base_lon", base_lon_, -1.0);
	// private_nh.param("base_height", base_height_, -1.0);

	private_nh.param("output_data_file", output_data_file_, std::string(""));
	if(!output_data_file_.empty()) {
		out_.open(output_data_file_, std::fstream::out);
		if( !out_.is_open()) {
			ROS_ERROR("Can not load file %s. \n", output_data_file_.c_str());
		}
	}

	private_nh.param("show_2d_map", show_2d_map_, false);
	if (show_2d_map_) {
		img_map_ = new cv::Mat(2000, 2000, CV_8UC3, cv::Scalar(255, 255, 255));
		cv::circle(*img_map_, cv::Point(1000 , 1000), 10, cv::Scalar(255, 0, 255), -1);
	}

	private_nh.param("show_google_map", show_google_map_, false);

	private_nh.param("show_gps_data", show_gps_data_, false);

  	double theta, scalar;
  	private_nh.param("align/theta", theta, 0.0);
  	private_nh.param("align/scalar", scalar, 0.0);
  	private_nh.param("align/px", px_, 0.0);
  	private_nh.param("align/py", py_, 0.0);

  	if (scalar != 0.0) {
  		is_align_ = true;
  		sin_s_ = sin(theta) * scalar;
  		cos_s_ = cos(theta) * scalar;
  	}

}

bool GPS::OpenDevice() {
	int flag;
	device_ = open(port_.c_str(), O_RDWR);
	if (device_ < 0) {
		ROS_ERROR("Can not open GPS device at %s. \n\n", port_.c_str());
		return false;
	}

	ROS_INFO("Open GPS device at %s\n.", port_.c_str());

	struct termios old_tio, new_tio;
	tcgetattr(device_, &old_tio);

	bzero(&new_tio, sizeof(new_tio));
	new_tio.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	new_tio.c_iflag &= ~(BRKINT | ICRNL | ISTRIP | IXON);
	new_tio.c_cflag &= ~(CSIZE | PARENB);
	new_tio.c_cflag |= CS8;
	new_tio.c_oflag &= ~(OPOST);
	new_tio.c_cc[VMIN] = 255;
	new_tio.c_cc[VTIME] = 0;

	flag = cfsetispeed(&new_tio, baud_rate_);
	if (flag < 0) {
		ROS_ERROR("Set input baud rate faild!");
		return false;
	}

	flag = cfsetospeed(&new_tio, baud_rate_);
	if (flag < 0) {
		ROS_ERROR("Set output baud rate faild!");
		return false;
	}

	tcflush(device_, TCIFLUSH);
	flag = tcsetattr(device_, TCSANOW, &new_tio);

	if (flag < 0) {
		ROS_ERROR("Can not configure the GPS device!");
		return false;
	}

	ROS_INFO("Configure the GPS device successfully!");

	return true;
}


int GPS::BaudrateEnum(int baud) {
	switch (baud) {
		case 0: return B0;
		case 50: return B50;
		case 75: return B75;
		case 110: return B110;
		case 134: return B134;
		case 150: return B150;
		case 200: return B200;
		case 300: return B300;
		case 600: return B600;
		case 1200: return B1200;
		case 1800: return B1800;
		case 2400: return B2400;
		case 4800: return B4800;
		case 9600: return B9600;
		case 19200: return B19200;
		case 38400: return B38400;
		case 57600: return B57600;
		case 115200: return B115200;
		case 230400: return B230400;
		default: {
			ROS_WARN("Can not set baud rate to %d, change to 19200 instead.\n", baud);
			return B19200;
		}
	}
}

// void GPS::Map2Cartesian(const double lat, const double lon, const double height, double &x, double &y, double &z) {
// 	if (proj_ == NULL) {
// 		GeographicLib::Geocentric earth(GeographicLib::Constants::WGS84_a(), GeographicLib::Constants::WGS84_f());
// 		if (!(base_lat_ == -1 && base_lon_ == -1 && base_height_ == -1)) {
// 			proj_ = new GeographicLib::LocalCartesian(base_lat_, base_lon_, base_height_, earth);
// 		} else {
// 			proj_ = new GeographicLib::LocalCartesian(lat, lon, height, earth);
// 		}
// 	}
// 	proj_->Forward(lat, lon, height, x, y, z);
// }

void GPS::ShowGoogleMap(const double lat, const double lon) {
	std::string url = "https://maps.googleapis.com/maps/api/staticmap?center=23.1579,113.522&zoom=18&size=1024x800&maptype=roadmap&markers=color:blue%7Clabel:S%7C" + 
	std::to_string(lat) +
	"," +
	std::to_string(lon) +
	"&key=AIzaSyBlDxCsnL1nn6cKmrgBKU2khbutU6J18Xs";
	cv::Mat img = getUrlImg(url);
	// std::cout<<"Latitude: "<<lat<<std::endl;
	// std::cout<<"Longitude: "<<lon<<std::endl<<std::endl;
	cv::imshow("map", img);
	cv::waitKey(1);
}

void GPS::Show2dMap(const double x, const double y, const double dir, const double v) {
	//std::cout<<"y: "<<y<<std::endl;
	//std::cout<<"x: "<<x<<std::endl;
	int img_x = (int)(roundf(x * 10) + 1000);
	int img_y = (int)(- roundf(y * 10) + 1000);
	//std::cout<<"img_y: "<<img_y<<std::endl;
	//std::cout<<"img_x: "<<img_x<<std::endl<<std::endl;
	// img_map_->at<cv::Vec3b>(img_y, img_x)[0] = 0;

	int r = roundf(v * 100);
	int dir_x = r * cos(dir);
	int dir_y = r * sin(dir);

	cv::circle(*img_map_, cv::Point(img_x, img_y), 1, cv::Scalar(0, 0, 0), -1);

	cv::Mat img_show = img_map_->clone();

	GPS::ArrowedLine(img_show, cv::Point(img_x, img_y), cv::Point(img_x + dir_x, img_y - dir_y), CV_RGB(255, 0, 255));
	cv::resize(img_show, img_show, cv::Size(), 0.5, 0.5);

	cv::imshow("2D MAP", img_show);
	cv::waitKey(1);
}

int GPS::WriteData(char *ptr, int size, int nmemb, void *user_data){
	std::vector<uchar> *stream = (std::vector<uchar>*)user_data;
	size_t count = size * nmemb;
	stream->insert(stream->end(), ptr, ptr + count);
	return count;
}

cv::Mat GPS::getUrlImg(std::string url, int timeout) {
	std::vector<uchar> stream;
	CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); //the img url
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, GPS::WriteData); // pass the writefunction
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stream); // pass the stream ptr to the writefunction
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout); // timeout if curl_easy hangs, 
    CURLcode res = curl_easy_perform(curl); // start curl
    curl_easy_cleanup(curl); // cleanup
    return cv::imdecode(stream, -1); // 'keep-as-is
}

void GPS::ParseUbxNavRelPosNED(unsigned char *p, UbxNavRelPosNED &data) {
	data.version = (int)p[0];
	data.refStationId = (int)*((uint16_t *)(p + 2));
	data.iTOW = (uint32_t)*((uint32_t *)(p + 4));
	data.relPosN = (double)*((int32_t *)(p + 8)) / 100.0;
	data.relPosE = (double)*((int32_t *)(p + 12)) / 100.0;
	data.relPosD = (double)*((int32_t *)(p + 16)) / 100.0;
	data.relPosHPN = (double)*((int8_t *)(p + 20)) / 10000.0;
	data.relPosHPE = (double)*((int8_t *)(p + 21)) / 10000.0;
	data.relPosHPD = (double)*((int8_t *)(p + 22)) / 10000.0;
	data.accN = (double)*((uint32_t *)(p + 24)) / 10000.0;
	data.accE = (double)*((uint32_t *)(p + 28)) / 10000.0;
	data.accD = (double)*((int32_t *)(p + 32)) / 10000.0; 
	data.flags = *((int8_t *)(p + 21));
}

void GPS::ParseUbxNavPvt(unsigned char *p, UbxNavPvt &data) {
	data.iTOW = (uint32_t)*((uint32_t *)p);
	data.year = (int)*((uint16_t *)(p + 4));
	data.month = (int)p[6];
	data.day = (int)p[7];
	data.hour = (int)p[8];
	data.min = (int)p[9];
	data.sec = (int)p[10];
	data.valid = *((int8_t *)(p + 11));
	data.tAcc = (double)*((uint32_t *)(p + 12));
	data.nano = (double)*((int32_t *)(p + 16));
	data.fixType = (int)p[20];
	data.flags = *((int8_t *)(p + 21));
	data.flags2 = *((int8_t *)(p + 22));
	data.numSV = (int)p[23];
	data.lon = (double)*((int32_t *)(p + 24)) / 10000000.0;
	data.lat = (double)*((int32_t *)(p + 28)) / 10000000.0;
	data.height = (double)*((int32_t *)(p + 32)) / 1000.0; 
	data.hMSL = (double)*((int32_t *)(p + 36)) / 1000.0; 
	data.hAcc = (double)*((uint32_t *)(p + 40)) / 1000.0;
	data.vAcc = (double)*((uint32_t *)(p + 44)) / 1000.0;
	data.velN = (double)*((int32_t *)(p + 48)) / 1000.0; 
	data.velE = (double)*((int32_t *)(p + 52)) / 1000.0; 
	data.velD = (double)*((int32_t *)(p + 56)) / 1000.0; 
	data.gSpeed = (double)*((int32_t *)(p + 60)) / 1000.0; 
	data.headMot = (double)*((int32_t *)(p + 64)) / 100000.0; 
	data.sAcc = (double)*((uint32_t *)(p + 68));
	data.headAcc = (double)*((uint32_t *)(p + 72)) / 10000.0;
	data.pDOP = (double)*((uint16_t *)(p + 76)) / 100.0;
	data.headVeh = (double)*((int32_t *)(p + 84)) / 100000.0; 
	data.magDec = (double)*((int16_t *)(p + 88)) / 100.0; 
	data.magAcc = (double)*((uint16_t *)(p + 90)) / 100.0; 
}

void GPS::ParseUbxNavPvtRaw(unsigned char *p, UbxNavPvtRaw &data) {
	data.iTOW = *((uint32_t *)p);
	data.year = *((uint16_t *)(p + 4));
	data.month = p[6];
	data.day = p[7];
	data.hour = p[8];
	data.min = p[9];
	data.sec = p[10];
	data.valid = *((int8_t *)(p + 11));
	data.tAcc = *((uint32_t *)(p + 12));
	data.nano = *((int32_t *)(p + 16));
	data.fixType = p[20];
	data.flags = *((int8_t *)(p + 21));
	data.flags2 = *((int8_t *)(p + 22));
	data.numSV = p[23];
	data.lon = *((int32_t *)(p + 24));// / 10000000.0;
	data.lat = *((int32_t *)(p + 28));// / 10000000.0;
	data.height = *((int32_t *)(p + 32)); 
	data.hMSL = *((int32_t *)(p + 36)); 
	data.hAcc = *((uint32_t *)(p + 40));
	data.vAcc = *((uint32_t *)(p + 44));
	data.velN = *((int32_t *)(p + 48)); 
	data.velE = *((int32_t *)(p + 52)); 
	data.velD = *((int32_t *)(p + 56)); 
	data.gSpeed = *((int32_t *)(p + 60)); 
	data.headMot = *((int32_t *)(p + 64));// / 100000.0; 
	data.sAcc = *((uint32_t *)(p + 68));
	data.headAcc = *((uint32_t *)(p + 72));// / 10000.0;
	data.pDOP = *((uint16_t *)(p + 76));// / 100.0;
	data.headVeh = *((int32_t *)(p + 84));// / 100000.0; 
	data.magDec = *((int16_t *)(p + 88));// / 100.0; 
	data.magAcc = *((uint16_t *)(p + 90));// / 100.0; 
}


void GPS::PrintUbxNavPvtRaw(UbxNavPvtRaw &data){
	std::cout<<"========================================="<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"iTOW: "   <<std::left<<std::setw(25)<<static_cast<unsigned>(data.iTOW)                            <<std::left<<std::setw(10)<<"ms"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"year: "   <<std::left<<std::setw(25)<<static_cast<unsigned>(data.year)                            <<std::left<<std::setw(10)<<"y"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"month: "  <<std::left<<std::setw(25)<<static_cast<unsigned>(data.month)    <<std::left<<std::setw(10)<<"m"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"day: "    <<std::left<<std::setw(25)<<static_cast<unsigned>(data.day)      <<std::left<<std::setw(10)<<"d"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"hour: "   <<std::left<<std::setw(25)<<static_cast<unsigned>(data.hour)     <<std::left<<std::setw(10)<<"h"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"min: "    <<std::left<<std::setw(25)<<static_cast<unsigned>(data.min)      <<std::left<<std::setw(10)<<"min"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"sec: "    <<std::left<<std::setw(25)<<static_cast<unsigned>(data.sec)      <<std::left<<std::setw(10)<<"s"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"valid: "  <<std::left<<std::setw(25)<<std::bitset<8>(data.valid)           <<std::left<<std::setw(10)<<"-"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"tAcc: "   <<std::left<<std::setw(25)<<static_cast<unsigned>(data.tAcc)                            <<std::left<<std::setw(10)<<"ns"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"nano: "   <<std::left<<std::setw(25)<<data.nano                            <<std::left<<std::setw(10)<<"ns"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"fixType: "<<std::left<<std::setw(25)<<static_cast<unsigned>(data.fixType)  <<std::left<<std::setw(10)<<"-"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"flags: "  <<std::left<<std::setw(25)<<std::bitset<8>(data.flags)           <<std::left<<std::setw(10)<<"-"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"flags2: " <<std::left<<std::setw(25)<<std::bitset<8>(data.flags2)          <<std::left<<std::setw(10)<<"-"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"numSV: "  <<std::left<<std::setw(25)<<static_cast<unsigned>(data.numSV)    <<std::left<<std::setw(10)<<"-"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"lon: "    <<std::left<<std::setw(25)<<data.lon                             <<std::left<<std::setw(10)<<"deg"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"lat: "    <<std::left<<std::setw(25)<<data.lat                             <<std::left<<std::setw(10)<<"deg"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"height: " <<std::left<<std::setw(25)<<data.height                          <<std::left<<std::setw(10)<<"mm"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"hMSL: "   <<std::left<<std::setw(25)<<data.hMSL                            <<std::left<<std::setw(10)<<"mm"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"hAcc: "   <<std::left<<std::setw(25)<<static_cast<unsigned>(data.hAcc)                            <<std::left<<std::setw(10)<<"mm"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"vAcc: "   <<std::left<<std::setw(25)<<static_cast<unsigned>(data.vAcc)                            <<std::left<<std::setw(10)<<"mm"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"velN: "   <<std::left<<std::setw(25)<<data.velN                            <<std::left<<std::setw(10)<<"mm/s"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"velE: "   <<std::left<<std::setw(25)<<data.velE                            <<std::left<<std::setw(10)<<"mm/s"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"velD: "   <<std::left<<std::setw(25)<<data.velD                            <<std::left<<std::setw(10)<<"mm/s"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"gSpeed: " <<std::left<<std::setw(25)<<data.gSpeed                          <<std::left<<std::setw(10)<<"mm/s"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"headMot: "<<std::left<<std::setw(25)<<data.headMot                         <<std::left<<std::setw(10)<<"deg"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"sAcc: "   <<std::left<<std::setw(25)<<static_cast<unsigned>(data.sAcc)                            <<std::left<<std::setw(10)<<"mm/s"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"headAcc: "<<std::left<<std::setw(25)<<static_cast<unsigned>(data.headAcc)                         <<std::left<<std::setw(10)<<"deg"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"pDOP: "   <<std::left<<std::setw(25)<<static_cast<unsigned>(data.pDOP)                            <<std::left<<std::setw(10)<<"-"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"headVeh: "<<std::left<<std::setw(25)<<data.headVeh                         <<std::left<<std::setw(10)<<"deg"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"magDec: " <<std::left<<std::setw(25)<<data.magDec                          <<std::left<<std::setw(10)<<"deg"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"magAcc: " <<std::left<<std::setw(25)<<static_cast<unsigned>(data.magAcc)                          <<std::left<<std::setw(10)<<"deg"<<std::endl;
	std::cout<<"========================================="<<std::endl;
}

void GPS::PrintUbxNavPvt(UbxNavPvt &data){
	std::cout<<"========================================="<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"iTOW: "   <<std::left<<std::setw(25)<<data.iTOW                            <<std::left<<std::setw(10)<<"ms"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"year: "   <<std::left<<std::setw(25)<<data.year                            <<std::left<<std::setw(10)<<"y"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"month: "  <<std::left<<std::setw(25)<<data.month                           <<std::left<<std::setw(10)<<"m"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"day: "    <<std::left<<std::setw(25)<<data.day                             <<std::left<<std::setw(10)<<"d"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"hour: "   <<std::left<<std::setw(25)<<data.hour                            <<std::left<<std::setw(10)<<"h"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"min: "    <<std::left<<std::setw(25)<<data.min                             <<std::left<<std::setw(10)<<"min"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"sec: "    <<std::left<<std::setw(25)<<data.sec                             <<std::left<<std::setw(10)<<"s"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"valid: "  <<std::left<<std::setw(25)<<std::bitset<8>(data.valid)           <<std::left<<std::setw(10)<<"-"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"tAcc: "   <<std::left<<std::setw(25)<<data.tAcc                            <<std::left<<std::setw(10)<<"ns"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"nano: "   <<std::left<<std::setw(25)<<data.nano                            <<std::left<<std::setw(10)<<"ns"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"fixType: "<<std::left<<std::setw(25)<<data.fixType                         <<std::left<<std::setw(10)<<"-"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"flags: "  <<std::left<<std::setw(25)<<std::bitset<8>(data.flags)           <<std::left<<std::setw(10)<<"-"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"flags2: " <<std::left<<std::setw(25)<<std::bitset<8>(data.flags2)          <<std::left<<std::setw(10)<<"-"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"numSV: "  <<std::left<<std::setw(25)<<data.numSV                           <<std::left<<std::setw(10)<<"-"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"lon: "    <<std::left<<std::setw(25)<<data.lon                             <<std::left<<std::setw(10)<<"deg"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"lat: "    <<std::left<<std::setw(25)<<data.lat                             <<std::left<<std::setw(10)<<"deg"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"height: " <<std::left<<std::setw(25)<<data.height                          <<std::left<<std::setw(10)<<"m"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"hMSL: "   <<std::left<<std::setw(25)<<data.hMSL                            <<std::left<<std::setw(10)<<"m"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"hAcc: "   <<std::left<<std::setw(25)<<data.hAcc                            <<std::left<<std::setw(10)<<"m"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"vAcc: "   <<std::left<<std::setw(25)<<data.vAcc                            <<std::left<<std::setw(10)<<"m"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"velN: "   <<std::left<<std::setw(25)<<data.velN                            <<std::left<<std::setw(10)<<"m/s"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"velE: "   <<std::left<<std::setw(25)<<data.velE                            <<std::left<<std::setw(10)<<"m/s"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"velD: "   <<std::left<<std::setw(25)<<data.velD                            <<std::left<<std::setw(10)<<"m/s"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"gSpeed: " <<std::left<<std::setw(25)<<data.gSpeed                          <<std::left<<std::setw(10)<<"m/s"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"headMot: "<<std::left<<std::setw(25)<<data.headMot                         <<std::left<<std::setw(10)<<"deg"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"sAcc: "   <<std::left<<std::setw(25)<<data.sAcc                            <<std::left<<std::setw(10)<<"m/s"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"headAcc: "<<std::left<<std::setw(25)<<data.headAcc                         <<std::left<<std::setw(10)<<"deg"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"pDOP: "   <<std::left<<std::setw(25)<<data.pDOP                            <<std::left<<std::setw(10)<<"-"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"headVeh: "<<std::left<<std::setw(25)<<data.headVeh                         <<std::left<<std::setw(10)<<"deg"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"magDec: " <<std::left<<std::setw(25)<<data.magDec                          <<std::left<<std::setw(10)<<"deg"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<"magAcc: " <<std::left<<std::setw(25)<<data.magAcc                          <<std::left<<std::setw(10)<<"deg"<<std::endl;
	std::cout<<"========================================="<<std::endl;
}

void GPS::PrintUbxNavRelPosNED(UbxNavRelPosNED &data) {
	std::cout<<"========================================="<<std::endl;
	std::cout<<std::right<<std::setw(15)<<"version: "       <<std::left<<std::setw(25)<<data.version                         <<std::left<<std::setw(10)<<"-"<<std::endl;
	std::cout<<std::right<<std::setw(15)<<"refStationId: "  <<std::left<<std::setw(25)<<data.refStationId                    <<std::left<<std::setw(10)<<"-"<<std::endl;
	std::cout<<std::right<<std::setw(15)<<"iTOW: "          <<std::left<<std::setw(25)<<data.iTOW                            <<std::left<<std::setw(10)<<"ms"<<std::endl;
	std::cout<<std::right<<std::setw(15)<<"relPosN: "       <<std::left<<std::setw(25)<<data.relPosN                         <<std::left<<std::setw(10)<<"m"<<std::endl;
	std::cout<<std::right<<std::setw(15)<<"relPosE: "       <<std::left<<std::setw(25)<<data.relPosE                         <<std::left<<std::setw(10)<<"m"<<std::endl;
	std::cout<<std::right<<std::setw(15)<<"relPosD: "       <<std::left<<std::setw(25)<<data.relPosD                         <<std::left<<std::setw(10)<<"m"<<std::endl;
	std::cout<<std::right<<std::setw(15)<<"relPosHPN: "     <<std::left<<std::setw(25)<<data.relPosHPN                       <<std::left<<std::setw(10)<<"m"<<std::endl;
	std::cout<<std::right<<std::setw(15)<<"relPosHPE: "     <<std::left<<std::setw(25)<<data.relPosHPE                       <<std::left<<std::setw(10)<<"m"<<std::endl;
	std::cout<<std::right<<std::setw(15)<<"relPosHPD: "     <<std::left<<std::setw(25)<<data.relPosHPD                       <<std::left<<std::setw(10)<<"m"<<std::endl;
	std::cout<<std::right<<std::setw(15)<<"accN: "          <<std::left<<std::setw(25)<<data.accN                            <<std::left<<std::setw(10)<<"m"<<std::endl;
	std::cout<<std::right<<std::setw(15)<<"accE: "          <<std::left<<std::setw(25)<<data.accE                            <<std::left<<std::setw(10)<<"m"<<std::endl;
	std::cout<<std::right<<std::setw(15)<<"accD: "          <<std::left<<std::setw(25)<<data.accD                            <<std::left<<std::setw(10)<<"m"<<std::endl;
	std::cout<<std::right<<std::setw(15)<<"flags: "         <<std::left<<std::setw(35)<<std::bitset<32>(data.flags)          <<std::left<<std::setw(10)<<"-"<<std::endl;
	std::cout<<"========================================="<<std::endl;
}


void GPS::ArrowedLine(cv::Mat &img, cv::Point pt1, cv::Point pt2, const cv::Scalar& color, int thickness, int line_type, int shift, double tipLength) {
	const double tipSize = norm(pt1-pt2)*tipLength; // Factor to normalize the size of the tip depending on the length of the arrow

	cv::line(img, pt1, pt2, color, thickness, line_type, shift);

	const double angle = atan2( (double) pt1.y - pt2.y, (double) pt1.x - pt2.x );

	cv::Point p(cvRound(pt2.x + tipSize * cos(angle + CV_PI / 4)),
		cvRound(pt2.y + tipSize * sin(angle + CV_PI / 4)));
	line(img, p, pt2, color, thickness, line_type, shift);

	p.x = cvRound(pt2.x + tipSize * cos(angle - CV_PI / 4));
	p.y = cvRound(pt2.y + tipSize * sin(angle - CV_PI / 4));
	line(img, p, pt2, color, thickness, line_type, shift);
}
