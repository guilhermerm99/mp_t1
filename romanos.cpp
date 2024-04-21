#include "romanos.hpp"
#include <string.h>

int valor(char romano) {
    switch (romano) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanos_para_decimal(const char *num_romano) {
    int resultado = 0;
    int tamanho = strlen(num_romano);

    for (int i = 0; i < tamanho; i++) {
        int valor1 = valor(num_romano[i]);

        if (i + 1 < tamanho) {
            int valor2 = valor(num_romano[i + 1]);

            // Comparando ambos os valores
            if (valor1 >= valor2) {
                // O valor do caractere atual é maior ou igual ao próximo
                resultado += valor1;
            } else {
                // O valor do caractere atual é menor que o próximo
                resultado += valor2 - valor1;
                i++; // Precisamos pular este caractere
            }
        } else {
            resultado += valor1;
            i++;
        }
    }

    return resultado;
}
