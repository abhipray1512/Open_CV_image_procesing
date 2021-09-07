#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<bits/stdc++.h>
using namespace std;
using namespace cv;
int main(){
	Mat img=imread("veg.jpg",0);
	int i,j,k,l;
	Mat gauss_fil(img.rows,img.cols,CV_8UC1,Scalar(255));
	int b=0;
	for(i=1;i<img.rows-1;i++){
		for(j=1;j<img.cols-1;j++){
			for(k=-1;k<=1;k++){
				for(l=-1;l<=1;l++){
					if(k==0 && l==0)
						b+=4*img.at<uchar>(i+k,j+l);
					else if(k==0 || l==0)
						b+=2*img.at<uchar>(i+k,j+l);
					else 
						b+=img.at<uchar>(i+k,j+l);
				}
			}
			gauss_fil.at<uchar>(i,j)=b/16;
			b=0;
		}
	}
	namedWindow("gaussian_filter",WINDOW_NORMAL);
	imshow("gaussian_filter",gauss_fil);
	waitKey(0);
}
