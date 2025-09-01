#ifndef IMAGEINFO_H
#define IMAGEINFO_H

#pragma once

#include <opencv2/opencv.hpp>

class ImageInfo
{
    public:
        ImageInfo();
        ~ImageInfo();

        static void image_show (const cv::Mat& image, const std::string& nomeImagem = "Imagem");

    private:
        /**
         * @brief Converte o identificador de tipo de um cv::Mat para uma string legível.
         * * A função recebe o inteiro retornado por `cv::Mat::type()` e extrai a informação
         * de profundidade (depth), como CV_8U, CV_32F, etc., retornando-a como uma 
         * std::string descritiva.
         * * @param tipo O inteiro que representa o tipo da matriz, obtido de `imagem.type()`.
         * @return std::string Uma string contendo a representação legível da profundidade da matriz.
         * Retorna "Tipo desconhecido" se a profundidade não for reconhecida.
        */
        static std::string tipo_to_string(int tipo);
};

#endif