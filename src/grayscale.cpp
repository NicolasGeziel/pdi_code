#include "grayscale.hpp"


GrayScale::GrayScale (const cv::Mat& img1)

{
    // Initialize the result matrix with the same size and type as img1
    img1_ = img1;
    result = cv::Mat(img1.rows, img1.cols, CV_8UC(1));
}

/**
* @brief Executa a conversão de uma imagem colorida para escala de cinza.* 
*/
cv::Mat GrayScale::get_gray()
{
    for (int linha = 0; linha < img1_.rows; linha++)
    {
        cv::Vec3b* pixel__in = img1_.ptr<cv::Vec3b>(linha);
        uchar* pixel_out = result.ptr<uchar>(linha);

        for (int coluna = 0; coluna < img1_.cols; coluna++)
        {
            pixel_out[coluna] = static_cast<uchar>( (pixel__in[coluna][0] + pixel__in[coluna][1] + pixel__in[coluna][2]) / 3 );
            //pixel_out[coluna] = (pixel__in[coluna][0] + pixel__in[coluna][1] + pixel__in[coluna][2]) / 3 ;
            //std::cout << "Linha: " << linha << ", Coluna: " << coluna << ", Pixel: " << static_cast<int>(pixel_out[coluna]) << std::endl;

        }
    }
    return result;
}