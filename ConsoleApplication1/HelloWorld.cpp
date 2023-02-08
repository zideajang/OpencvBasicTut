#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

int main()
{

	//读取文件
	//cout << "hello opencv" << endl;
	string image_path1 = "golang.jpg";
	string image_path2 = "c_programming.png";

	cv::Mat golang_cover = cv::imread(image_path1, cv::IMREAD_COLOR);
	cv::Mat c_cover = cv::imread(image_path2, cv::IMREAD_COLOR);

	if (golang_cover.empty()) {
		cout << "Could not read the image " << image_path1 << endl;
		return 1;
	}

	cv::resize(golang_cover, golang_cover, cv::Size(300, 300));

	//对图像进行旋转
	cv::rotate(golang_cover, golang_cover,cv::ROTATE_90_COUNTERCLOCKWISE);

	//显示文件
	for (int i = 0; i < golang_cover.rows; i++)
	{
		for (int j = 0; j < golang_cover.cols; j++) {
			cv::Vec3b bgrPixel = golang_cover.at<cv::Vec3b>(i, j);
			//cout << "bgr: " << bgrPixel << endl;

			unsigned char grayScale = (bgrPixel[2] + bgrPixel[1] + bgrPixel[0]) / 3;
			golang_cover.at<cv::Vec3b>(i, j) = { grayScale,grayScale,grayScale };

			cv::Vec3b grayPixel = golang_cover.at<cv::Vec3b>(i, j);
			//cout << "gray: " << bgrPixel << endl;
		}
	}


	cv::imshow("Display window", golang_cover);
	int k = cv::waitKey(0);
	if (k == 's') {
		cv::imwrite("temp.png", golang_cover);
	}

	return 0;
}