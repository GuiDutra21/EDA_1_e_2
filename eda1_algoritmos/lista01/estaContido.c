#include <stdio.h>

#define MAX_SIZE  10000 // Defina um tamanho máximo para o vetor

int main() {
    int tamanho, numero;
    
    scanf("%d", &tamanho);

    if (tamanho <= 0 || tamanho > MAX_SIZE) {
        return 1; // Retorne um código de erro
    }

    int vetor[MAX_SIZE];

    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    scanf("%d", &numero);

    int pertence = 0; // Usado para indicar se o número pertence ao vetor

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == numero) {
            pertence = 1;
            break; // Se o número for encontrado, saia do loop
        }
    }

    if (pertence) {
        printf("pertence\n");
    } else {
        printf("nao pertence\n");
    }

    return 0;
}