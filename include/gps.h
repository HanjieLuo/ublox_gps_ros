#ifndef GPS_H
#define GPS_H

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <bitset>
#include <fstream>
#include <math.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include <termios.h>
#include <unistd.h>

#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>

// for show the map
#include "curl/curl.h"
#include <vector>
#include <opencv2/opencv.hpp>

#include "ublox_gps_ros/gps_msg.h"

//remap in 2d map
// #include <GeographicLib/Geocentric.hpp>
// #include <GeographicLib/LocalCartesian.hpp>

// Navigation Position Velocity Time Solution
// u-blox 8 / u-blox M8 from protocol version 15 up to version 20.2
// Payload Contents (92 bytes)
// ref: Addendum-HPG130_ProtocolSpec_(UBX-16004304).pdf Page:52
struct UbxNavPvtRaw {
	//Type  		Name        Unit      Descrption (scaling)
	uint32_t        iTOW;       // ms     GPS time of week of the navigation epoch. See the description of iTOW for details.
	uint16_t        year;       // y      Year UTC
	uint8_t         month;      // month  Month, range 1..12 UTC
	uint8_t         day;        // d      Day of month, range 1..31 UTC
	uint8_t         hour;       // h      Hour of day, range 0..23 UTC
	uint8_t         min;        // min    Minute of hour, range 0..59 UTC
	uint8_t         sec;        // s      Seconds of minute, range 0..60 UTC
	int8_t          valid;      // -      Validity Flags (see graphic below)
	uint32_t        tAcc;       // ns     Time accuracy estimate UTC
	int32_t         nano;       // ns     Fraction of second, range -1e9..1e9 UTC
	uint8_t         fixType;    // -      GNSSfix Type, 0: no fix 1: dead reckoning only 2: 2D-fix 3: 3D-fix 4: GNSS + dead reckoning combined 5: time only fix
	int8_t          flags;      // -      Fix status flags
	int8_t  		flags2;     // -      Additional flags
	uint8_t  		numSV;      // -      Number of satellites used in Nav Solution
	int32_t         lon;        // deg    Longitude (1e-7)
	int32_t         lat;        // deg    Latitude (1e-7)
	int32_t         height;     // mm     Height above Ellipsoid
	int32_t         hMSL;       // mm     Height above mean sea level
	uint32_t  		hAcc;       // mm     Horizontal Accuracy Estimate
	uint32_t  		vAcc;       // mm     Vertical Accuracy Estimate
	int32_t         velN;       // mm/s   NED north velocity
	int32_t         velE;       // mm/s   NED east velocity
	int32_t         velD;       // mm/s   NED down velocity
	int32_t         gSpeed;     // mm/s   Ground Speed (2-D)
	int32_t         headMot;    // deg    Heading of motion 2-D (1e-5)
	uint32_t  		sAcc;       // mm/s   Speed Accuracy Estimate
	uint32_t  		headAcc;    // deg    Heading Accuracy Estimate (1e-5)
	uint16_t 		pDOP;       // -      Position DOP (0.01)
	// uint8_t  reserved1[6];
	int32_t         headVeh;    //deg     Heading of vehicle (2-D)
	int16_t         magDec;     //deg     Magnetic declination
	uint16_t 		magAcc;     //deg     Magnetic declination accuracy
};

struct UbxNavPvt {
	//Type  		Name        Unit      Descrption (scaling)
	uint32_t        iTOW;       // ms     GPS time of week of the navigation epoch. See the description of iTOW for details.
	int        		year;       // y      Year UTC
	int       		month;      // month  Month, range 1..12 UTC
	int         	day;        // d      Day of month, range 1..31 UTC
	int         	hour;       // h      Hour of day, range 0..23 UTC
	int         	min;        // min    Minute of hour, range 0..59 UTC
	int         	sec;        // s      Seconds of minute, range 0..60 UTC
	int8_t          valid;      // -      Validity Flags (see graphic below)
	double        	tAcc;       // ns     Time accuracy estimate UTC
	double         	nano;       // ns     Fraction of second, range -1e9..1e9 UTC
	int         	fixType;    // -      GNSSfix Type, 0: no fix 1: dead reckoning only 2: 2D-fix 3: 3D-fix 4: GNSS + dead reckoning combined 5: time only fix
	int8_t          flags;      // -      Fix status flags
	int8_t  		flags2;     // -      Additional flags
	int  			numSV;      // -      Number of satellites used in Nav Solution
	double         	lon;        // deg    Longitude (1e-7)
	double         	lat;        // deg    Latitude (1e-7)
	double         	height;     // mm     Height above Ellipsoid
	double         	hMSL;       // mm     Height above mean sea level
	double  		hAcc;       // mm     Horizontal Accuracy Estimate
	double  		vAcc;       // mm     Vertical Accuracy Estimate
	double         	velN;       // mm/s   NED north velocity
	double         	velE;       // mm/s   NED east velocity
	double         	velD;       // mm/s   NED down velocity
	double         	gSpeed;     // mm/s   Ground Speed (2-D)
	double         	headMot;    // deg    Heading of motion 2-D (1e-5)
	double  		sAcc;       // mm/s   Speed Accuracy Estimate
	double  		headAcc;    // deg    Heading Accuracy Estimate (1e-5)
	double 			pDOP;       // -      Position DOP (0.01)
	// uint8_t  reserved1[6];
	double          headVeh;    //deg     Heading of vehicle (2-D)
	double          magDec;     //deg     Magnetic declination
	double 			magAcc;     //deg     Magnetic declination accuracy
};


struct UbxNavRelPosNED {
	//Type  		Name            Unit      Descrption (scaling)
	int        		version;        // -      Message version (0x00 for this version)
	int        		refStationId;   // -      Reference Station ID. Must be in the range 0.. 4095
	uint32_t       	iTOW;           // ms     GPS time of week of the navigation epoch. See the description of iTOW for details.
	double         	relPosN;        // cm     North component of relative position vector
	double         	relPosE;        // cm     East component of relative position vector
	double         	relPosD;        // cm     Down component of relative position vector
	double         	relPosHPN;      // mm     High-precision North component of relative position vector. Must be in the range -99 to +99. 
									//        The full North component of the relative position vector, in units of cm, is given by relPosN + (relPosHPN * 1e-2)
	double         	relPosHPE;      // mm     High-precision East component of relative position vector. Must be in the range -99 to +99.
									//        The full East component of the relative position vector, in units of cm, is given by relPosE + (relPosHPE * 1e-2)
	double         	relPosHPD;      // mm     High-precision Down component of relative position vector. Must be in the range -99 to +99.
								    //        The full Down component of the relative position vector, in units of cm, is given by relPosD + (relPosHPD * 1e-2)
	double          accN;  			// mm     Accuracy of relative position North component      
	double          accE;  			// mm     Accuracy of relative position East component
	double          accD;  			// mm     Accuracy of relative position Down component
	int8_t			flags;    		// -      Flags
};    

//UBX-NAV-PVT (0x01 0x07)
#define MSG_HEAD1 0xb5
#define MSG_HEAD2 0x62
// #define MSG_CLASS 0x01
// #define MSG_ID 0x07
// #define PAYLOAD_LENGTH 92


#define HEX(x) \
std::setw(2) << std::setfill('0') << std::hex << (int)(x) << std::dec

class GPS {
public:
	GPS();
	~GPS();
	void Run();
	bool OpenDevice();
private:
	std::string port_;
	int baud_rate_;
	int device_;

	int payload_length_;
	unsigned char payload_[1080];
	unsigned char msg_class_;
	unsigned char msg_id_;
	unsigned char cksum_A_;
	unsigned char cksum_B_;
	unsigned char msg_cksum_A_;
	unsigned char msg_cksum_B_;
	int msg_index_;
	int step_;

	UbxNavPvt pvt_data_;
	UbxNavRelPosNED relposned_data_;

	// double base_lat_;
	// double base_lon_;
	// double base_height_;

    uint32_t stamp_;      	// ms   	GPS time of week of the navigation epoch. See the description of iTOW for details.  
    double lat_;			// deg
    double lon_;			// deg
    double height_;     	// m    	Height above Ellipsoid
    double x_;				// m		North component of relative position vector
    double y_;				// m   		East component of relative position vector
    double z_;				// m    	Down component of relative position vector
    double vel_x_;			// m/s   	north velocity
	double vel_y_;			// m/s   	east velocity
	double vel_z_;			// m/s   	down velocity
	double ground_speed_;   // m/s   	Ground Speed (2-D)
	double head_motion_;   	// radian   Heading of motion 2-D (1e-5), ref to x direction
	// double head_vehicle_;// deg      Heading of vehicle (2-D)
    int fix_type_;          // -        GNSSfix Type, 0: no fix 1: dead reckoning only 2: 2D-fix 3: 3D-fix 4: GNSS + dead reckoning combined 5: time only fix

    std::string output_data_file_;
    std::ofstream out_;

    bool show_2d_map_;
    bool show_google_map_;
    cv::Mat* img_map_;

    ros::NodeHandle nh_;
    ros::Publisher gps_pub_;

    // GeographicLib::LocalCartesian *proj_;

    void getParams();
    int BaudrateEnum(int baud);
    void getData(unsigned char buffer[], int buffer_size);
    void ProcessData();
    
    void ParseUbxNavPvt(unsigned char *p, UbxNavPvt &data);
    void ParseUbxNavPvtRaw(unsigned char *p, UbxNavPvtRaw &data);
    
    void ParseUbxNavRelPosNED(unsigned char *p, UbxNavRelPosNED &data);

    void PrintUbxNavPvtRaw(UbxNavPvtRaw &data);
    void PrintUbxNavPvt(UbxNavPvt &data);

    void PrintUbxNavRelPosNED(UbxNavRelPosNED &data);

	// void Map2Cartesian(const double lat, const double lon, const double height, double &x, double &y, double &z);

    cv::Mat getUrlImg(std::string url, int timeout = 10);
    static int WriteData(char *ptr, int size, int nmemb, void *user_data);
    void ShowGoogleMap(const double lat, const double lon);
    void Show2dMap(const double x, const double y, const double dir, const double v);

    void Publish();


};
#endif