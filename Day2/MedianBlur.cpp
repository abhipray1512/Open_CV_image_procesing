#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<bits/stdc++.h>
using namespace std;
using namespace cv;
int main(){
	Mat img=imread("veg.jpg",0);
	int i,j,k,l;
	Mat med_fil(img.rows,img.cols,CV_8UC1,Scalar(255));
	int B[9],p;
	for(i=1;i<img.rows-1;i++){
		for(j=1;j<img.cols-1;j++){
			p=0;
			for(k=-1;k<=1;k++){
				for(l=-1;l<=1;l++){
					B[p]=img.at<uchar>(i+k,j+l);
					p++;
				}
			}
			sort(B,B+9);
			med_fil.at<uchar>(i,j)=B[4];
		}
	}
	namedWindow("median_filter",WINDOW_NORMAL);
	imshow("median_filter",med_fil);
	waitKey(0);
}