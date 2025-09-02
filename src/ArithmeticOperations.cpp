#include "ArithmeticOperations.hpp"

cv::Mat ArithmeticOperations::addScalar(const cv::Mat& img, double scalar) {
    cv::Mat result(img.rows, img.cols, img.type()); // 3 canais
    for (int i = 0; i < img.rows; ++i) {
        for (int j = 0; j < img.cols; ++j) {
            if (img.channels() == 3) {
                cv::Vec3b p = img.at<cv::Vec3b>(i, j);
                for (int c = 0; c < 3; ++c) {
                    int newValue = p[c] + scalar;
                    result.at<cv::Vec3b>(i, j)[c] = cv::saturate_cast<uchar>(newValue);
                }
            } else if (img.channels() == 1) {
                uchar p = img.at<uchar>(i, j);
                int newValue = p + scalar;
                result.at<uchar>(i, j) = cv::saturate_cast<uchar>(newValue);
            }
        }
    }

    return result;
}
cv::Mat ArithmeticOperations::subtractScalar(const cv::Mat& img, double scalar) {
    cv::Mat result(img.rows, img.cols, img.type());
    for(int i = 0; i < img.rows; i ++){
        for(int j = 0; j < img.cols; j++){
            if(img.channels()==3){
                cv::Vec3b p = img.at<cv::Vec3b>(i,j);
                for(int c = 0; c< 3; c++){
                    result.at<cv::Vec3b>(i,j)[c] = cv::saturate_cast<uchar>(p[c]- scalar);
                }
            }
            else if(img.channels()==1){
                result.at<uchar>(i,j) = cv::saturate_cast<uchar>(img.at<uchar>(i,j)- scalar);
            }
        }
    }
    return result;
}
cv::Mat ArithmeticOperations::multiplyScalar(const cv::Mat& img, double scalar){
    cv::Mat result(img.rows,img.cols, img.type());
    for(int i=0;i< img.rows;i++){
        for(int j=0;j<img.cols;j++){
            if(img.channels()==3){
                cv::Vec3b p = img.at<cv::Vec3b>(i,j);
                for(int c=0;c<3;c++){
                    result.at<cv::Vec3b>(i,j)[c] = cv::saturate_cast<uchar>(p[c]*scalar);
                }
            }
            else if(img.channels()==1){
                result.at<uchar>(i,j) = cv::saturate_cast<uchar>(img.at<uchar>(i,j)*scalar);
            }
        }
    }
    return result;
}
cv::Mat ArithmeticOperations::divideScalar(const cv::Mat& img, double scalar){
    cv::Mat result(img.rows,img.cols, img.type());
    for(int i=0;i< img.rows;i++){
        for(int j=0;j<img.cols;j++){
            if(img.channels()==3){
                cv::Vec3b p = img.at<cv::Vec3b>(i,j);
                for(int c=0;c<3;c++){
                    result.at<cv::Vec3b>(i,j)[c] = cv::saturate_cast<uchar>(p[c]/scalar);
                }
            }
            else if(img.channels()==1){
                result.at<uchar>(i,j) = cv::saturate_cast<uchar>(img.at<uchar>(i,j)/scalar);
            }
        }
    }
    return result;
}

cv::Mat ArithmeticOperations::addImages(const cv::Mat& img1, const cv::Mat& img2){
    CV_Assert(img1.size() == img2.size() && img1.type() == img2.type());
    cv::Mat result(img1.rows, img1.cols, img1.type());
    for(int i=0;i<img1.rows;i++){
        for(int j=0;j<img1.cols;j++){
            if(img1.channels()==3){
                cv::Vec3b p1 = img1.at<cv::Vec3b>(i,j);
                cv::Vec3b p2 = img2.at<cv::Vec3b>(i,j);
                for(int c=0;c<3;c++){
                    result.at<cv::Vec3b>(i,j)[c] = cv::saturate_cast<uchar>(p1[c]+p2[c]);
                }
            }
            else if(img1.channels()==1){
                uchar p1 = img1.at<uchar>(i,j);
                uchar p2 = img2.at<uchar>(i,j);
                result.at<uchar>(i,j) = cv::saturate_cast<uchar>(p1+p2);
            }
        }
    }
    return result;
}

cv::Mat ArithmeticOperations::subtractImages(const cv::Mat& img1, const cv::Mat& img2){
    CV_Assert(img1.size() == img2.size() && img1.type() == img2.type());
    cv::Mat result(img1.rows, img1.cols, img1.type());
    for(int i=0;i<img1.rows;i++){
        for(int j=0;j<img1.cols;j++){
            if(img1.channels()==3){
                cv::Vec3b p1 = img1.at<cv::Vec3b>(i,j);
                cv::Vec3b p2 = img2.at<cv::Vec3b>(i,j);
                for(int c=0;c<3;c++){
                    result.at<cv::Vec3b>(i,j)[c] = cv::saturate_cast<uchar>(p1[c]-p2[c]);
                }
            }
            else if(img1.channels()==1){
                uchar p1 = img1.at<uchar>(i,j);
                uchar p2 = img2.at<uchar>(i,j);
                result.at<uchar>(i,j) = cv::saturate_cast<uchar>(p1-p2);
            }
        }
    }
    return result;
}

cv::Mat ArithmeticOperations::multiplyImages(const cv::Mat& img1, const cv::Mat& img2){
    CV_Assert(img1.size() == img2.size() && img1.type() == img2.type());
    cv::Mat result(img1.rows, img1.cols, img1.type());
    for(int i=0;i<img1.rows;i++){
        for(int j=0;j<img1.cols;j++){
            if(img1.channels()==3){
                cv::Vec3b p1 = img1.at<cv::Vec3b>(i,j);
                cv::Vec3b p2 = img2.at<cv::Vec3b>(i,j);
                for(int c=0;c<3;c++){
                    result.at<cv::Vec3b>(i,j)[c] = cv::saturate_cast<uchar>(p1[c]*p2[c]);
                }
            }
            else if(img1.channels()==1){
                uchar p1 = img1.at<uchar>(i,j);
                uchar p2 = img2.at<uchar>(i,j);
                result.at<uchar>(i,j) = cv::saturate_cast<uchar>(p1*p2);
            }
        }
    }
    return result;
}

cv::Mat ArithmeticOperations::divideImages(const cv::Mat& img1, const cv::Mat& img2){
    CV_Assert(img1.size() == img2.size() && img1.type() == img2.type());
    cv::Mat result(img1.rows, img1.cols, img1.type());
    for(int i=0;i<img1.rows;i++){
        for(int j=0;j<img1.cols;j++){
            if(img1.channels()==3){
                cv::Vec3b p1 = img1.at<cv::Vec3b>(i,j);
                cv::Vec3b p2 = img2.at<cv::Vec3b>(i,j);
                for(int c=0;c<3;c++){
                    if(p2[c] != 0){
                        result.at<cv::Vec3b>(i,j)[c] = cv::saturate_cast<uchar>(p1[c]/p2[c]);
                    } else {
                        result.at<cv::Vec3b>(i,j)[c] = 255; // ou algum outro scalar padrão
                    }
                }
            }
            else if(img1.channels()==1){
                uchar p1 = img1.at<uchar>(i,j);
                uchar p2 = img2.at<uchar>(i,j);
                if(p2 != 0){
                    result.at<uchar>(i,j) = cv::saturate_cast<uchar>(p1/p2);
                } else {
                    result.at<uchar>(i,j) = 255; // ou algum outro scalar padrão
                }
            }
        }
    }
    return result;
}

// cv::Mat ArithmeticOperations::SomarscalarImagem(const cv::Mat& img,int vetor[3]) {
//     cv::Mat result(img.rows, img.cols, img.type()); 
//     for (int i = 0; i < img.rows; ++i) {
//         for (int j = 0; j < img.cols; ++j) {
//             if (img.channels() == 3) {
//                 cv::Vec3b p = img.at<cv::Vec3b>(i, j);
//                 int newValueB = p[0] + vetor[2];
//                 int newValueG = p[1] + vetor[1];
//                 int newValueR = p[2] + vetor[0];
//                 result.at<cv::Vec3b>(i, j)[0] = cv::saturate_cast<uchar>(newValueB);
//                 result.at<cv::Vec3b>(i, j)[1] = cv::saturate_cast<uchar>(newValueG);
//                 result.at<cv::Vec3b>(i, j)[2] = cv::saturate_cast<uchar>(newValueR);
//             } else if (img.channels() == 1) {
//                 uchar p = img.at<uchar>(i, j);
//                 int newValue = p + vetor[0];
//                 result.at<uchar>(i, j) = cv::saturate_cast<uchar>(newValue);
//             }
//         }
//     }
//     return result;
// }

// cv::Mat ArithmeticOperations::SubtrairscalarImagem(const cv::Mat& img,int vetor[3]) {
//     cv::Mat result(img.rows, img.cols, img.type()); 
//     for (int i = 0; i < img.rows; ++i) {
//         for (int j = 0; j < img.cols; ++j) {
//             if (img.channels() == 3) {
//                 cv::Vec3b p = img.at<cv::Vec3b>(i, j);
//                 int newValueB = p[0] - vetor[2];
//                 int newValueG = p[1] - vetor[1];
//                 int newValueR = p[2] - vetor[0];
//                 result.at<cv::Vec3b>(i, j)[0] = cv::saturate_cast<uchar>(newValueB);
//                 result.at<cv::Vec3b>(i, j)[1] = cv::saturate_cast<uchar>(newValueG);
//                 result.at<cv::Vec3b>(i, j)[2] = cv::saturate_cast<uchar>(newValueR);
//             } else if (img.channels() == 1) {
//                 uchar p = img.at<uchar>(i, j);
//                 int newValue = p - vetor[0];
//                 result.at<uchar>(i, j) = cv::saturate_cast<uchar>(newValue);
//             }
//         }
//     }
//     return result;
// }

// cv::Mat ArithmeticOperations::MultiplicarscalarImagem(const cv::Mat& img,double vetor[3]) {
//     cv::Mat result(img.rows, img.cols, img.type()); 
//     for (int i = 0; i < img.rows; ++i) {
//         for (int j = 0; j < img.cols; ++j) {
//             if (img.channels() == 3) {
//                 cv::Vec3b p = img.at<cv::Vec3b>(i, j);
//                 int newValueB = p[0] * vetor[2];
//                 int newValueG = p[1] * vetor[1];
//                 int newValueR = p[2] * vetor[0];
//                 result.at<cv::Vec3b>(i, j)[0] = cv::saturate_cast<uchar>(newValueB);
//                 result.at<cv::Vec3b>(i, j)[1] = cv::saturate_cast<uchar>(newValueG);
//                 result.at<cv::Vec3b>(i, j)[2] = cv::saturate_cast<uchar>(newValueR);
//             } else if (img.channels() == 1) {
//                 uchar p = img.at<uchar>(i, j);
//                 int newValue = p * vetor[0];
//                 result.at<uchar>(i, j) = cv::saturate_cast<uchar>(newValue);
//             }
//         }
//     }
//     return result;
// }

// cv::Mat ArithmeticOperations::DividirscalarImagem(const cv::Mat& img,double vetor[3]) {
//     cv::Mat result(img.rows, img.cols, img.type()); 
//     for (int i = 0; i < img.rows; ++i) {
//         for (int j = 0; j < img.cols; ++j) {
//             if (img.channels() == 3) {
//                 cv::Vec3b p = img.at<cv::Vec3b>(i, j);
//                 int newValueB = vetor[2] != 0 ? p[0] / vetor[2] : 255;
//                 int newValueG = vetor[1] != 0 ? p[1] / vetor[1] : 255;
//                 int newValueR = vetor[0] != 0 ? p[2] / vetor[0] : 255;
//                 result.at<cv::Vec3b>(i, j)[0] = cv::saturate_cast<uchar>(newValueB);
//                 result.at<cv::Vec3b>(i, j)[1] = cv::saturate_cast<uchar>(newValueG);
//                 result.at<cv::Vec3b>(i, j)[2] = cv::saturate_cast<uchar>(newValueR);
//             } else if (img.channels() == 1) {
//                 uchar p = img.at<uchar>(i, j);
//                 int newValue = vetor[0] != 0 ? p / vetor[0] : 255;
//                 result.at<uchar>(i, j) = cv::saturate_cast<uchar>(newValue);
//             }
//         }
//     }
//     return result;
// }