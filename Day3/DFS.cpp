#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<bits/stdc++.h>
using namespace std;
using namespace cv;
struct point{
	int x;
	int y;
};
void dfs(point p,Mat *a){
	if(a->at<uchar>(p.x,p.y+1)>127 && p.y>=0 && p.y<a->cols && p.x<a->rows && p.x>=0){
		point temp;
		temp.x=p.x;
		temp.y=p.y+1;
		a->at<uchar>(p.x,p.y)=0;
		namedWindow("window",WINDOW_NORMAL);
		imshow("window",*a);
		waitKey(1);
		dfs(temp,a);
	}
	if(a->at<uchar>(p.x+1,p.y)>127 && p.y>=0 && p.y<a->cols && p.x<a->rows && p.x>=0){
		point temp;
		temp.x=p.x+1;
		temp.y=p.y;
		a->at<uchar>(p.x,p.y)=0;
		namedWindow("window",WINDOW_NORMAL);
		imshow("window",*a);
		waitKey(1);
		dfs(temp,a);
	}
	if(a->at<uchar>(p.x,p.y-1)>127 && p.y>=0 && p.y<a->cols && p.x<a->rows && p.x>=0){
		point temp;
		temp.x=p.x;
		temp.y=p.y-1;
		a->at<uchar>(p.x,p.y)=0;
		namedWindow("window",WINDOW_NORMAL);
		imshow("window",*a);
		waitKey(1);
		dfs(temp,a);
	}
	if(a->at<uchar>(p.x-1,p.y)>127 && p.y>=0 && p.y<a->cols && p.x<a->rows && p.x>=0){
		point temp;
		temp.x=p.x-1;
		temp.y=p.y;
		a->at<uchar>(p.x,p.y)=0;
		namedWindow("window",WINDOW_NORMAL);
		imshow("window",*a);
		waitKey(1);
		dfs(temp,a);
	}
	if(a->at<uchar>(p.x+1,p.y+1)>127 && p.y>=0 && p.y<a->cols && p.x<a->rows && p.x>=0){
		point temp;
		temp.x=p.x+1;
		temp.y=p.y+1;
		a->at<uchar>(p.x,p.y)=0;
		namedWindow("window",WINDOW_NORMAL);
		imshow("window",*a);
		waitKey(1);
		dfs(temp,a);
	}
	if(a->at<uchar>(p.x-1,p.y+1)>127 && p.y>=0 && p.y<a->cols && p.x<a->rows && p.x>=0){
		point temp;
		temp.x=p.x-1;
		temp.y=p.y+1;
		a->at<uchar>(p.x,p.y)=0;
		namedWindow("window",WINDOW_NORMAL);
		imshow("window",*a);
		waitKey(1);
		dfs(temp,a);
	}
	if(a->at<uchar>(p.x-1,p.y-1)>127 && p.y>=0 && p.y<a->cols && p.x<a->rows && p.x>=0){
		point temp;
		temp.x=p.x-1;
		temp.y=p.y-1;
		a->at<uchar>(p.x,p.y)=0;
		namedWindow("window",WINDOW_NORMAL);
		imshow("window",*a);
		waitKey(1);
		dfs(temp,a);
	}
	if(a->at<uchar>(p.x+1,p.y-1)>127 && p.y>=0 && p.y<a->cols && p.x<a->rows && p.x>=0){
		point temp;
		temp.x=p.x+1;
		temp.y=p.y-1;
		a->at<uchar>(p.x,p.y)=0;
		namedWindow("window",WINDOW_NORMAL);
		imshow("window",*a);
		waitKey(1);
		dfs(temp,a);
	}
	a->at<uchar>(p.x,p.y)=0;
	return;
}
int main(){
	Mat img=imread("binary3.jpg",0);
	int i,j,count=0;
	point p;
	for(i=0;i<img.rows;i++){
		for(j=0;j<img.cols;j++){
			p.x=i;
			p.y=j;
			if(img.at<uchar>(i,j)>127){
				dfs(p,&img);
				cout<<p.x<<"  "<<p.y<<endl;
				count++;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}
