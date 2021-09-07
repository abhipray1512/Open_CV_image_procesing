#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace std;
using namespace cv;
int main(){
	Mat a(720,720,CV_8UC3,Scalar(0,0,255));
	int i,j;
	for(i=40;i<680;i++){
		for(j=40;j<680;j++){
			if((i-40)%160<80 && (j-40)%160<80){
				a.at<Vec3b>(i,j)={255,255,255};
			}
			else if((i-40)%160>=80 && (j-40)%160>=80){
				a.at<Vec3b>(i,j)={255,255,255};
			}
			else if((i-40)%160<80 && (j-40)%160>=80){
				a.at<Vec3b>(i,j)={0,0,0};
			}
			else if((i-40)%160>=80 && (j-40)%160<80){
				a.at<Vec3b>(i,j)={0,0,0};
			}
		}
	}
	namedWindow("window1",WINDOW_NORMAL);
	imshow("window1",a);
	waitKey(5000);
}