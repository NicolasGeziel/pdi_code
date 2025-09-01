#include "Operation.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

Operation::Operation () {}

cv::Mat Operation::ParaCinzaMedia(const cv::Mat& img) {
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

cv::Mat Operation::ParaCinzaPonderada(const cv::Mat& img) {
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

cv::Mat Operation::SomarValorEscalarNaImagem(const cv::Mat& img, int valor) {
    cv::Mat result(img.rows, img.cols, img.type()); // 3 canais
    for (int i = 0; i < img.rows; ++i) {
        for (int j = 0; j < img.cols; ++j) {
            if (img.channels() == 3) {
                cv::Vec3b p = img.at<cv::Vec3b>(i, j);
                for (int c = 0; c < 3; ++c) {
                    int novo_valor = p[c] + valor;
                    result.at<cv::Vec3b>(i, j)[c] = cv::saturate_cast<uchar>(novo_valor);
                }
            } else if (img.channels() == 1) {
                uchar p = img.at<uchar>(i, j);
                int novo_valor = p + valor;
                result.at<uchar>(i, j) = cv::saturate_cast<uchar>(novo_valor);
            }
        }
    }

    return result;
}
cv::Mat Operation::SubtrairValorEscalarNaImagem(const cv::Mat& img,int valor) {
    cv::Mat result(img.rows, img.cols, img.type());
    for(int i = 0; i < img.rows; i ++){
        for(int j = 0; j < img.cols; j++){
            if(img.channels()==3){
                cv::Vec3b p = img.at<cv::Vec3b>(i,j);
                for(int c = 0; c< 3; c++){
                    result.at<cv::Vec3b>(i,j)[c] = cv::saturate_cast<uchar>(p[c]- valor);
                }
            }
            else if(img.channels()==1){
                result.at<uchar>(i,j) = cv::saturate_cast<uchar>(img.at<uchar>(i,j)- valor);
            }
        }
    }
    return result;
}
cv::Mat Operation::MultiplicarValorEscalarNaImagem(const cv::Mat& img,double valor){
    cv::Mat result(img.rows,img.cols, img.type());
    for(int i=0;i< img.rows;i++){
        for(int j=0;j<img.cols;j++){
            if(img.channels()==3){
                cv::Vec3b p = img.at<cv::Vec3b>(i,j);
                for(int c=0;c<3;c++){
                    result.at<cv::Vec3b>(i,j)[c] = cv::saturate_cast<uchar>(p[c]*valor);
                }
            }
            else if(img.channels()==1){
                result.at<uchar>(i,j) = cv::saturate_cast<uchar>(img.at<uchar>(i,j)*valor);
            }
        }
    }
    return result;
}
cv::Mat Operation::DividirValorEscalarNaImagem(const cv::Mat& img,int valor){
    cv::Mat result(img.rows,img.cols, img.type());
    for(int i=0;i< img.rows;i++){
        for(int j=0;j<img.cols;j++){
            if(img.channels()==3){
                cv::Vec3b p = img.at<cv::Vec3b>(i,j);
                for(int c=0;c<3;c++){
                    result.at<cv::Vec3b>(i,j)[c] = cv::saturate_cast<uchar>(p[c]/valor);
                }
            }
            else if(img.channels()==1){
                result.at<uchar>(i,j) = cv::saturate_cast<uchar>(img.at<uchar>(i,j)/valor);
            }
        }
    }
    return result;
}

cv::Mat Operation::SomarImagemComImagem(const cv::Mat& img1, const cv::Mat& img2){
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

cv::Mat Operation::SubtrairImagemComImagem(const cv::Mat& img1, const cv::Mat& img2){
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

cv::Mat Operation::MultiplicarImagemComImagem(const cv::Mat& img1, const cv::Mat& img2){
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

cv::Mat Operation::DividirImagemComImagem(const cv::Mat& img1, const cv::Mat& img2){
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
                        result.at<cv::Vec3b>(i,j)[c] = 255; // ou algum outro valor padrão
                    }
                }
            }
            else if(img1.channels()==1){
                uchar p1 = img1.at<uchar>(i,j);
                uchar p2 = img2.at<uchar>(i,j);
                if(p2 != 0){
                    result.at<uchar>(i,j) = cv::saturate_cast<uchar>(p1/p2);
                } else {
                    result.at<uchar>(i,j) = 255; // ou algum outro valor padrão
                }
            }
        }
    }
    return result;
}
cv::Mat Operation::SomarValorImagem(const cv::Mat& img,int vetor[3]) {
    cv::Mat result(img.rows, img.cols, img.type()); 
    for (int i = 0; i < img.rows; ++i) {
        for (int j = 0; j < img.cols; ++j) {
            if (img.channels() == 3) {
                cv::Vec3b p = img.at<cv::Vec3b>(i, j);
                int novo_valorB = p[0] + vetor[2];
                int novo_valorG = p[1] + vetor[1];
                int novo_valorR = p[2] + vetor[0];
                result.at<cv::Vec3b>(i, j)[0] = cv::saturate_cast<uchar>(novo_valorB);
                result.at<cv::Vec3b>(i, j)[1] = cv::saturate_cast<uchar>(novo_valorG);
                result.at<cv::Vec3b>(i, j)[2] = cv::saturate_cast<uchar>(novo_valorR);
            } else if (img.channels() == 1) {
                uchar p = img.at<uchar>(i, j);
                int novo_valor = p + vetor[0];
                result.at<uchar>(i, j) = cv::saturate_cast<uchar>(novo_valor);
            }
        }
    }
    return result;
}
cv::Mat Operation::SubtrairValorImagem(const cv::Mat& img,int vetor[3]) {
    cv::Mat result(img.rows, img.cols, img.type()); 
    for (int i = 0; i < img.rows; ++i) {
        for (int j = 0; j < img.cols; ++j) {
            if (img.channels() == 3) {
                cv::Vec3b p = img.at<cv::Vec3b>(i, j);
                int novo_valorB = p[0] - vetor[2];
                int novo_valorG = p[1] - vetor[1];
                int novo_valorR = p[2] - vetor[0];
                result.at<cv::Vec3b>(i, j)[0] = cv::saturate_cast<uchar>(novo_valorB);
                result.at<cv::Vec3b>(i, j)[1] = cv::saturate_cast<uchar>(novo_valorG);
                result.at<cv::Vec3b>(i, j)[2] = cv::saturate_cast<uchar>(novo_valorR);
            } else if (img.channels() == 1) {
                uchar p = img.at<uchar>(i, j);
                int novo_valor = p - vetor[0];
                result.at<uchar>(i, j) = cv::saturate_cast<uchar>(novo_valor);
            }
        }
    }
    return result;
}
cv::Mat Operation::MultiplicarValorImagem(const cv::Mat& img,double vetor[3]) {
    cv::Mat result(img.rows, img.cols, img.type()); 
    for (int i = 0; i < img.rows; ++i) {
        for (int j = 0; j < img.cols; ++j) {
            if (img.channels() == 3) {
                cv::Vec3b p = img.at<cv::Vec3b>(i, j);
                int novo_valorB = p[0] * vetor[2];
                int novo_valorG = p[1] * vetor[1];
                int novo_valorR = p[2] * vetor[0];
                result.at<cv::Vec3b>(i, j)[0] = cv::saturate_cast<uchar>(novo_valorB);
                result.at<cv::Vec3b>(i, j)[1] = cv::saturate_cast<uchar>(novo_valorG);
                result.at<cv::Vec3b>(i, j)[2] = cv::saturate_cast<uchar>(novo_valorR);
            } else if (img.channels() == 1) {
                uchar p = img.at<uchar>(i, j);
                int novo_valor = p * vetor[0];
                result.at<uchar>(i, j) = cv::saturate_cast<uchar>(novo_valor);
            }
        }
    }
    return result;
}
cv::Mat Operation::DividirValorImagem(const cv::Mat& img,double vetor[3]) {
    cv::Mat result(img.rows, img.cols, img.type()); 
    for (int i = 0; i < img.rows; ++i) {
        for (int j = 0; j < img.cols; ++j) {
            if (img.channels() == 3) {
                cv::Vec3b p = img.at<cv::Vec3b>(i, j);
                int novo_valorB = vetor[2] != 0 ? p[0] / vetor[2] : 255;
                int novo_valorG = vetor[1] != 0 ? p[1] / vetor[1] : 255;
                int novo_valorR = vetor[0] != 0 ? p[2] / vetor[0] : 255;
                result.at<cv::Vec3b>(i, j)[0] = cv::saturate_cast<uchar>(novo_valorB);
                result.at<cv::Vec3b>(i, j)[1] = cv::saturate_cast<uchar>(novo_valorG);
                result.at<cv::Vec3b>(i, j)[2] = cv::saturate_cast<uchar>(novo_valorR);
            } else if (img.channels() == 1) {
                uchar p = img.at<uchar>(i, j);
                int novo_valor = vetor[0] != 0 ? p / vetor[0] : 255;
                result.at<uchar>(i, j) = cv::saturate_cast<uchar>(novo_valor);
            }
        }
    }
    return result;
}   

cv::Mat Operation::Limiarizacao(const cv::Mat& img, int limiar){
    cv::Mat result(img.rows, img.cols, img.type());
    for(int i=0;i<img.rows;i++){
        for(int j=0;j<img.cols;j++){
            uchar p = img.at<uchar>(i,j);
            if(img.channels()==3){
                cv::Vec3b p = img.at<cv::Vec3b>(i,j);
                for(int c=0;c<3;c++){
                    result.at<cv::Vec3b>(i,j)[c] = (p[c] >= limiar) ? 255 : 0;
                }              
            }
            else if(img.channels()==1){
                result.at<uchar>(i,j) = (p >= limiar) ? 255 : 0;
            }
        }
    }
    return result;
}

cv::Mat Operation::isolarCanalR(const cv::Mat& img){
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
cv::Mat Operation::isolarCanalG(const cv::Mat& img){
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

cv::Mat Operation::isolarCanalB(const cv::Mat& img){
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

cv::Mat Operation::Negativo(const cv::Mat& img){
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

cv::Mat Operation::HistogramaCinza(const cv::Mat& img) {
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

cv::Mat Operation::HistogramaColorida(const cv::Mat& img) {
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
