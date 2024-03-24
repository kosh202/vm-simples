#include <stdio.h>
#include "funcoes.h"

int main()
{
    int dados[255];
    int i = 0;
    zerar(dados);

    do
    {
        printf(" 1 - NOP\n 2 - STA\n 3 - LDA\n 4 - ADD\n 5 - OR\n 6 - AND\n 7 - NOT\n 8 - JMP\n 9 - JN\n 10 - JZ\n 11 - HLT\n 12 - Guardar dados\n 13 - run\n i:%d\n opção: ", i);

        int expression;
        if (scanf("%d", &expression) != 1)
        {
            printf("Erro de entrada. Por favor, insira um número válido.\n");

            // Limpa o buffer de entrada
            while (getchar() != '\n')
                ;
            continue;
        }

        // Limpa o buffer de entrada após o scanf
        getchar();

        switch (expression)
        {
        case 0:
            test(dados);
            break;
        case 1:
            i = pegarValor();
            NOP(dados, i);
            break;
        case 2:
            // STA - Armazena o valor no endereço especificado
            funcao(dados, i, 16);
            break;
        case 3:
            // LDA - Carrega o valor do endereço especificado
            funcao(dados, i, 32);
            break;
        case 4:
            // ADD - Adiciona o valor ao acumulador
            funcao(dados, i, 48);
            break;
        case 5:

            // OR - Realiza a operação lógica OR
            funcao(dados, i, 64);
            break;
        case 6:

            // AND - Realiza a operação lógica AND
            funcao(dados, i, 80);
            break;
        case 7:

            // NOT - Realiza a operação lógica NOT
            funcao(dados, i, 96);
            break;
        case 8:
            // JMP - Salta para o endereço especificado
            funcao(dados, i, 128);
            break;
        case 9:
            // JN - Salta para o endereço especificado se o acumulador for negativo
            funcao(dados, i, 144);
            break;
        case 10:
            // JZ - Salta para o endereço especificado se o acumulador for zero
            funcao(dados, i, 160);
            break;
        case 11:
            // HLT - Encerra a execução do programa
            i = pegarValor();
            dados[i] = 240;
            // printf("Instrução HLT - Saindo do programa.\n");
            return 0;
        default:
            printf("Instrução inválida.\n");
        }

    } while (1); // Continua indefinidamente até que o usuário selecione a opção de sair

    return 0;
}
