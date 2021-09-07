#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<bits/stdc++.h>
using namespace std;
using namespace cv;
int main(){
	Mat img=imread("lowcontrast.PNG",0);
	int i,j,hist[256]={0};
	for(i=0;i<img.rows;i++){
		for(j=0;j<img.cols;j++){
			hist[img.at<uchar>(i,j)]++;
		}
	}
	int max=0;
	for(i=0;i<256;i++){
		if(max<hist[i]){
			max=hist[i];
		}
	}
    Mat hist_image(max,1024,CV_8UC1,Scalar(255));
    for(i=0;i<1024;i++){
    	for(j=0;j<hist[i/4];j++){
    		hist_image.at<uchar>(max-j,i)=0;
    	}
    }
    namedWindow("Histogram",WINDOW_NORMAL);
    imshow("Histogram",hist_image);
    waitKey(0);
	return 0;
}