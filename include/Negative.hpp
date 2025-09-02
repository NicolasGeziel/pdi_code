#ifndef NEGATIVE_HPP
#define NEGATIVE_HPP
#include <opencv2/opencv.hpp>
 
class Negative 
{
	public:
		static cv::Mat applyNegative(const cv::Mat& img);
		
};
#endif  // NEGATIVE_HPP