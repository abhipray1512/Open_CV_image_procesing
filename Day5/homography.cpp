#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include<bits/stdc++.h>
using namespace std;
using namespace cv;
int main(){
	Mat img=imread("homo.jpg",0);
	Mat dest;
	Mat dstimg(300,400,CV_8UC3,Scalar(0,0,0));
	vector<Point2f>srcpts;
	vector<Point2f> dstpts;
	srcpts.push_back(Point2f(203,163));
    srcpts.push_back(Point2f(342,238));
    srcpts.push_back(Point2f(204,434));
    srcpts.push_back(Point2f(45,303));
    dstpts.push_back(Point2f(0,0));
    dstpts.push_back(Point2f(99,0));
    dstpts.push_back(Point2f(99,99));
    dstpts.push_back(Point2f(0,99));
    Mat h=findHomography(srcpts,dstpts);
    warpPerspective(img,dstimg,h,dstimg.size());
    namedWindow("window",WINDOW_NORMAL);
    namedWindow("window1",WINDOW_NORMAL);
    imshow("window",img);
    waitKey(5000);
    imshow("window1",dstimg);
    waitKey(0);
    return 0;
}