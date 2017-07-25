# -*- coding: utf-8 -*-
import numpy as np
import cv2
import cv2.cv as cv
import csv

file_name = '/home/luohanjie/Documents/SLAM/Data/align/data_file.txt'
src = []
dst = []

with open(file_name) as f:
    f_csv = csv.reader(f)
    my_csv_data = list(f_csv)
    data_len = len(my_csv_data)
    for i in range(data_len):
        if my_csv_data[i][0] == 'amcl_pose' and my_csv_data[i-1][0] == 'gps_pose':
            src.append([my_csv_data[i-1][2], my_csv_data[i-1][3]])
            dst.append([my_csv_data[i][2], my_csv_data[i][3]])

src = (np.array(src)).astype(np.float32)
dst = (np.array(dst)).astype(np.float32)

rows = src.shape[0]

SRC = cv.CreateMatHeader(rows, 1, cv.CV_32FC2) 
DST = cv.CreateMatHeader(rows, 1, cv.CV_32FC2) 

cv.SetData(SRC, src.tostring(), 8) 
cv.SetData(DST, dst.tostring(), 8) 

TRANS = cv.CreateMat(2, 3, cv.CV_32F) 
cv.EstimateRigidTransform(SRC, DST, TRANS, False) 
trans = np.fromstring(TRANS.tostring(),dtype=np.float32).reshape(2,-1) 
trans = np.vstack((trans, np.array([0.0, 0.0, 1.0])))

print "The transformation matrxi is:"
print trans
print
theta = np.arctan(trans[1, 0] / trans[1, 1])
scalar = trans[1, 0] / np.sin(theta)


print "theta:", theta
print "scalar:", scalar
print "px:", trans[0, 2]
print "py:", trans[1, 2]






 




