// Copyright [2024] [Guilherme Ribeiro de Macedo]

#include <string> // Incluindo o cabeçalho do sistema C++ antes de qualquer outro cabeçalho
#include "mp_t1\romanos.hpp"  // Incluindo o diretório ao nomear arquivos de cabeçalho local
#include "mp_t1\catch.hpp"  // Incluindo o diretório ao nomear arquivos de cabeçalho local

int valor(char romano) {
    switch (romano) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1;  // Retorna -1 para caracteres inválidos.
    }
}

int romanos_para_decimal(const std::string& num_romano) {
    if (num_romano.empty()) return 0;  // Verifica se a string é vazia

    int resultado = 0;
    int tamanho = num_romano.size();

    for (int i = 0; i < tamanho; i++) {
        int valor1 = valor(num_romano[i]);

        if (valor1 == -1) return -1;  // Caractere inválido encontrado

        if (i + 1 < tamanho) {
            int valor2 = valor(num_romano[i + 1]);

            // Comparando ambos os valores
            if (valor1 >= valor2) {
                // O valor do caractere atual é maior ou igual ao próximo
                resultado += valor1;
            } else {
                // O valor do caractere atual é menor que o próximo
                resultado += valor2 - valor1;
                i++;  // Precisamos pular este caractere
            }
        } else {
            resultado += valor1;
        }
    }

    return resultado;
}
