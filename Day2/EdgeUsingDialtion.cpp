#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace std;
using namespace cv;
int main(){
	Mat img=imread("erosion4.png",0);
	Mat b(img.rows,img.cols,CV_8UC1,Scalar(0));
	Mat c(img.rows,img.cols,CV_8UC1,Scalar(0));
	Mat d(img.rows,img.cols,CV_8UC1,Scalar(0));
	Mat e(img.rows,img.cols,CV_8UC1,Scalar(0));
	Mat g(img.rows,img.cols,CV_8UC1,Scalar(0));
	Mat f(img.rows,img.cols,CV_8UC1,Scalar(255));
	int i,j,k=0,l=0;
	for(i=0;i<img.rows;i++){
		for(j=0;j<img.cols;j++){
			b.at<uchar>(i,j)=img.at<uchar>(i,j);
			for(k=-1;img.at<uchar>(i,j)==255 && k<=1;k++){
				for(l=-1;l<=1;l++){
					if(i+k>=0 && i+k<img.rows && j+l>=0 && j+l<img.cols && img.at<uchar>(i+k,j+l)==0){
						b.at<uchar>(i,j)=0;
					}
				}
			}
		}
	}
	for(i=0;i<img.rows;i++){
		for(j=0;j<img.cols;j++){
			c.at<uchar>(i,j)=b.at<uchar>(i,j);
			for(k=-1;b.at<uchar>(i,j)==0 && k<=1;k++){
				for(l=-1;l<=1;l++){
					if(i+k>=0 && i+k<b.rows && j+l>=0 && j+l<b.cols && b.at<uchar>(i+k,j+l)==255){
						c.at<uchar>(i,j)=255;
					}
				}
			}
		}
	}
	for(i=0;i<img.rows;i++){
		for(j=0;j<img.cols;j++){
			d.at<uchar>(i,j)=c.at<uchar>(i,j);
			for(k=-1;c.at<uchar>(i,j)==0 && k<=1;k++){
				for(l=-1;l<=1;l++){
					if(i+k>=0 && i+k<c.rows && j+l>=0 && j+l<c.cols && c.at<uchar>(i+k,j+l)==255){
						d.at<uchar>(i,j)=255;
					}
				}
			}
		}
	}
	for(i=0;i<img.rows;i++){
		for(j=0;j<img.cols;j++){
			e.at<uchar>(i,j)=d.at<uchar>(i,j);
			for(k=-1;d.at<uchar>(i,j)==0 && k<=1;k++){
				for(l=-1;l<=1;l++){
					if(i+k>=0 && i+k<c.rows && j+l>=0 && j+l<c.cols && d.at<uchar>(i+k,j+l)==255){
						e.at<uchar>(i,j)=255;
					}
				}
			}
		}
	}
	for(i=0;i<img.rows;i++){
		for(j=0;j<img.cols;j++){
			g.at<uchar>(i,j)=e.at<uchar>(i,j);
			for(k=-1;e.at<uchar>(i,j)==0 && k<=1;k++){
				for(l=-1;l<=1;l++){
					if(i+k>=0 && i+k<c.rows && j+l>=0 && j+l<c.cols && e.at<uchar>(i+k,j+l)==255){
						g.at<uchar>(i,j)=255;
					}
				}
			}
		}
	}
	for(i=0;i<img.rows;i++){
		for(j=0;j<img.cols;j++){
			f.at<uchar>(i,j)=g.at<uchar>(i,j)-d.at<uchar>(i,j);
		}
	}
	namedWindow("window",WINDOW_NORMAL);
	imshow("window",d);
	waitKey(0);
}