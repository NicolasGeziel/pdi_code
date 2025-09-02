#ifndef ISOLATEBYCHANNEL_HPP
#define ISOLATEBYCHANNEL_HPP
#include <opencv2/opencv.hpp>
 
class IsolateByChannel 
{
	public:
		static cv::Mat isolateRedChannel(const cv::Mat& img);
		static cv::Mat isolateGreenChannel(const cv::Mat& img);
		static cv::Mat isolateBlueChannel(const cv::Mat& img);
};
#endif  // ISOLATEBYCHANNEL_HPP