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

int NOP(int program[], int index){
    return program[index] = 0;
}

int STA(int program[], int index){
    return program[index] = 16;
}

int LDA(int program[], int index){
    return program[index] = 32;
}

int ADD(int program[], int index){
    return program[index] = 48;
}

int OR(int program[], int index){
    return program[index] = 64;
}

int AND(int program[], int index){
    return program[index] = 80;
}

int NOT(int program[], int index){
    return program[index] = 96;
}

int JMP(int program[], int index){
    return program[index] = 128;
}

int JN(int program[], int index){
    return program[index] = 144;
}

int JZ(int program[], int index){
    return program[index] = 160;
}

int HLT(int program[], int index){
    return program[index] = 240;
}

int guardarDados(int dados[], int index, int valor){
    return dados[index] = valor;
}

int EXECUTAR(int program[], int dados[]){
    int i = 0;
    do
    {
        // switch (program[i])
        // {
        // case /* constant-expression */
        //     /* code */
        //     break;
        
        // default:
        //     break;
        // }
    } while (i < 255);
    
}

#endif /* FUNCOES_H */
