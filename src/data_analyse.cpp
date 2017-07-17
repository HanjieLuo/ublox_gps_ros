#include "data_analyse.h"


DataAnalyse::DataAnalyse(void) {

}

DataAnalyse::~DataAnalyse() {

}

bool DataAnalyse::ReadFile(const char *file, int index, int &row, vector<double*> &data) {
    fstream fin(file);

    if (!fin.is_open()) {
        return false;
    }


    int i = 0, col = 0, k;
    char buffer[1024] = {};
    fin.getline(buffer, 1024);

    for (k = 0; k < strlen(buffer); k++) {
        if (buffer[k] == ',') col++;
    }

    fin.seekg(0, ios_base::beg); 

    col++;
    double *tmp;

    while ( fin.getline(buffer, 1024) ) {
        if (i < index) {
            i++;
            continue;
        }

        tmp = new double[col];

        tmp[0] = std::atof(strtok(buffer, ","));

        for (k = 1; k < col; k ++) {
            tmp[k] = std::atof(strtok(NULL, ","));
        }

        data.push_back(tmp);
        i++;
    }

    row = i;
    fin.close();
    return true;
}


void DataAnalyse::ShowMap(vector<double*> &data) {
    int img_x, img_y;
    double x, y, head_motion, ground_speed, t;
    cv::Mat img_map(2000, 2000, CV_8UC3, cv::Scalar(255, 255, 255));
    cv::Mat img_show;
    for(vector<double*>::iterator iter=data.begin(); iter!=data.end(); ++iter) {
        //x = (*iter)[4];
        //y = (*iter)[5];
        x = (*iter)[5];
        y = (*iter)[6];
        head_motion = (*iter)[11];
        ground_speed = (*iter)[12];
        t = (*iter)[0];
        // ground_speed = (*iter)[12];
        cout<<"stamp: "<<static_cast<long>(t)<<endl;
        cout<<"x: "<<x<<endl;
        cout<<"y: "<<y<<endl;
        cout<<"head_motion: "<<head_motion<<endl;
        cout<<"ground_speed: "<<ground_speed<<endl<<endl;;

        img_x = (int)(roundf(x * 10) + 1000);
        img_y = (int)(- roundf(y * 10) + 1000);

        // head_motion = (90 - head_motion);
        // head_motion = fmod(head_motion + 180, 360);
        // if (head_motion < 0)
        //     head_motion += 360;
        // head_motion -= 180;
        // head_motion = head_motion * M_PI / 180;

        //head_motion = 90 - head_motion;
        //if (head_motion < -180) head_motion += 360;
        //head_motion *= 0.01745329251;

        int dir_x, dir_y, r;
        r = roundf(ground_speed * 100);
        dir_x = r * cos(head_motion);
        dir_y = r * sin(head_motion);

        // cout<<head_motion<<endl;
        // cout<<dir_x<<", "<<dir_y<<endl;

        cv::circle(img_map, cv::Point(img_x, img_y), 1, cv::Scalar(0, 0, 0), -1);

        img_show = img_map.clone();

        // GPS::ArrowedLine(img_show, cv::Point(img_x, img_y), cv::Point(img_x + dir_x, img_y - dir_y), CV_RGB(255, 0, 255));

        GPS::ArrowedLine(img_show, cv::Point(img_x, img_y), cv::Point(img_x + dir_x, img_y - dir_y), CV_RGB(255, 0, 255));

        // cout<<head_motion<<endl<<endl;
        // cout<<roundf(ground_speed * 10)<<endl;

        cv::resize(img_show, img_show, cv::Size(), 0.5, 0.5);

        cv::imshow("2D MAP", img_show);
        cv::waitKey(10);
    }
}


void DataAnalyse::ShowTrace(vector<double*> &data) {
    cv::Mat img_map(2000, 2000, CV_8UC3, cv::Scalar(255, 255, 255));
    cv::Mat img_show;

    int img_x, img_y, img_x_tar, img_y_tar;
    double x, y, head_motion, x_tar, y_tar, stamp;
    double distance_tar, angle_tar, linear_v, angular_v;

    for(vector<double*>::iterator iter=data.begin(); iter!=data.end(); ++iter) {
        stamp = (*iter)[0];
        x = (*iter)[2];
        y = (*iter)[3];
        head_motion = (*iter)[4];
        x_tar = (*iter)[5];
        y_tar = (*iter)[6];
        distance_tar = (*iter)[7];
        angle_tar = (*iter)[8];
        linear_v = (*iter)[9];
        angular_v = (*iter)[10];

        cout<<"stamp: "<<static_cast<long>(stamp)<<endl;
        cout<<"x: "<<x<<endl;
        cout<<"y: "<<y<<endl;
        cout<<"head_motion: "<<head_motion<<endl;
        cout<<"x_tar: "<<x_tar<<endl;
        cout<<"y_tar: "<<y_tar<<endl;
        cout<<"distance_tar: "<<distance_tar<<endl;
        cout<<"angle_tar: "<<angle_tar<<endl;
        cout<<"linear_v: "<<linear_v<<endl;
        cout<<"angular_v: "<<angular_v<<endl<<endl;

        img_x = (int)(roundf(x * 10) + 1000);
        img_y = (int)(- roundf(y * 10) + 1000);

        int dir_x, dir_y, r;
        r = roundf(50);
        dir_x = r * cos(head_motion);
        dir_y = r * sin(head_motion);

        cv::circle(img_map, cv::Point(img_x, img_y), 1, cv::Scalar(0, 0, 0), -1);

        img_show = img_map.clone();


        img_x_tar = (int)(roundf(x_tar * 10) + 1000);
        img_y_tar = (int)(- roundf(y_tar * 10) + 1000);
        cv::circle(img_show, cv::Point(img_x_tar, img_y_tar), 1, cv::Scalar(255, 0, 0), -1);


        GPS::ArrowedLine(img_show, cv::Point(img_x, img_y), cv::Point(img_x + dir_x, img_y - dir_y), CV_RGB(255, 0, 255));


        cv::resize(img_show, img_show, cv::Size(), 0.75, 0.75);

        cv::imshow("2D MAP", img_show);
        cv::waitKey(0);
    }
}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "data_analyse");

    if (strcmp(argv[1], "showmap") == 0){

        int row, i;
        vector<double*> data;

    // const char *file = "/home/luohanjie/Documents/SLAM/Data/gps/d2k3.csv";

        bool flag = DataAnalyse::ReadFile(argv[2], 0, row, data);

        DataAnalyse::ShowMap(data);
        // std::cout << row << std::endl;
    } else if (strcmp(argv[1], "showtrace") == 0) {
        int row, i;
        vector<double*> data;


        bool flag = DataAnalyse::ReadFile(argv[2], 0, row, data);
        cout<<"row:"<<row<<endl;
        DataAnalyse::ShowTrace(data);

    }


    ros::spin();

    return 0;
}
