#ifndef ARITHMETICOPERATIONS_HPP
#define ARITHMETICOPERATIONS_HPP
#include <opencv2/opencv.hpp>
 
class ArithmeticOperations 
{
	public:
		static cv::Mat addScalar(const cv::Mat& img, double scalar);
		static cv::Mat subtractScalar(const cv::Mat& img, double scalar);
		static cv::Mat multiplyScalar(const cv::Mat& img, double scalar);
		static cv::Mat divideScalar(const cv::Mat& img, double scalar);
		static cv::Mat addImages(const cv::Mat& img1, const cv::Mat& img2);
		static cv::Mat subtractImages(const cv::Mat& img1, const cv::Mat& img2);
		static cv::Mat multiplyImages(const cv::Mat& img1, const cv::Mat& img2);
		static cv::Mat divideImages(const cv::Mat& img1, const cv::Mat& img2);
		
};
#endif  // ARITHMETICOPERATIONS_HPP