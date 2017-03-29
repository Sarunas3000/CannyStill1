#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>
#include<conio.h>


int main() {

	cv::Mat imgOriginal;        // input image
	cv::Mat imgGrayscale;       // grayscale of input image
	cv::Mat imgBlurred;         // intermediate blured image
	cv::Mat imgCanny;           // Canny edge image

	imgOriginal = cv::imread("image.jpg");          // open image

	if (imgOriginal.empty()) {
		std::cout << "error: image not read from file\n\n";
		_getch();                                               
		return(0);                
	}

	cv::cvtColor(imgOriginal, imgGrayscale, CV_BGR2GRAY);       // convert to grayscale

	cv::GaussianBlur(imgGrayscale,          // input image
		imgBlurred,                         // output image
		cv::Size(5, 5),                    
		1.5);                               

	cv::Canny(imgBlurred,           // input image
		imgCanny,                   // output image
		100,                        // low threshold
		200);                       // high threshold

	cv::namedWindow("imgOriginal", CV_WINDOW_NORMAL);
	cv::namedWindow("imgCanny", CV_WINDOW_NORMAL);
															
	cv::imshow("imgOriginal", imgOriginal);
	cv::imshow("imgCanny", imgCanny);

	cv::waitKey(0); 

	return(0);
}



