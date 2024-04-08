#ifndef LEITURA_H
#define LEITURA_H

#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>

int decimalParaBinario(int decimal) {
    int binario = 0;
    int digito, expoente = 0;
    
    while (decimal > 0) {
        digito = decimal % 2;
        binario += digito * std::pow(10, expoente);
        decimal /= 2;
        expoente++;
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

//end é o terceiro numero que o ler arquivo pega
void NOP(int PC, int AC, int end, int indice){
    indice ++;
};

void STA(int PC, int AC, int end, int indice, int memoria[]){
    AC = memoria[end];
    indice++;
}

void LDA(int PC, int AC, int end, int indice, int memoria[]){
    memoria[end] = AC;
    indice+=2;
}

void ADD(int PC, int AC, int end, int indice, int memoria[]){
    PC+= memoria[end];
    indice+=2;
}

void OR(int PC, int AC, int end, int indice, int memoria[]){
    int resultado = 0;
    int expoente = 0;
    int binario1 = decimalParaBinario(AC);
    int binario2 = decimalParaBinario(memoria[end]);
    
    while (binario1 > 0 || binario2 > 0) {
        int bit1 = binario1 % 10;
        int bit2 = binario2 % 10;
        int bitResultado = (bit1 == 1 || bit2 == 1) ? 1 : 0;
        resultado += bitResultado * std::pow(10, expoente);
        binario1 /= 10;
        binario2 /= 10;
        expoente++;
    }
    printf("%d", resultado);
    

}
// Função para fazer a operação lógica OR entre dois números binários
// int ORBinario(int binario1, int binario2) {
//     int resultado = 0;
//     int expoente = 0;
    
//     while (binario1 > 0 || binario2 > 0) {
//         int bit1 = binario1 % 10;
//         int bit2 = binario2 % 10;
//         int bitResultado = (bit1 == 1 || bit2 == 1) ? 1 : 0;
//         resultado += bitResultado * std::pow(10, expoente);
//         binario1 /= 10;
//         binario2 /= 10;
//         expoente++;
//     }
    
//     return resultado;
// }

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
        if ((segundoNumero == 0)|| (segundoNumero == 96) || (segundoNumero == 240)) {
            terceiroNumero = -1; // Define um valor padrão caso não haja terceiro número
            
        } else {
            fscanf(arquivo, "%d", &terceiroNumero);
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
