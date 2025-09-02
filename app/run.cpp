#include <iostream>
#include <GrayscaleConverter.hpp>
#include <Thresholding.hpp>
#include <Negative.hpp>
#include <ArithmeticOperations.hpp>
#include <IsolateByChannel.hpp>
#include <Histogram.hpp>

int main() {
    cv::Mat img = cv::imread("../data/blobs-image.jpg");
    cv::Mat img2 = cv::imread("../data/ave-01.jpeg");
    cv::Mat img3 = cv::imread("../data/ave-02.jpeg");
    cv::Mat img4 = cv::imread("../data/estrada1.png");
    cv::Mat img5 = cv::imread("../data/estrada.png");

    if (img.empty() || img2.empty() || img3.empty()) {
        std::cerr << "Erro ao carregar a imagem\n";
        return -1;
    }

    cv::Mat grayscale = GrayscaleConverter::toGrayscaleUsingWeightedMean(img);
    cv::Mat grayscale2 = GrayscaleConverter::toGrayscaleUsingArithmeticMean(img);
    cv::Mat addImages = ArithmeticOperations::addImages(img4, img5);
    cv::Mat subtractImages = ArithmeticOperations::subtractImages(img4, img5);
    cv::Mat multiplyImages = ArithmeticOperations::multiplyImages(img2, img3);
    cv::Mat divideImages = ArithmeticOperations::divideImages(img2, img3);
    cv::Mat addScalar = ArithmeticOperations::addScalar(img, 50);
    cv::Mat subtractScalar = ArithmeticOperations::subtractScalar(img, 50);
    cv::Mat multiplyScalar = ArithmeticOperations::multiplyScalar(img, 1.5);
    cv::Mat divideScalar = ArithmeticOperations::divideScalar(img, 1.5);
    cv::Mat thresholded = Thresholding::applyThreshold(grayscale, 128);
    cv::Mat isolatedRed = IsolateByChannel::isolateRedChannel(img);
    cv::Mat isolatedGreen = IsolateByChannel::isolateGreenChannel(img);
    cv::Mat isolatedBlue = IsolateByChannel::isolateBlueChannel(img);
    cv::Mat histogramGray = Histogram::viewGrayscaleHistogram(grayscale);
    cv::Mat histogramColor = Histogram::viewColorHistogram(img);
    cv::Mat negative = Negative::applyNegative(img);
    
    cv::imshow("Original", img);
    cv::imshow("Grayscale Weighted", grayscale);
    cv::imshow("Grayscale Arithmetic", grayscale2);
    cv::waitKey(0);
    cv::imshow("Add Images", addImages);
    cv::imshow("Subtract Images", subtractImages);
    cv::waitKey(0);
    cv::imshow("Multiply Images", multiplyImages);
    cv::imshow("Divide Images", divideImages);
    cv::waitKey(0);
    cv::imshow("Add Scalar", addScalar);
    cv::imshow("Subtract Scalar", subtractScalar);
    cv::imshow("Multiply Scalar", multiplyScalar);
    cv::imshow("Divide Scalar", divideScalar);
    cv::waitKey(0);
    cv::imshow("Thresholded", thresholded);
    cv::waitKey(0);
    cv::imshow("Isolated Red", isolatedRed);
    cv::imshow("Isolated Green", isolatedGreen);
    cv::imshow("Isolated Blue", isolatedBlue);
    cv::waitKey(0);
    cv::imshow("Histogram Gray", histogramGray);
    cv::imshow("Histogram Color", histogramColor);
    cv::waitKey(0);
    cv::imshow("Negative", negative);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}