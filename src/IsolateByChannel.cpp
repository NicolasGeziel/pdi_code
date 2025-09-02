#include "IsolateByChannel.hpp"

cv::Mat IsolateByChannel::isolateRedChannel(const cv::Mat& img){
    CV_Assert(!img.empty() && img.channels() == 3);
    cv::Mat result(img.rows, img.cols, img.type());
    for(int i=0;i<img.rows;i++){
        for(int j=0;j<img.cols;j++){
            cv::Vec3b p = img.at<cv::Vec3b>(i,j);
            result.at<cv::Vec3b>(i,j)[0] = 0; // Canal B
            result.at<cv::Vec3b>(i,j)[1] = 0; // Canal G
            result.at<cv::Vec3b>(i,j)[2] = p[2]; // Canal R
        }
    }
    return result;
}

cv::Mat IsolateByChannel::isolateGreenChannel(const cv::Mat& img){
    CV_Assert(!img.empty() && img.channels() == 3);
    cv::Mat result(img.rows, img.cols, img.type());
    for(int i=0;i<img.rows;i++){
        for(int j=0;j<img.cols;j++){
            cv::Vec3b p = img.at<cv::Vec3b>(i,j);
            result.at<cv::Vec3b>(i,j)[0] = 0; // Canal B
            result.at<cv::Vec3b>(i,j)[1] = p[1]; // Canal G
            result.at<cv::Vec3b>(i,j)[2] = 0; // Canal R
        }
    }
    return result;
}

cv::Mat IsolateByChannel::isolateBlueChannel(const cv::Mat& img){
    CV_Assert(!img.empty() && img.channels() == 3);
    cv::Mat result(img.rows, img.cols, img.type());
    for(int i=0;i<img.rows;i++){
        for(int j=0;j<img.cols;j++){
            cv::Vec3b p = img.at<cv::Vec3b>(i,j);
            result.at<cv::Vec3b>(i,j)[0] = p[0]; // Canal B
            result.at<cv::Vec3b>(i,j)[1] = 0; // Canal G
            result.at<cv::Vec3b>(i,j)[2] = 0; // Canal R
        }
    }
    return result;
}