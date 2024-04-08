#include <iostream>
#include <cmath> // Para usar a função pow

// Função para converter decimal para binário
int decimalParaBinario(int decimal) {
    int binario = 0;
    int digito, expoente = 0;
    
    while (decimal > 0) {
        digito = decimal % 2;
        binario += digito * std::pow(10, expoente);
        decimal /= 2;
        expoente++;
    }
    
    return binario;
}

// Função para fazer a operação lógica OR entre dois números binários
int ORBinario(int binario1, int binario2) {
    int resultado = 0;
    int expoente = 0;
    
    while (binario1 > 0 || binario2 > 0) {
        int bit1 = binario1 % 10;
        int bit2 = binario2 % 10;
        int bitResultado = (bit1 == 1 || bit2 == 1) ? 1 : 0;
        resultado += bitResultado * std::pow(10, expoente);
        binario1 /= 10;
        binario2 /= 10;
        expoente++;
    }
    
    return resultado;
}

int main() {
    int decimal1 = 9;  // 1001 em binário
    int decimal2 = 3;  // 0011 em binário
    
    // Convertendo decimais para binários
    int binario1 = decimalParaBinario(decimal1);
    int binario2 = decimalParaBinario(decimal2);

    // Fazendo a operação lógica OR entre os números binários
    int resultado = ORBinario(binario1, binario2);
    
    // Exibindo o resultado
    std::cout << "Resultado: " << resultado << std::endl;

    return 0;
}
