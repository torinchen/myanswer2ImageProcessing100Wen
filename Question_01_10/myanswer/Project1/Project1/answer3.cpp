#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<vector>

using namespace std;
using namespace cv;
int main(void) {
	Mat image = imread("D:/imageprocess100/ImageProcessing100Wen/Question_01_10/imori.jpg");
	if (image.empty()) {
		cout << "Loading image failed£¡" << endl;
		waitKey(0);
		return -1;
	}
	vector<Mat> image_new;
	Mat dst1(image.rows, image.cols, CV_8UC1);
	Mat dst2;
	int index = 0;
	split(image, image_new);//b g r
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			index = j * image.rows + j;
			if ((0.2126*(float)image_new[2].at<uchar>(i, j) + 0.7152*(float)image_new[1].at<uchar>(i, j) + 0.0722*(float)image_new[0].at<uchar>(i, j)) > 128)
			{
				dst1.at<uchar>(i, j) = 255;
			}
			else
			{
				dst1.at<uchar>(i, j) = 0;
			}
			
		}

	}
	dst2 = 0.2126*image_new[2] + 0.7152*image_new[1] + 0.0722*image_new[0];
	dst2 = (dst2 > 128) * 255;
	imshow("Imageinput", image);
	imshow("Imageres1", dst1);
	imshow("Imageres2", dst2-dst1);
	waitKey(0);
	return 0;
}