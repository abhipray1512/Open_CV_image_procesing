#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<bits/stdc++.h>
using namespace std;
using namespace cv;
int main(){
	Mat img=imread("lena_color.jpg",0);
	Mat Temp(95,80,CV_8UC1,Scalar(255));
	int i,j,k,l;
	for(i=0;i<95;i++){
		for(j=0;j<80;j++){
			Temp.at<uchar>(i,j)=img.at<uchar>(i,j);
		}
	}
	int thre=0,min=INT_MAX;
	namedWindow("window",WINDOW_NORMAL);
	createTrackbar("Thresold","window",&thre,500);
	for(i=0;i<img.rows;i++){
		for(j=0;j<img.cols;j++){
			int R=0,p;
			for(k=0;k<Temp.rows;k++){
				for(l=0;l<Temp.cols;l++){
					p=Temp.at<uchar>(k,l)-img.at<uchar>(k+i,l+j);
					R+=p*p;		
					if(R<min)
						min=R;		
				}
			}
		}
	}
	while(1){
		if(min<thre){
			cout<<"Yes"<<endl;
		}
		else
			cout<<"No"<<endl;
		imshow("window",img);
		waitKey(1);
	}
	return 0;	
}