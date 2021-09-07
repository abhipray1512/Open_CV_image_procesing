#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace std;
using namespace cv;
int main(){
	Mat img=imread("fruits.png",1);
	Mat a(4*img.rows,4*img.cols,CV_8UC3,Scalar(255,255,255));
	int i,j,k=0,l=0,p,q;
	for(i=0;i<img.rows;i++){
		for(j=0;j<img.cols;j++){
			for(p=0;p<4;p++){
				for(q=0;q<4;q++){
					a.at<Vec3b>(k+p,l+q)=img.at<Vec3b>(i,j);
				}
			}
			l+=4;
		}
		l=0;
		k+=4;
	}
	Mat b(a.rows/3,a.cols/3,CV_8UC3,Scalar(0,0,0));
	k=0;
	l=0;
	for(i=0;i<a.rows/3;i++){
		for(j=0;j<a.cols/3;j++){
			for(p=0;p<3;p++){
				for(q=0;q<3;q++){
					b.at<Vec3b>(i,j)[0]+=a.at<Vec3b>(k+p,l+q)[0]/16;
					b.at<Vec3b>(i,j)[1]+=a.at<Vec3b>(k+p,l+q)[1]/16;
					b.at<Vec3b>(i,j)[2]+=a.at<Vec3b>(k+p,l+q)[2]/16;
				}
			}
			l+=3;
		}
		l=0;
		k+=3;
	}
	namedWindow("window",WINDOW_AUTOSIZE);
	imshow("window",b);
	waitKey(5000);
	return 0;
}
