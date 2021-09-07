#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<bits/stdc++.h>
using namespace std;
using namespace cv;
int main(){
	Mat img=imread("A5.png",0);
	int i,j,theta;
	for(i=0;i<img.rows;i++){
		for(j=0;j<img.cols;j++){
			if(img.at<uchar>(i,j)>127){
				img.at<uchar>(i,j)=255;
			}
			else
				img.at<uchar>(i,j)=0;
		}
	}
	float r;
	int height=2*sqrt((img.rows)*(img.rows)+(img.cols)*(img.cols));
	Mat a(height,180,CV_8UC1,Scalar(0));
	for(i=0;i<img.rows;i++){
		for(j=0;j<img.cols;j++){
			if(img.at<uchar>(i,j)==255){
				for(theta=0;theta<180;theta++){
					r=i*cos(theta*3.14/180)+j*sin(theta*3.14/180);
					if(a.at<uchar>(height/2+r,theta)<255);
						a.at<uchar>(height/2+r,theta)+=2;
				}
			}
		}
	}
	int th=245,l,k;
	namedWindow("Hugg",WINDOW_NORMAL);
	createTrackbar("th","Hugg",&th,255);
	while(1){
		int count=0;
		for(i=0;i<a.rows;i++){
			for(j=0;j<a.cols;j++){
				if(a.at<uchar>(i,j)>th){
					for(k=-2;k<=2;k++){
						for(l=-2;l<=2;l++){
							if(a.at<uchar>(i,j)<a.at<uchar>(i+k,j+l) && j+l>=0 && j+l<a.cols && i+k>=0 && i+k<a.rows);
								break;
						}
					}
					if(l==3 && k==3)
						count++;
				}
			}
		}
		cout<<count<<endl;
		imshow("Hugg",a);
		waitKey(1);
	}
	return 0;
}