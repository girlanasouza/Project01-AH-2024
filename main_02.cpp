#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <chrono>  
#include <cstdlib>  
#include <iostream>
#include <string.h>
#include "libraries/stb_image.h"
#include "libraries/stb_image_write.h"

using namespace std;

void apply_filter_green(int width, int height, int channels, unsigned char* img_filtered ) {
    if (channels == 3 || channels == 4) {
        for (int i = 0; i < width * height * channels; i += channels) {
            img_filtered[i + 1] = 255; 
        }
        stbi_write_png("output/output_green.png", width, height, channels, img_filtered, width * channels);
        cout << "Imagem com filtro verde salva como output_green.png" << endl;
    } else {
        cerr << "A imagem não possui canais suficientes para aplicar o filtro verde!" << endl;
    }
}

void apply_filter_invert(int width, int height, int channels, unsigned char* img_filtered, unsigned char* img ) {
    if (channels == 3 || channels == 4) {
        for (int i = 0; i < width * height * channels; i += channels) {
            img_filtered[i] = 255 - img[i];
            img_filtered[i + 1] = 255 - img[i + 1];
            img_filtered[i + 2] = 255 - img[i + 2];
        }

        stbi_write_png("output/output_inverted.png", width, height, channels, img_filtered, width * channels);
        cout << "Imagem com filtro invertido salva como output_inverted.png" << endl;
    }
}

void apply_filter_grayscale(int width, int height, int channels, unsigned char* img_filtered, unsigned char* img ) {
    if (channels == 3 || channels == 4) {
        for (int i = 0; i < width * height * channels; i += channels) {
            unsigned char r = img[i];
            unsigned char g = img[i + 1];
            unsigned char b = img[i + 2];
            unsigned char gray = (unsigned char)(0.2126f * r + 0.7152f * g + 0.0722f * b);

            img_filtered[i] = gray;
            img_filtered[i + 1] = gray;
            img_filtered[i + 2] = gray;
        }

        stbi_write_png("output/output_grayscale.png", width, height, channels, img_filtered, width * channels);
        cout << "Imagem em escala de cinza salva como output_grayscale.png" << endl;
    }
}

void apply_all_filters(int width, int height, int channels, unsigned char* img_filtered, unsigned char* img ) {
    apply_filter_green(width, height, channels, img_filtered);
    apply_filter_invert(width, height, channels, img_filtered, img ) ;
    apply_filter_grayscale(width, height, channels, img_filtered, img );
}

void apply_filter(const string& filter_type) {
    int width, height, channels;
    unsigned char* img = stbi_load("input/input.jpg", &width, &height, &channels, 0);

    if (img == nullptr) {
        cerr << "Erro ao abrir a imagem!" << endl;
        return;
    }

    unsigned char* img_filtered = (unsigned char*)malloc(width * height * channels);

    if (img_filtered == nullptr) {
        cerr << "Erro ao alocar memória para a imagem filtrada!" << endl;
        stbi_image_free(img);
        return;
    }

    // Copia a imagem original para img_filtered
    memcpy(img_filtered, img, width * height * channels);

    if (filter_type == "green") 
        apply_filter_green(width, height, channels, img_filtered);
    else if (filter_type == "invert") 
        apply_filter_invert(width, height, channels, img_filtered, img ) ;
    else if (filter_type == "grayscale") 
        apply_filter_grayscale(width, height, channels, img_filtered, img );
    else if (filter_type=="all") 
        apply_all_filters(width, height, channels, img_filtered, img );
    else 
        cerr << "Filtro desconhecido!" << endl;
    

    free(img_filtered);
    stbi_image_free(img);
}

int main(int argc, char* argv[]) {
    // Medir tempo de execução para CPU
    auto start_cpu = chrono::high_resolution_clock::now(); 

    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " <filtro>" << endl;
        cerr << "Filtros disponíveis: green, invert, grayscale" << endl;
        return 1;
    }

    string filter_type = argv[1];

    apply_filter(filter_type);

    // MEDIÇÂO NA CPU
    auto end_cpu = chrono::high_resolution_clock::now();
    auto duration_cpu = chrono::duration_cast<chrono::milliseconds>(end_cpu - start_cpu);

    cout << endl;
    cout << "Tempo de execução na CPU: " << duration_cpu.count() << " ms" << endl;


    return 0;
}
