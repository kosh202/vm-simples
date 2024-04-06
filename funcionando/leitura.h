#ifndef LEITURA_H
#define LEITURA_H

#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>

void lerArquivo(int indice, int AC, int PC) {
    std::ifstream arquivo("entrada.txt"); // Abre o arquivo "dados.txt" para leitura
    if (!arquivo) { // Verifica se o arquivo foi aberto com sucesso
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
    }

    int primeiroNumero, segundoNumero, terceiroNumero;
    std::vector<int> numerosTerceiro; // Vetor para armazenar os terceiros números

    while (arquivo >> primeiroNumero >> segundoNumero) { // Lê os dois primeiros números de cada linha
        if (segundoNumero == 32) { // Se o segundo número for 32, leia o terceiro número
            if (!(arquivo >> terceiroNumero)) { // Lê o terceiro número
                std::cerr << "Erro ao ler o terceiro número." << std::endl;
            }
            numerosTerceiro.push_back(terceiroNumero); // Armazena o terceiro número no vetor
        }
    }

    // Exemplo de uso dos números lidos
    std::cout << "Primeiro número: " << primeiroNumero << std::endl;
    std::cout << "Segundo número: " << segundoNumero << std::endl;
    for (int num : numerosTerceiro) {
        std::cout << "Terceiro número: " << num << std::endl;
    }

    arquivo.close(); // Fecha o arquivo
}

int test() {
     FILE *arquivo = fopen("../entrada.txt", "r"); // Abre o arquivo "dados.txt" para leitura
    if (!arquivo) { // Verifica se o arquivo foi aberto com sucesso
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return 1;
    }

    int primeiroNumero, segundoNumero, terceiroNumero;
    char instrucao[100]; // Uma string para armazenar a instrução
    while (fscanf(arquivo, "%d %d", &primeiroNumero, &segundoNumero) != EOF) {
        if (fscanf(arquivo, "%d", &terceiroNumero) != 1) { // Verifica se há um terceiro número
            terceiroNumero = -1; // Define um valor padrão caso não haja terceiro número
        }
        fscanf(arquivo, "%[^\n]", instrucao); // Lê a instrução
        printf("Primeiro número: %d\n", primeiroNumero); // Imprime o primeiro número
        printf("Segundo número: %d\n", segundoNumero); // Imprime o segundo número
        if (terceiroNumero != -1) { // Se houver um terceiro número, imprime-o
            printf("Terceiro número: %d\n", terceiroNumero);
        }
        printf("Instrução: %s\n", instrucao); // Imprime a instrução
    }

    fclose(arquivo); // Fecha o arquivo
    return 0;
}

#endif 
