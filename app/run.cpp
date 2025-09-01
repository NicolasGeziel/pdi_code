#include <opencv2/opencv.hpp>
#include <iostream>
#include "Operation.hpp"

int main() {
    cv::Mat img = cv::imread("../data/blobs-image.jpg");
    cv::Mat img2 = cv::imread("../data/ave-01.jpeg");
    cv::Mat img3 = cv::imread("../data/ave-02.jpeg");
    if (img.empty()) {
        std::cerr << "Erro ao carregar a imagem\n";
        return -1;
    }
    /*
    cv::Mat somarvalor = Operation::SomarValorEscalarNaImagem(img, 50);
    cv::Mat m = Operation::ParaCinzaMedia(img);
    cv::Mat m = Operation::ParaCinzaMedia(img);
    cv::Mat somarvalor = Operation::SomarValorEscalarNaImagem(img, 50);
    cv::Mat somarValorCinza = Operation::SomarValorEscalarNaImagem(m, 50);
    cv::Mat subtrairValorCinza = Operation::SubtrairValorEscalarNaImagem(m, 50);
    cv::Mat subtrairValor = Operation::SubtrairValorEscalarNaImagem(img, 50);
    cv::Mat MultiplicarValor = Operation::MultiplicarValorEscalarNaImagem(img, 2);
    cv::Mat MultiplicarValorCinza = Operation::MultiplicarValorEscalarNaImagem(m, 2);
    cv::Mat DividirValor = Operation::DividirValorEscalarNaImagem(img, 2);
    cv::Mat DividirValorCinza = Operation::DividirValorEscalarNaImagem(m, 2);
    */
    double vetor[3] = {0.5, 3, 1};
    //cv::Mat somarvalorImagem = Operation::Histograma(img);
    cv::Mat p = Operation::ParaCinzaPonderada(img);
    cv::Mat SomarValorIMagemcinza = Operation::Histograma(p);
    // cv::imshow("Original", img);
    cv::imshow("Original Cinza", p);
    //cv::imshow("Sub valor Imagem", somarvalorImagem);
    cv::imshow("SUbs Cinza", SomarValorIMagemcinza);
    /*
    cv::imshow("Media Arit", somarvalor);
    cv::imshow("Media Arit", somarvalor);
    cv::imshow("Cinza + 50", somarValorCinza);
    cv::imshow("Cinza - 50", subtrairValorCinza);
    cv::imshow("Original - 50", subtrairValor);
    cv::imshow("Original * 2", MultiplicarValor);
    cv::imshow("Cinza * 2", MultiplicarValorCinza);
    cv::imshow("Original / 2", DividirValor);
    cv::imshow("Cinza / 2", DividirValorCinza);
    */

    cv::waitKey(0);

    return 0;
}