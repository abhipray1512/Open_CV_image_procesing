#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;
int main(){
	Mat img=imread("fruits.png",1);
	Mat a(3*img.rows,3*img.cols,CV_8UC3,Scalar(255,255,255));
	int i,j;
	int d_angle=0;
	namedWindow("window",WINDOW_NORMAL);
	createTrackbar("Angle","window",&d_angle,360);
	double angle;
	int p,q;
	while(1){
		angle=d_angle*3.14/180;
		for(i=img.rows;i<2*img.rows;i++){
			for(j=img.cols;j<2*img.cols;j++){
				p=3*img.rows/2+(i-3*img.rows/2)*cos(angle)+(j-3*img.cols/2)*sin(angle);
				q=3*img.cols/2-(i-3*img.rows/2)*sin(angle)+(j-3*img.cols/2)*cos(angle);
				a.at<Vec3b>(p,q)=img.at<Vec3b>(i-img.rows,j-img.cols);
			}
		}
		imshow("window",a);
		waitKey(1);
		a.setTo(Scalar(255,255,255));
	}
	return 0;	
}