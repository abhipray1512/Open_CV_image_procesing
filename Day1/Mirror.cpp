#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace std;
using namespace cv;
int main(){
	Mat img=imread("fruits.png",1);
	Mat a(img.rows,img.cols,CV_8UC3,Scalar(255,255,255));
	int i,j;
	for(i=0;i<img.rows;i++){
		for(j=0;j<img.cols;j++){
			a.at<Vec3b>(i,j)=img.at<Vec3b>(i,img.cols-j);
		}
	}
	namedWindow("window1",WINDOW_NORMAL);
	imshow("window1",a);
	waitKey(0);
}