#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
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
	Mat dst;
	split(image, image_new);//b g r
	swap(image_new[0], image_new[2]); // swap b and r
	merge(image_new, dst);// remerge
	imshow("Imageinput", image);
	imshow("Imageres", dst);
	waitKey(0);
	return 0;
}