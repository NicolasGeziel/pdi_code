#ifndef OPERATION_HPP
#define OPERATION_HPP
 #include <opencv2/opencv.hpp>
 
class GrayScale 
{
	public:
	
		GrayScale(const cv::Mat& img1);
		cv::Mat get_gray();

 	private:
		cv::Mat img1_;
		cv::Mat result;
		
};
#endif  // OPERATION_HPP