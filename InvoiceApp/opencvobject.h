#ifndef OPENCVOBJECT_H
#define OPENCVOBJECT_H

#include <QObject>
#include <stdio.h>
#include<iostream>
#include<vector>
#include <atlstr.h>
#include <Windows.h>
#include <fstream>
#include <iterator>
#include <string>
#include <time.h>
#include <QDate>
#include <QDir>
#include <QFile>
/*************OpenCV**************/
//#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/calib3d/calib3d.hpp>
//#include <opencv2/imgproc/types_c.h>
//#include <opencv2/core/core_c.h>
#include "opencv2/opencv.hpp"


using namespace std;
using namespace cv;

class opencvObject : public QObject
{
    Q_OBJECT

public:
    explicit opencvObject(QObject *parent = 0);
    int reorder_point(std::vector<cv::Point> &keypoints, bool xorder);
    void  photoProcess(QString path);
    Mat myRotateAntiClockWise90(Mat src);
    Mat matRotateClockWise270(Mat src);
    Mat matRotateClockWise180(Mat src);
    Mat matRotateClockWise90(Mat src);
};


static bool comp_x(const cv::Point &a, const cv::Point &b)
{
    return a.x<b.x;
}

static bool comp_y(const cv::Point &a, const cv::Point &b)
{
    return a.y<b.y;
}



#endif // OPENCVOBJECT_H
