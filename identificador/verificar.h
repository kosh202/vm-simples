#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <iostream>
// #include <ctype.h>

void prin(int num[], int tamanho){
  for (int i = 0; i < tamanho; i++)
  {
    printf("%d\n", num[i]);
  }
  
}

void zerar(int num[]){
  for (int i = 0; i < 100; i++)
  {
    num[i] = 0;
  }
  
}

void limpar(char palavra[]) {
  for (int i = 0; i < 100; i++) {
    palavra[i] = '\0'; // Define cada elemento do array como um caractere nulo
  }
}

int extrairNumeros(char arrChar[], int arrInt[]) {
    int numInt = 0; // Inicializa o contador de números inteiros
    // Itera sobre cada caractere na string
    for (int i = 0; arrChar[i] != '\0'; ++i) {
        // Verifica se o caractere atual é um dígito
        if (isdigit(arrChar[i])) {
            // Converte a substring contendo o número para inteiro e armazena no array de inteiros
            arrInt[numInt++] = atoi(&arrChar[i]);
            // Avança o índice para o próximo caractere não numérico
            while (isdigit(arrChar[i]))
                ++i;
        }
    }
    return numInt;
}

static void operacao(char palavra[], char operacao) {
  char local[100];
  limpar(local);
  int indices[100];
  int index = 0;
  for (int i = 0; i < 100; i++) {
    if (palavra[i] == operacao) {
      local[i] = operacao;
      indices[index] = i;
      index++;
    }
  }
  for (int i = 0; i < 100; i++) {
    if (palavra[i] != '\0') {
      printf("%c: %c\n", palavra[i], local[i]);
    }
  }
}

#endif
