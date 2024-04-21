#include "romanos.hpp"
#include <string>
#include <iostream>

// Função para converter um caractere romano em seu valor decimal correspondente.
int valor(char romano) {
    switch (romano) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;  // Retorna 0 para caracteres inválidos.
    }
}

// Função para converter uma string de números romanos em seu valor decimal correspondente.
int romanos_para_decimal(const std::string& num_romano) {
    int resultado = 0;
    int tamanho = num_romano.size();

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
        }
    }

    return resultado;
}

// Função principal que demonstra a conversão de um número romano para decimal.
int main() {
    std::string num_romano = "MCMIV"; // Exemplo de número romano
    int resultado = romanos_para_decimal(num_romano);
    std::cout << "O valor decimal de " << num_romano << " é " << resultado << std::endl;
    return 0;
}
