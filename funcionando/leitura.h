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
void NOP(int &PC, int &AC){
    PC ++;
};

void STA(int &PC, int &AC, int memoria[]){
    memoria[PC+1] = AC;
    PC+=2;
}

void LDA(int &PC, int &AC, int memoria[]){
    AC = memoria[memoria[PC+1]];
    PC+=2;
}

void ADD(int &PC, int &AC, int memoria[]){
    AC+= memoria[memoria[PC+1]];
    PC+=2;
}

void OR(int &PC, int &AC, int memoria[]){
    int resultado = 0;
    int expoente = 0;
    int binario1 = decimalParaBinario(AC);
    int binario2 = decimalParaBinario(memoria[PC+1]);
    
    while (binario1 > 0 || binario2 > 0) {
        int bit1 = binario1 % 10;
        int bit2 = binario2 % 10;
        int bitResultado = (bit1 == 1 || bit2 == 1) ? 1 : 0;
        resultado += bitResultado * std::pow(10, expoente);
        binario1 /= 10;
        binario2 /= 10;
        expoente++;
    }  
    PC+=2;

}

void AND(int &PC, int &AC, int memoria[]) {
    int resultado = 0;
    int expoente = 0;
    int binario1 = decimalParaBinario(AC);
    int binario2 = decimalParaBinario(memoria[PC+1]);

    while (binario1 > 0 && binario2 > 0) {
        int bit1 = binario1 % 10;
        int bit2 = binario2 % 10;
        int bitResultado = (bit1 == 1 && bit2 == 1) ? 1 : 0;
        resultado += bitResultado * std::pow(10, expoente);
        binario1 /= 10;
        binario2 /= 10;
        expoente++;
    }
    PC+=2;
}

// Função para fazer a operação lógica NOT em um número binário
void NOTBinario(int &PC, int &AC) {
    int resultado = 0;
    int expoente = 0;
    int binario = decimalParaBinario(AC);
    
    while (binario > 0) {
        int bit = binario % 10;
        int bitNOT = (bit == 1) ? 0 : 1;
        resultado += bitNOT * std::pow(10, expoente);
        binario /= 10;
        expoente++;
    }
    
    // Se o resultado não tiver 8 dígitos, preencher com zeros à esquerda
    while (expoente < 8) {
        resultado += 0 * std::pow(10, expoente);
        expoente++;
    }
    
    AC = binarioParaDecimal(resultado);
    PC++;
}

// Função para o salto incondicional JMP
void JMP(int &PC, int memoria[]) {
    PC = memoria[PC+1]; // Retorna o endereço para onde o PC deve ser pulado
}

// Função para o salto condicional se o AC for negativo (JN)
void JN(int &PC, int &AC, int memoria[]) {
    if (AC < 0) {
        memoria[PC+1]; // Retorna o endereço para onde o PC deve ser pulado se AC for negativo
    } else {
        PC += 2; // Retorna o próximo endereço se AC for positivo ou zero
    }
}

// Função para o salto condicional se o AC for zero (JZ)
void JZ(int &PC, int &AC, int memoria[]) {
    if (AC == 0) {
        PC = memoria[PC+1]; // Retorna o endereço para onde o PC deve ser pulado se AC for zero
    } else {
        PC+=2; // Retorna o próximo endereço se AC for diferente de zero
    }
}

// Função para a instrução HLT (halt)
int HLT() {
    return -1; // Retorna -1 para indicar que o programa deve ser interrompido
}

//leitura do arquivo depois implemntar as fuções para rodar o neader
void lerArquivo(int instrucoes[]) {
    FILE *arquivo = fopen("../entrada.txt", "r"); // Abre o arquivo "entrada.txt" para leitura
    if (!arquivo) { // Verifica se o arquivo foi aberto com sucesso
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return;
    }

    int primeiroNumero, segundoNumero, terceiroNumero;
    char instrucao[100]; // Uma string para armazenar a instrução
    int i=0;
    while (fscanf(arquivo, "%d %d", &primeiroNumero, &segundoNumero) != EOF) {
        if ((segundoNumero == 0)|| (segundoNumero == 96) || (segundoNumero == 240)) {
            terceiroNumero = -1; // Define um valor padrão caso não haja terceiro número
            instrucoes[i]=segundoNumero;
            i++;
        } else {
            fscanf(arquivo, "%d", &terceiroNumero);
            instrucoes[i]=segundoNumero;
            instrucoes[i+1]=terceiroNumero;
            i+=2;

        }
        fscanf(arquivo, " %[^\n]", instrucao); // Lê a instrução
        // printf("Primeiro número: %d\n", primeiroNumero); // Imprime o primeiro número
        // printf("Segundo número: %d\n", segundoNumero); // Imprime o segundo número
        if (terceiroNumero != -1) { // Se houver um terceiro número, imprime-o
            // printf("Terceiro número: %d\n", terceiroNumero);
        }
        // printf("Instrução: %s\n", instrucao); // Imprime a instrução
    }

    fclose(arquivo); // Fecha o arquivo
}

void rodar(int array[], int &PC, int &AC){

    while (array[PC] != 240)
    {
        printf("PC: %d\n AC: %d\n", PC, AC);

        switch(array[PC]) {
        case 0:
            NOP(PC,AC);
            break;
        case 16:
            STA(PC,AC,array);
            break;
        case 32:
            LDA(PC,AC,array);
            break;
        case 48:
            ADD(PC,AC,array);
            break;
        case 64:
            OR(PC,AC,array);
            break;
        case 80:
            AND(PC,AC,array);
            break;
        case 96:
            NOTBinario(PC, AC);
            break;
        case 128:
            JMP(PC,array);
            break;
        case 144:
            JN(PC,AC, array);
            break;
        case 160:
            JZ(PC,AC,array);
            break;
        case 240:
            HLT();
            PC++;
            break;
        default:
            printf("instrucao invalida");
            break;
            // code block
        }
    }
} 


#endif
