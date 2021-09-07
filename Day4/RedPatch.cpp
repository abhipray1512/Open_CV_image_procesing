#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<bits/stdc++.h>
using namespace std;
using namespace cv;
int main(){
	VideoCapture cap(0);
	if(!cap.isOpened())
		return -1;
	int rmin=0,bmax=119,gmax=226,rmax=251,i,j;
	namedWindow("window",WINDOW_NORMAL);
	createTrackbar("rmin","window",&rmin,255);
	createTrackbar("rmax","window",&rmax,255);
	createTrackbar("bmax","window",&bmax,255);
	createTrackbar("gmax","window",&gmax,255);
	while(1){
		Mat img;
		cap>>img;
		for(i=0;i<img.rows;i++){
			for(j=0;j<img.cols;j++){
				if((img.at<Vec3b>(i,j)[1] >rmin && img.at<Vec3b>(i,j)[1] <rmax) || img.at<Vec3b>(i,j)[0] <bmax || img.at<Vec3b>(i,j)[2] <gmax){
					img.at<Vec3b>(i,j)={0,0,0};
				}
				else
					img.at<Vec3b>(i,j)={255,255,255};
			}
		}
		Mat img2(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
		int k,l;
		for(i=0;i<img.rows;i++){
			for(j=0;j<img.cols;j++){
				img2.at<uchar>(i,j)=img.at<uchar>(i,j);
				for(k=-1;img.at<uchar>(i,j)==255 && k<=1;k++){
					for(l=-1;l<=1;l++){
						if(i+k>=0 && i+k<img.rows && j+l>=0 && j+l<img.cols && img.at<uchar>(i+k,j+l)==0){
							img2.at<uchar>(i,j)=0;
						}
					}
				}
			}
		}
		Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
		Canny(img,img1,50,100,5);
		vector<vector<Point>>contours;
		vector<Vec4i>hierarchy;
		findContours(img1,contours,hierarchy,CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
		int max=0,max_index;
		for(i=0;i<contours.size();i++){
			if(contourArea(contours[i])>max){
				max=contourArea(contours[i]);
				max_index=i;
			}
		}
		drawContours(img1,contours,-1,255,2,8);
		namedWindow("window2",WINDOW_NORMAL);
		imshow("window2",img1);
		waitKey(1);
		imshow("window",img);
		waitKey(1);
		if(contours.empty()){
			continue;
		}
		Moments m;
		int center=img.cols/2;
		i=max_index;
		m=moments(contours[i],true);
		center=(int)(m.m10/m.m00);// only x-coordinate of center
		float area=contourArea(contours[i]);
		int screen_area=img.cols*img.rows;
		if(area<screen_area/20){
			cout<<"Forward"<<endl;
		}
		if(area>screen_area/10){
			cout<<"Backward"<<endl;
		}
		if(area>screen_area/20 && area<screen_area/10){
			if(center>2*img.cols/3){
				cout<<"Left"<<endl;
			}
			else if(center<img.cols/3){
				cout<<"Right"<<endl;
			}
		}
	}
	return 0;
}
