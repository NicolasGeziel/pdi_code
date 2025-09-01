#ifndef OPERATION_HPP
#define OPERATION_HPP
#include <opencv2/opencv.hpp>
#include <iostream>
class Operation 
{
	public:
	
		Operation();
		static cv::Mat ParaCinzaMedia(const cv::Mat& img);
		static cv::Mat ParaCinzaPonderada(const cv::Mat& img);

		static cv::Mat SomarValorEscalarNaImagem(const cv::Mat& img, int valor);
		static cv::Mat SubtrairValorEscalarNaImagem(const cv::Mat& img, int valor);
		static cv::Mat MultiplicarValorEscalarNaImagem(const cv::Mat& img, double valor);
		static cv::Mat DividirValorEscalarNaImagem(const cv::Mat& img, int valor);

		static cv::Mat SomarImagemComImagem(const cv::Mat& img1, const cv::Mat& img2);
		static cv::Mat SubtrairImagemComImagem(const cv::Mat& img1, const cv::Mat& img2);
		static cv::Mat MultiplicarImagemComImagem(const cv::Mat& img1, const cv::Mat& img2);
		static cv::Mat DividirImagemComImagem(const cv::Mat& img1, const cv::Mat& img2);

		static cv::Mat SomarValorImagem(const cv::Mat& img,int vetor[3]);
		static cv::Mat SubtrairValorImagem(const cv::Mat& img,int vetor[3]);
		static cv::Mat MultiplicarValorImagem(const cv::Mat& img,double vetor[3]);
		static cv::Mat DividirValorImagem(const cv::Mat& img,double vetor[3]);

		static cv::Mat Limiarizacao(const cv::Mat& img, int limiar);
		static cv::Mat Negativo(const cv::Mat& img);

		static cv::Mat isolarCanalR(const cv::Mat& img);
		static cv::Mat isolarCanalG(const cv::Mat& img);
		static cv::Mat isolarCanalB(const cv::Mat& img);
		
		static cv::Mat HistogramaCinza(const cv::Mat& img);
		static cv::Mat HistogramaColorida(const cv::Mat& img);


 	private:

		
};

#endif  // OPERATION_HPP
