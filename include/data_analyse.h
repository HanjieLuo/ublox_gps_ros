#ifndef DATAANALYSE_H
#define DATAANALYSE_H

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <math.h>

using namespace std;

class DataAnalyse {
public:
    DataAnalyse();
    ~DataAnalyse();

    static bool ReadFile(const char *file, int col, int index, int &row, vector<double*> &data);
    static void ShowMap(vector<double*> &data);
private:

};

#endif