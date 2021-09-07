
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace std;
using namespace cv;
int main()
{

	Mat img=imread("fruits.png",1); //imread is a function to read the image in the given format. 0 for greyscale. 1 for colored.
		//the image is stored in Mat img
	Mat a(img.rows,img.cols,CV_8UC1,Scalar(0));

	int i,j,rmin=0,bmin=0,gmin=0,rmax=255,bmax=255,gmax=255;
	
	namedWindow("window1",WINDOW_NORMAL);
	createTrackbar("rmin","window1",&rmin,255);
	createTrackbar("rmax","window1",&rmax,255);
	createTrackbar("bmin","window1",&bmin,255);
	createTrackbar("bmax","window1",&bmax,255);
	createTrackbar("gmin","window1",&gmin,255);
	createTrackbar("gmax","window1",&gmax,255);

	while(1)
	{for(i=0;i<img.rows;++i)
		{
			for(j=0;j<img.cols;++j)
			{
				if(img.at<Vec3b>(i,j)[0]>=bmin && img.at<Vec3b>(i,j)[1]>=gmin && img.at<Vec3b>(i,j)[2]>=rmin && img.at<Vec3b>(i,j)[0]<=bmax && img.at<Vec3b>(i,j)[1]<=gmax && img.at<Vec3b>(i,j)[2]<=rmax)
				a.at<uchar>(i,j) = 255;
				else
					a.at<uchar>(i,j) = 0;

			}
		}


		imshow("window1",a); //showing image
		waitKey(1);

	}
}