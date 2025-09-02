#include "Histogram.hpp"

cv::Mat Histogram::viewGrayscaleHistogram(const cv::Mat& img) {
    CV_Assert(!img.empty() && img.channels() == 1);

    // Vetor de frequências (0–255)
    std::vector<int> hist(256, 0);

    // Contagem das intensidades
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            uchar p = img.at<uchar>(i, j);
            hist[p]++;
        }
    }

    // Normalizar para caber na altura da imagem
    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound((double) hist_w / 256);

    int max_val = *std::max_element(hist.begin(), hist.end());

    cv::Mat histImage(hist_h, hist_w, CV_8UC1, cv::Scalar(255));

    for (int i = 1; i < 256; i++) {
        int y1 = cvRound(((double)hist[i-1] / max_val) * hist_h);
        int y2 = cvRound(((double)hist[i] / max_val) * hist_h);

        cv::line(histImage,
                 cv::Point(bin_w * (i-1), hist_h - y1),
                 cv::Point(bin_w * (i),   hist_h - y2),
                 cv::Scalar(0), 2, 8, 0);
    }

    return histImage;
}

cv::Mat Histogram::viewColorHistogram(const cv::Mat& img) {
    CV_Assert(!img.empty() && img.channels() == 3);

    // 3 histogramas: B, G, R
    std::vector<int> histB(256, 0), histG(256, 0), histR(256, 0);

    // Contagem de cada canal
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            cv::Vec3b p = img.at<cv::Vec3b>(i, j);
            histB[p[0]]++;
            histG[p[1]]++;
            histR[p[2]]++;
        }
    }

    // Configuração do gráfico
    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound((double) hist_w / 256);

    int maxB = *std::max_element(histB.begin(), histB.end());
    int maxG = *std::max_element(histG.begin(), histG.end());
    int maxR = *std::max_element(histR.begin(), histR.end());
    int max_val = std::max({maxB, maxG, maxR});

    cv::Mat histImage(hist_h, hist_w, CV_8UC3, cv::Scalar(0,0,0));

    // Desenhar cada canal
    for (int i = 1; i < 256; i++) {
        int yB1 = cvRound(((double)histB[i-1] / max_val) * hist_h);
        int yB2 = cvRound(((double)histB[i] / max_val) * hist_h);

        int yG1 = cvRound(((double)histG[i-1] / max_val) * hist_h);
        int yG2 = cvRound(((double)histG[i] / max_val) * hist_h);

        int yR1 = cvRound(((double)histR[i-1] / max_val) * hist_h);
        int yR2 = cvRound(((double)histR[i] / max_val) * hist_h);

        cv::line(histImage,
                 cv::Point(bin_w*(i-1), hist_h - yB1),
                 cv::Point(bin_w*i,     hist_h - yB2),
                 cv::Scalar(255,0,0), 2, 8, 0);

        cv::line(histImage,
                 cv::Point(bin_w*(i-1), hist_h - yG1),
                 cv::Point(bin_w*i,     hist_h - yG2),
                 cv::Scalar(0,255,0), 2, 8, 0);

        cv::line(histImage,
                 cv::Point(bin_w*(i-1), hist_h - yR1),
                 cv::Point(bin_w*i,     hist_h - yR2),
                 cv::Scalar(0,0,255), 2, 8, 0);
    }

    return histImage;
}