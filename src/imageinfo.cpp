#include "ImageInfo.hpp"

ImageInfo::ImageInfo()
{}
ImageInfo::~ImageInfo()
{}


/**
 * @brief Converte o identificador de tipo de um cv::Mat para uma string legível.
 * * A função recebe o inteiro retornado por `cv::Mat::type()` e extrai a informação
 * de profundidade (depth), como CV_8U, CV_32F, etc., retornando-a como uma 
 * std::string descritiva.
 * * @param tipo O inteiro que representa o tipo da matriz, obtido de `imagem.type()`.
 * @return std::string Uma string contendo a representação legível da profundidade da matriz.
 * Retorna "Tipo desconhecido" se a profundidade não for reconhecida.
 */
std::string ImageInfo::tipo_to_string(int tipo) 
{
    int profundidade = tipo & CV_MAT_DEPTH_MASK;
    switch (profundidade) {
        case CV_8U:  return "CV_8U (8-bit unsigned integer)";
        case CV_8S:  return "CV_8S (8-bit signed integer)";
        case CV_16U: return "CV_16U (16-bit unsigned integer)";
        case CV_16S: return "CV_16S (16-bit signed integer)";
        case CV_32S: return "CV_32S (32-bit signed integer)";
        case CV_32F: return "CV_32F (32-bit float)";
        case CV_64F: return "CV_64F (64-bit double)";
        default:     return "Tipo desconhecido";
    }
}

/**
 * @brief Mostra informações detalhadas de uma imagem Mat do OpenCV.
 *
 * @param imagem A imagem (cv::Mat) cujas informações serão exibidas.
 * @param nomeImagem Uma string opcional com o nome da imagem para exibição.
 */
void ImageInfo::image_show(const cv::Mat& image, const std::string& nomeImagem)
{
    std::cout << "--------------------------------------------------" << std::endl << std::endl;
    std::cout << "--- Info da Imagem: " << nomeImagem << " ---" << std::endl;

    // 1. Quantidade de Linhas e Colunas (Altura e Largura)
    std::cout << "Dimensoes (Linhas x Colunas): " << image.rows << " x " << image.cols << std::endl;

    // 2. Quantidade de Canais
    std::cout << "Quantidade de Canais: " << image.channels() << std::endl;

    // 3. Tamanho (Total de elementos)
    // O tamanho total é o número de pixels multiplicado pelo número de canais.
    std::cout << "Tamanho (Total de elementos): " << image.total() << std::endl;
    // O tamanho em bytes pode ser calculado como: imagem.total() * imagem.elemSize()
    std::cout << "Tamanho em bytes: " << image.total() * image.elemSize() << " bytes" << std::endl;

    // 4. Profundidade (Depth)
    // A profundidade refere-se ao tipo de dados de cada elemento na matriz.
    std::cout << "Profundidade (Depth): " << tipo_to_string(image.type()) << std::endl;

    std::cout << "--------------------------------------------------" << std::endl << std::endl;
}