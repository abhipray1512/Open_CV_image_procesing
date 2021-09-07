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
queue<point>q;
void bfs(point k,Mat *a){
	q.push(k);
	while(!q.empty()){
		point p=q.front();
		a->at<uchar>(p.x,p.y)=0;
		if(a->at<uchar>(p.x,p.y+1)>127 && p.y>=0 && p.y<a->cols && p.x<a->rows && p.x>=0){
			point temp;
			temp.x=p.x;
			temp.y=p.y+1;
			a->at<uchar>(temp.x,temp.y)=0;
			namedWindow("window",WINDOW_NORMAL);
			imshow("window",*a);
			waitKey(1);
			q.push(temp);
		}
		if(a->at<uchar>(p.x+1,p.y)>127 && p.y>=0 && p.y<a->cols && p.x<a->rows && p.x>=0){
			point temp;
			temp.x=p.x+1;
			temp.y=p.y;
			a->at<uchar>(temp.x,temp.y)=0;
			namedWindow("window",WINDOW_NORMAL);
			imshow("window",*a);
			waitKey(1);
			q.push(temp);
		}
		if(a->at<uchar>(p.x,p.y-1)>127 && p.y>=0 && p.y<a->cols && p.x<a->rows && p.x>=0){
			point temp;
			temp.x=p.x;
			temp.y=p.y-1;
			a->at<uchar>(temp.x,temp.y)=0;
			namedWindow("window",WINDOW_NORMAL);
			imshow("window",*a);
			waitKey(1);
			q.push(temp);
		}
		if(a->at<uchar>(p.x-1,p.y)>127 && p.y>=0 && p.y<a->cols && p.x<a->rows && p.x>=0){
			point temp;
			temp.x=p.x-1;
			temp.y=p.y;
			a->at<uchar>(temp.x,temp.y)=0;
			namedWindow("window",WINDOW_NORMAL);
			imshow("window",*a);
			waitKey(1);
			q.push(temp);
		}
		if(a->at<uchar>(p.x+1,p.y+1)>127 && p.y>=0 && p.y<a->cols && p.x<a->rows && p.x>=0){
			point temp;
			temp.x=p.x+1;
			temp.y=p.y+1;
			a->at<uchar>(temp.x,temp.y)=0;
			namedWindow("window",WINDOW_NORMAL);
			imshow("window",*a);
			waitKey(1);
			q.push(temp);
		}
		if(a->at<uchar>(p.x-1,p.y+1)>127 && p.y>=0 && p.y<a->cols && p.x<a->rows && p.x>=0){
			point temp;
			temp.x=p.x-1;
			temp.y=p.y+1;
			a->at<uchar>(temp.x,temp.y)=0;
			namedWindow("window",WINDOW_NORMAL);
			imshow("window",*a);
			waitKey(1);
			q.push(temp);
		}
		if(a->at<uchar>(p.x-1,p.y-1)>127 && p.y>=0 && p.y<a->cols && p.x<a->rows && p.x>=0){
			point temp;
			temp.x=p.x-1;
			temp.y=p.y-1;
			a->at<uchar>(temp.x,temp.y)=0;
			namedWindow("window",WINDOW_NORMAL);
			imshow("window",*a);
			waitKey(1);
			q.push(temp);
		}
		if(a->at<uchar>(p.x+1,p.y-1)>127 && p.y>=0 && p.y<a->cols && p.x<a->rows && p.x>=0){
			point temp;
			temp.x=p.x+1;
			temp.y=p.y-1;
			a->at<uchar>(temp.x,temp.y)=0;
			namedWindow("window",WINDOW_NORMAL);
			imshow("window",*a);
			waitKey(1);
			q.push(temp);
		}
		q.pop();
	}
	return;
}
int main(){
	Mat img=imread("Binary1.png",0);
	int i,j,count=0;
	point p;
	for(i=0;i<img.rows;i++){
		for(j=0;j<img.cols;j++){
			p.x=i;
			p.y=j;
			if(img.at<uchar>(i,j)>127){
				bfs(p,&img);
				cout<<p.x<<"  "<<p.y<<endl;
				count++;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}