#ifndef GRAYSCALECONVERTER_HPP
#define GRAYSCALECONVERTER_HPP
#include <opencv2/opencv.hpp>
 
class GrayscaleConverter
{
	public:
		static cv::Mat toGrayscaleUsingWeightedMean(const cv::Mat& img);
		static cv::Mat toGrayscaleUsingArithmeticMean(const cv::Mat& img);
		
};
#endif  // GRAYSCALECONVERTER_HPP