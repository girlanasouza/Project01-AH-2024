#!/bin/bash

# Verifica se o programa executável está presente
if [ ! -f "./main_02" ]; then
    echo "Programa não encontrado. Certifique-se de compilar o main_02."
    exit 1
fi

# Verifica se o argumento do filtro foi fornecido
if [ "$#" -ne 1 ]; then
    echo "Uso: $0 <filtro>"
    echo "Filtros disponíveis: green, invert, grayscale"
    exit 1
fi

# Define o filtro a ser aplicado
FILTER_TYPE=$1

# Aplica o filtro escolhido
case "$FILTER_TYPE" in
    green)
        echo "Aplicando filtro verde..."
        ./main_02 green
        ;;
    invert)
        echo "Aplicando filtro invertido..."
        ./main_02 invert
        ;;
    grayscale)
        echo "Aplicando filtro em escala de cinza..."
        ./main_02 grayscale
        ;;
    all)
        echo "Aplicando todos os filtros..."
        ./main_02 all
        ;;
    *)
        echo "Filtro desconhecido. Use: green, invert, grayscale."
        exit 1
        ;;
esac


