#ifndef THRESHOLDING_HPP
#define THRESHOLDING_HPP
#include <opencv2/opencv.hpp>
 
class Thresholding 
{
	public:
		static cv::Mat applyThreshold(const cv::Mat& img, int thresholdValue);
		
};
#endif  // THRESHOLDING_HPP