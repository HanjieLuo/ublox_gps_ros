#include "data_analyse.h"


DataAnalyse::DataAnalyse(void) {

}

DataAnalyse::~DataAnalyse() {

}

bool DataAnalyse::ReadFile(const char *file, int col, int index, int &row, vector<double*> &data) {
    fstream fin(file);

    if (!fin.is_open()) {
        return false;
    }

    char buffer[1024] = {};
    int i = 0, k;
    double *tmp;
    while ( fin.getline(buffer, 1024) ) {
        if (i < index) {
            i++;
            continue;
        }

        tmp = new double[col];

        tmp[0] = std::atof(strtok(buffer, ","));

        // cout<<tmp[0]<<",";

        for (k = 1; k < col; k ++) {
            tmp[k] = std::atof(strtok(NULL, ","));
            // cout<<tmp[k]<<",";
        }

        // cout<<endl<<endl;

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
    cv::Mat img_map(1600, 1600, CV_8UC3, cv::Scalar(255, 255, 255));
    cv::Mat img_show;
    for(vector<double*>::iterator iter=data.begin(); iter!=data.end(); ++iter) {
        x = (*iter)[4];
        y = (*iter)[5];
        // x = (*iter)[5];
        // y = (*iter)[6];
        head_motion = (*iter)[11];
        ground_speed = (*iter)[12];
        t = (*iter)[0];
        // ground_speed = (*iter)[12];
        cout<<"stamp: "<<static_cast<long>(t)<<endl;
        cout<<"x: "<<x<<endl;
        cout<<"y: "<<y<<endl;
        cout<<"head_motion: "<<head_motion<<endl;
        cout<<"ground_speed: "<<ground_speed<<endl<<endl;;

        img_x = (int)(roundf(x * 10) + 800);
        img_y = (int)(- roundf(y * 10) + 800);

        // head_motion = (90 - head_motion);
        // head_motion = fmod(head_motion + 180, 360);
        // if (head_motion < 0)
        //     head_motion += 360;
        // head_motion -= 180;
        // head_motion = head_motion * M_PI / 180;

        head_motion = 90 - head_motion;
        if (head_motion < -180) head_motion += 360;
        head_motion *= 0.01745329251;

        int dir_x, dir_y, r;
        r = roundf(ground_speed * 100);
        dir_x = r * cos(head_motion);
        dir_y = r * sin(head_motion);

        // cout<<head_motion<<endl;
        // cout<<dir_x<<", "<<dir_y<<endl;

        cv::circle(img_map, cv::Point(img_x, img_y), 1, cv::Scalar(0, 0, 0), -1);

        img_show = img_map.clone();

        cv::arrowedLine(img_show, cv::Point(img_x, img_y), cv::Point(img_x + dir_x, img_y - dir_y), CV_RGB(255, 0, 255));




        // cout<<head_motion<<endl<<endl;
        // cout<<roundf(ground_speed * 10)<<endl;

        cv::resize(img_show, img_show, cv::Size(), 0.5, 0.5);

        cv::imshow("2D MAP", img_show);
        cv::waitKey(10);
    }
}



int main(int argc, char **argv)
{

    ros::init(argc, argv, "data_analyse");

    int row, i;
    vector<double*> data;

    // const char *file = "/home/luohanjie/Documents/SLAM/Data/gps/d2k3.csv";

    bool flag = DataAnalyse::ReadFile(argv[1], 13, 0, row, data);

    DataAnalyse::ShowMap(data);



    std::cout << row << std::endl;


    ros::spin();

    return 0;
}