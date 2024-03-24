#include <stdio.h>
#include "funcoes.h"

int main()
{
    int dados[255];
    bool inicio = true;
    int expression;
    int i = 0;
    zerar(dados);

    do
    {
        printf(" 1 - NOP\n 2 - STA\n 3 - LDA\n 4 - ADD\n 5 - OR\n 6 - AND\n 7 - NOT\n 8 - JMP\n 9 - JN\n 10 - JZ\n 11 - HLT\n 12 - Guardar dados\n 13 - run\n i:%d\n", i);

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
            i = pegarValor(i);
            NOP(dados, i);
            i++;
            break;
        case 2:
            i = pegarValor(i);
            STA(dados, i);
            i += 2;
            break;
        case 3:
            i = pegarValor(i);
            LDA(dados, i);
            i += 2;
        case 4:
            // i = pegarValor(i);
            // ADD(dados, i);
        case 11:
            printf("Instrução HLT - Saindo do programa.\n");
            break;
        default:
            printf("Instrução inválida.\n");
        }

    } while (inicio);

    return 0;
}
