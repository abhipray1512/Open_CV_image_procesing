#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace std;
using namespace cv;
int main(){
	Mat image;
	image=imread("fruits.png",IMREAD_COLOR);
	Mat grey(516,625,CV_8UC1,Scalar(0));
	int i,j;
	for(i=0;i<516;i++){
		for(j=0;j<625;j++){
			grey.at<uchar>(i,j)=0.3*image.at<Vec3b>(i,j)[0]+0.59*image.at<Vec3b>(i,j)[1]+0.11*image.at<Vec3b>(i,j)[2];
		}
	}
	namedWindow("window",WINDOW_NORMAL);
	imshow("window",grey);
	waitKey(0);
}