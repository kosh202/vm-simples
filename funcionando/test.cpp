#include <iostream>
#include <cstdio>
#include "leitura.h"

int tamanho = 255;

void zera(int array[]){
  for (int i = 0; i < tamanho; i++)
    {
      array[i] = 0;
    }
    
}

void lerArray(int array[]){
  for (int i = 0; i < tamanho; i++)
    {
      printf("%d, ", array[i]);
    }
}

int main() {
    int AC = 0;
    int PC = 0;
    
    int instrucoes[tamanho] = {0};
    zera(instrucoes);
    lerArquivo(instrucoes);
    instrucoes[130] = 2;
    instrucoes[131] = 4;
    instrucoes[132] = 5;
    lerArray(instrucoes);
    
    rodar(instrucoes,PC,AC);
    printf("PC: %d\nAC: %d", PC, AC);

    


    return 0;
}
