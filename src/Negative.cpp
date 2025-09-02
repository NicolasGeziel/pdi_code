#include "Negative.hpp"

cv::Mat Negative::applyNegative(const cv::Mat& img){
    cv::Mat result(img.rows, img.cols, img.type());
    for(int i=0;i<img.rows;i++){
        for(int j=0;j<img.cols;j++){
            if(img.channels()==3){
                cv::Vec3b p = img.at<cv::Vec3b>(i,j);
                for(int c=0;c<3;c++){
                    result.at<cv::Vec3b>(i,j)[c] = 255 - p[c];
                }
            }
            else if(img.channels()==1){
                uchar p = img.at<uchar>(i,j);
                result.at<uchar>(i,j) = 255 - p;
            }
        }
    }
    return result;
}