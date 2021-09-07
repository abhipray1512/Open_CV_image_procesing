#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<bits/stdc++.h>
using namespace std;
using namespace cv;
int main(){
	Mat img=imread("rubik.jpg",0);
	int i,j,sxT=600,syT=600,szT=600,k,l;
	namedWindow("window",WINDOW_NORMAL);
	createTrackbar("Sx Threesold","window",&sxT,600);
	createTrackbar("Sy Threesold","window",&syT,600);
	createTrackbar("Diagonal detection Threesold","window",&szT,600);
	while(1){
		Mat a(img.rows,img.cols,CV_8UC1,Scalar(255));
		for(i=1;i<img.rows-1;i++){
			for(j=1;j<img.cols-1;j++){
				int sx=0,sy=0,sz=0;
				for(k=-1;k<=1;k++){
					for(l=-1;l<=1;l++){
						if(l==0){
							sx+=0;
						}
						else if(k==0 && l==-1){
							sx-=2*img.at<uchar>(i+k,j+l);
						}
						else if(k==0 && l==1){
							sx+=2*img.at<uchar>(i+k,j+l);
						}
						else if(l==1){
							sx+=img.at<uchar>(i+k,j+l);
						}
						else{
							sx-=img.at<uchar>(i+k,j+l);
						}
						if(k==0){
							sy+=0;
						}
						else if(l==0 && k==-1){
							sy-=2*img.at<uchar>(i+k,j+l);
						}
						else if(l==0 && k==1){
							sy+=2*img.at<uchar>(i+k,j+l);
						}
						else if(k==1){
							sy+=img.at<uchar>(i+k,j+l);
						}
						else{
							sy-=img.at<uchar>(i+k,j+l);
						}
					}
				}
				sz=sqrt(sx*sx+sy*sy);
				if(sx>sxT || sy>syT || sz>szT){
					a.at<uchar>(i,j)=0;
				}
			}
		}
		imshow("window",a);
		waitKey(1);
	}
}