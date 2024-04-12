#include <stdio.h>
#include "verificar.h"

int main() {
    // Definição do array de char
    char meuArray[100] = "5+2"; 
    int num[100];
    int instrucoes[255];
    int numInt= 0;
    zerar(num);
    zerar(instrucoes);
    instrucoes[0]=32;//pegar item
    int test[255];
    zerar(test);

    printf("Digite uma palavra: %s\n", meuArray);

  // numero(meuArray);//por enquanto estou só printando o numero e não guardando ele
  // int quantNum = N(meuArray, num);
  int qtdValores = extrairNumeros(meuArray, num);
  prin(num, qtdValores);
  printf("\n");
  //operacao(meuArray, '*');//mostrando no print e tem guardado nas posicoes do array
  // operacao(meuArray, '/');
  int qtdSum = operacao(meuArray, '+');
  int qtdInstrucoes = ((qtdSum*2)+2)+1;
  // operacao(meuArray, '-');
  // operacao(meuArray, '(');
  // operacao(meuArray, ')');
  printf("quant instrucoes: %d\nquant valores: %d\n\n\n", qtdInstrucoes, qtdValores);

extrairOperadores(meuArray, instrucoes);
dados(qtdInstrucoes,qtdValores, instrucoes, num, test);
prin(test, (qtdInstrucoes+qtdValores));
  
    return 0;
}
