#include <stdio.h>
#include "verificar.h"

int main() {
    // Definição do array de char
    char meuArray[100] = "a12*+-s1/+25)("; 
    int num[100];
    int numInt= 0;
    zerar(num);

    printf("Digite uma palavra: %s\n", meuArray);

  // numero(meuArray);//por enquanto estou só printando o numero e não guardando ele
  // int quantNum = N(meuArray, num);
  int index = extrairNumeros(meuArray, num);
  prin(num, index);
  operacao(meuArray, '*');//mostrando no print e tem guardado nas posicoes do array
  // operacao(meuArray, '/');
  // operacao(meuArray, '+');
  // operacao(meuArray, '-');
  // operacao(meuArray, '(');
  // operacao(meuArray, ')');


  
    return 0;
}
