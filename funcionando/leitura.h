#ifndef LEITURA_H
#define LEITURA_H

#include <cstdio>


// Função que converte um número decimal para binário
long long decimalParaBinario(int decimal) {
    long long binario = 0;
    int resto, i = 1;

    while (decimal != 0) {
        resto = decimal % 2;
        decimal /= 2;
        binario += resto * i;
        i *= 10;
    }

    return binario;
}

// Função que converte um número binário para decimal
int binarioParaDecimal(long long binario) {
    int decimal = 0, i = 0, resto;

    while (binario != 0) {
        resto = binario % 10;
        binario /= 10;
        decimal += resto << i;
        ++i;
    }

    return decimal;
}

void NOP(int PC, int AC, int valor){};

//leitura do arquivo depois implemntar as fuções para rodar o neader
void lerArquivo(int i, int PC, int AC) {
    FILE *arquivo = fopen("../entrada.txt", "r"); // Abre o arquivo "entrada.txt" para leitura
    if (!arquivo) { // Verifica se o arquivo foi aberto com sucesso
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return;
    }

    int primeiroNumero, segundoNumero, terceiroNumero;
    char instrucao[100]; // Uma string para armazenar a instrução
    while (fscanf(arquivo, "%d %d", &primeiroNumero, &segundoNumero) != EOF) {
        if (segundoNumero == 32) {
            fscanf(arquivo, "%d", &terceiroNumero);
        } else {
            terceiroNumero = -1; // Define um valor padrão caso não haja terceiro número
        }
        fscanf(arquivo, " %[^\n]", instrucao); // Lê a instrução
        printf("Primeiro número: %d\n", primeiroNumero); // Imprime o primeiro número
        printf("Segundo número: %d\n", segundoNumero); // Imprime o segundo número
        if (terceiroNumero != -1) { // Se houver um terceiro número, imprime-o
            printf("Terceiro número: %d\n", terceiroNumero);
        }
        printf("Instrução: %s\n", instrucao); // Imprime a instrução
    }

    fclose(arquivo); // Fecha o arquivo
}

#endif
