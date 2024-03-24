/*
00	  NOP   	     Nenhuma operação
16	  STA    end	 Armazena acumulador no endereço “end” da memória
32	  LDA    end	 Carrega o acumulador com o conteúdo do endereço “end” da memória
48	  ADD    end	 Soma o conteúdo do endereço “end” da memória ao acumulador
64	  OR     end	 Efetua operação lógica “OU” do conteúdo do endereço “end” da memória ao acumulador
80	  AND    end	 Efetua operação lógica “E” do conteúdo do endereço “end” da memória ao acumulador
96	  NOT   	     Inverte todos os bits do acumulador
128	  JMP    end	 Desvio incondicional para o endereço “end” da memória
144	  JN     end	 Desvio condicional, se “N=1”, para o endereço “end” da memória
160	  JZ     end	 Desvio condicional, se “Z=1”, para o endereço “end” da memória
240	  HLT   	     Para o ciclo de busca-decodificação-execução
*/

#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>

int tamanho = 255;

static void zerar(int dados[])
{
    for (int i = 0; i < 255; i++)
    {
        dados[i] = 9;
    }
}

// pega um valor do terminal
static int pegarValor(int i)
{
    printf("end: ");
    int verificar = scanf("%d", &i);
    while ((verificar != 1))
    {
        while (getchar() != '\n')
            ;                                                                  // limpar o buffer
        printf("Erro de entrada. Por favor, insira um número válido.\nend: "); // reincerir numero
        verificar = scanf("end: %d", &i);
    }
    return i;
}

static void test(int dados[])
{
    for (int j = 0; j <= 255; j++)
    {
        printf("%d, ", dados[j]);
    }
    printf("\n");
}

static void NOP(int dado[], int i)
{
    dado[i] = 0;
}

static void STA(int dado[], int indice)
{ // armazenar no acumulador
    dado[indice] = 16;
    printf("end: ");
    int verificar = scanf("%d", &dado[indice + 1]);
    while (verificar != 1)
    {
        while (getchar() != '\n')
            ;                                                                  // limpar o buffer
        printf("Erro de entrada. Por favor, insira um número válido.\nend: "); // reincerir numero
        verificar = scanf("%d", &dado[indice + 1]);
    }
}

static void LDA(int dado[], int indice)
{
    dado[indice] = 32;
    printf("end: ");
    int verificar = scanf("%d", &dado[indice + 1]);
    while (verificar != 1)
    {
        while (getchar() != '\n')
            ;                                                                  // limpar o buffer
        printf("Erro de entrada. Por favor, insira um número válido.\nend: "); // reincerir numero
        verificar = scanf("%d", &dado[indice + 1]);
    }
}

// Defina protótipos de outras funções do Neander aqui, se necessário

#endif /* NEANDER_FUNCTIONS_H */
