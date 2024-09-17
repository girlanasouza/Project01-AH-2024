#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "libraries/stb_image.h"
#include "libraries/stb_image_write.h"
#include <iostream>
#include <chrono>  // Biblioteca para medir tempo de execução

using namespace std;

int main() {
    // Medir tempo de execução para CPU
    auto start_cpu = chrono::high_resolution_clock::now();  // Início da medição

    // Abrir imagem
    int width, height, channels;
    unsigned char* img = stbi_load("input/input.jpg", &width, &height, &channels, 0);

    if (img == nullptr) {
        cerr << "Erro ao abrir a imagem!" << endl;
        return -1;
    }

    // Aplicar filtro verde (se a imagem tiver 3 ou 4 canais)
    if (channels == 3 || channels == 4) {
        for (int i = 0; i < width * height * channels; i += channels) {
            img[i + 1] = 255;  // Definir o canal verde para 255
        }
        stbi_write_png("output/output_green.png", width, height, channels, img, width * channels);
        cout << "Imagem com filtro verde salva como output_green.png" << endl;
    } else {
        cerr << "A imagem não possui canais suficientes para aplicar o filtro verde!" << endl;
    }

    // Aplicar filtro invertido (inverter as cores)
    if (channels == 3 || channels == 4) {
        unsigned char* img_inverted = (unsigned char*)malloc(width * height * channels);
        memcpy(img_inverted, img, width * height * channels); 

        for (int i = 0; i < width * height * channels; i += channels) {
            img_inverted[i] = 255 - img[i];       
            img_inverted[i + 1] = 255 - img[i + 1];
            img_inverted[i + 2] = 255 - img[i + 2];
        }

        stbi_write_png("output/output_inverted.png", width, height, channels, img_inverted, width * channels);
        free(img_inverted);
        cout << "Imagem com filtro invertido salva como output_inverted.png" << endl;
    }

    // Converter imagem para escala de cinza
    for (int i = 0; i < width * height * channels; i += channels) {
        unsigned char r = img[i];
        unsigned char g = img[i + 1];
        unsigned char b = img[i + 2];
        unsigned char gray = (unsigned char)(0.2126f * r + 0.7152f * g + 0.0722f * b);

        img[i] = gray;
        img[i + 1] = gray;
        img[i + 2] = gray;
    }

    stbi_write_png("output/output_grayscale.png", width, height, channels, img, width * channels);
    cout << "Imagem em escala de cinza salva como output_grayscale.png" << endl;

    // Liberar memória da imagem original
    stbi_image_free(img);

    // Fim da medição
    auto end_cpu = chrono::high_resolution_clock::now();
    auto duration_cpu = chrono::duration_cast<chrono::milliseconds>(end_cpu - start_cpu);
    cout << "Tempo de execução na CPU: " << duration_cpu.count() << " ms" << endl;

    return 0;
}
