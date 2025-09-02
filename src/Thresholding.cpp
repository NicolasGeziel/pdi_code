#include "Thresholding.hpp"

cv::Mat Thresholding::applyThreshold(const cv::Mat& img, int thresholdValue){
    cv::Mat result(img.rows, img.cols, img.type());
    for(int i=0;i<img.rows;i++){
        for(int j=0;j<img.cols;j++){
            uchar p = img.at<uchar>(i,j);
            if(img.channels()==3){
                cv::Vec3b p = img.at<cv::Vec3b>(i,j);
                for(int c=0;c<3;c++){
                    result.at<cv::Vec3b>(i,j)[c] = (p[c] >= thresholdValue) ? 255 : 0;
                }              
            }
            else if(img.channels()==1){
                result.at<uchar>(i,j) = (p >= thresholdValue) ? 255 : 0;
            }
        }
    }
    return result;
}