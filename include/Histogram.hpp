#ifndef HISTOGRAM_HPP
#define HISTOGRAM_HPP
#include <opencv2/opencv.hpp>
 
class Histogram 
{
	public:
		static cv::Mat viewGrayscaleHistogram(const cv::Mat& img);
		static cv::Mat viewColorHistogram(const cv::Mat& img);
};
#endif  // ISOLATEBYCHANNEL_HPP