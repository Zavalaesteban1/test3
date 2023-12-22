#include "opencv2/opencv.hpp"
#include<iostream>
using namespace cv;
using namespace std;


void print()
{
	Mat image, imgHSV, mask;
	int hmin = 0, smin = 110, vmin = 13;
	int hmax = 19, smax = 240, vmax = 245;
	namedWindow("testWindow");
	VideoCapture cap(0);
	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);
	if (!cap.isOpened())
    {
		cout << "Cannot open camera" << endl;
    }
	while (true)
    {
		cap >> image;
		imshow("testWindow", image);
		cvtColor(image, imgHSV, COLOR_BGR2HSV); //input img, output img, colorspace

		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		inRange(imgHSV, lower, upper, mask);
        
		imshow("HSV Image", imgHSV);
		imshow("Mask", mask);
		waitKey(1);
	}
}


int main()
{

    print();

    return 0;
}