#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace std;
using namespace cv;
int main(){
	Mat a(100,100,CV_8UC1,Scalar(0));
	int i,j;
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			if((i-49)*(i-49)+(j-49)*(j-49)<=625){
				a.at<uchar>(i,j)=255;
			}
		}
	}
	namedWindow("window",WINDOW_NORMAL);
	imshow("window",a);
	waitKey(5000);
}