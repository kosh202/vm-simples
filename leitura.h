
#ifndef LEITURA_H
#define LEITURA_H

#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <cstring>

void lerArquivo(int indice, int AC, int PC) {
    FILE *file = fopen("entrada.txt", "r");
    
    // Verifica se o arquivo foi aberto com sucesso
    if (!file) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
    }
    
    char line[1000]; // Tamanho máximo da linha
    
    // Lê e exibe cada linha do arquivo
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
        
        // Divide a linha em palavras
        char *token = strtok(line, " \t\n");
        
        // Verifica cada palavra
        while (token != NULL) {
            if (strcmp(token, "LDA") == 0) {
                printf("Tem LDA: %s \n", line);
                break; // Para a verificação se encontrou "LDA"
            }
            token = strtok(NULL, " \t\n");
        }
    }
    
    // Fecha o arquivo
    fclose(file);

}

#endif 
