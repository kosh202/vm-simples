#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "funcoes.h"

int main() {
    int dados[255];
    bool n = false;
    bool z = true;
    int AC = 0;
    int PC = 0;
    bool inicio = true;
    int expression;
    int program[255];
    int i = 0;
    int endDado;

    do {
        printf("\
        1 - NOP\n\
        2 - STA\n\
        3 - LDA\n\
        4 - ADD\n\
        5 - OR\n\
        6 - AND\n\
        7 - NOT\n\
        8 - JMP\n\
        9 - JN\n\
        10 - JZ\n\
        11 - HLT\n\
        12 - Guardar dados\n\
        13 - run\n");

        scanf("%d", &expression);

        switch (expression) {
            case 1: // NOP
                // Não faz nada, apenas avança para a próxima instrução
                NOP(program, i);
                i++;
                break;
            case 2: // STA
                // Armazena o valor de AC na posição de memória especificada pelo próximo valor do programa
                STA(program, i);
                i++;
                printf("end: ");
                scanf("%d", &endDado);
                dados[i];
                i++;
                break;
            case 3: // LDA
                // Carrega o valor da posição de memória especificada pelo próximo valor do programa em AC
                LDA(program, i);
                i++;
                printf("end: ");
                scanf("%d", &endDado);
                dados[i];
                i++;
                break;
            case 4: // ADD
                // Soma o valor da posição de memória especificada pelo próximo valor do programa a AC
                ADD(program, i);
                i++;
                printf("end: ");
                scanf("%d", &endDado);
                dados[i];
                i++;
                break;
            case 5: // OR
                // Realiza uma operação OR bitwise entre o valor de AC e o valor da posição de memória especificada pelo próximo valor do programa
                OR(program, i);
                i++;
                printf("end: ");
                scanf("%d", &endDado);
                dados[i];
                i++;
                break;
            case 6: // AND
                // Realiza uma operação AND bitwise entre o valor de AC e o valor da posição de memória especificada pelo próximo valor do programa
                AND(program, i);
                i++;
                printf("end: ");
                scanf("%d", &endDado);
                dados[i];
                i++;
                break;
            case 7: // NOT
                // Inverte todos os bits do valor de AC
                NOT(program, i);
                i++;
                break;
            case 8: // JMP
                // Pula para a posição de memória especificada pelo próximo valor do programa
                JMP(program, i);
                i++;
                printf("end: ");
                scanf("%d", &endDado);
                dados[i];
                i++;
                break;
            case 9: // JN
                // Pula para a posição de memória especificada pelo próximo valor do programa se o sinal de AC for negativo
                JN(program, i);
                i++;
                printf("end: ");
                scanf("%d", &endDado);
                dados[i];
                i++;
                break;
            case 10: // JZ
                // Pula para a posição de memória especificada pelo próximo valor do programa se AC for zero
                JZ(program, i);
                i++;
                printf("end: ");
                scanf("%d", &endDado);
                dados[i];
                i++;
                break;
            case 11: // HLT
                // Encerra o programa
                HLT(program, i);
                i++;
                break;
            case 12: // Guardar dados
                // Implemente a lógica para salvar dados conforme necessário
                int index;
                int valor;
                bool a = true;
                do
                {
                    printf("onde vai guardar: ");
                    scanf("%d", index);
                    printf("valor: ");
                    scanf("%d", valor);
                    guardarDados(dados, index, valor);
                    printf("deseja continuar (1 - sim | 0 - nao): ");
                    scanf("%d", &a);
                } while (a);
                break;
            case 13: // run
                // Implemente a lógica para executar o programa
                
                break;
            default:
                // Tratar entrada inválida
                printf("Instrução inválida!\n");
                break;
        }
    } while (inicio);

    return 0;
}
