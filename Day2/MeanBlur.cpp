#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<bits/stdc++.h>
using namespace std;
using namespace cv;
int main(){
	Mat img=imread("index.jpg",0);
	int i,j,k,l;
	Mat mean_fil(img.rows,img.cols,CV_8UC1,Scalar(255));
	int b=0;
	for(i=1;i<img.rows-1;i++){
		for(j=1;j<img.cols-1;j++){
			for(k=-1;k<=1;k++){
				for(l=-1;l<=1;l++){
					b+=img.at<uchar>(i+k,j+l);
				}
			}
			mean_fil.at<uchar>(i,j)=b/9;
			b=0;
		}
	}
	namedWindow("mean_filter",WINDOW_NORMAL);
	imshow("mean_filter",mean_fil);
	waitKey(0);
}