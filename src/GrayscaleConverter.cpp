#include "GrayscaleConverter.hpp"
#include <opencv2/opencv.hpp>

cv::Mat GrayscaleConverter::toGrayscaleUsingArithmeticMean(const cv::Mat& img) {
    CV_Assert(!img.empty() && img.channels() == 3);

    cv::Mat result(img.rows, img.cols, CV_8UC1); // <<<<<< 1 canal

    for (int i = 0; i < img.rows; ++i) {
        for (int j = 0; j < img.cols; ++j) {
            cv::Vec3b p = img.at<cv::Vec3b>(i, j);
            uchar media = static_cast<uchar>((p[0] + p[1] + p[2]) / 3);
            result.at<uchar>(i, j) = media; // <<<<<< usa uchar
        }
    }
    return result;
}

cv::Mat GrayscaleConverter::toGrayscaleUsingWeightedMean(const cv::Mat& img) {
    CV_Assert(!img.empty() && img.channels() == 3);

    cv::Mat result(img.rows, img.cols, CV_8UC1); // <<<<<< 1 canal

    for (int i = 0; i < img.rows; ++i) {
        for (int j = 0; j < img.cols; ++j) {
            cv::Vec3b p = img.at<cv::Vec3b>(i, j); // B, G, R
            uchar gray = cv::saturate_cast<uchar>(
                0.114 * p[0] + 0.587 * p[1] + 0.299 * p[2]
            );
            result.at<uchar>(i, j) = gray; // <<<<<< usa uchar
        }
    }
    return result;
}