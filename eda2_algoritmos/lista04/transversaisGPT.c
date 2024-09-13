#include <stdio.h>
#include <string.h>

// Função recursiva para construir o percurso posfixo
void construirPosfixo(char *prefixo, char *infixo, int n, char *posfixo, int *indice) {
    if (n == 0) {
        return;
    }

    // O primeiro caractere do percurso prefixo é a raiz
    char raiz = prefixo[0];

    // Encontrar a posição da raiz no percurso infixo
    int posRaiz = strchr(infixo, raiz) - infixo;

    // Construir a subárvore esquerda
    construirPosfixo(prefixo + 1, infixo, posRaiz, posfixo, indice);

    // Construir a subárvore direita
    construirPosfixo(prefixo + posRaiz + 1, infixo + posRaiz + 1, n - posRaiz - 1, posfixo, indice);

    // Adicionar a raiz ao percurso posfixo
    posfixo[(*indice)++] = raiz;
}

int main() {
    int C;
    scanf("%d", &C);

    while (C--) {
        int N;
        char S1[53], S2[53];
        scanf("%d %s %s", &N, S1, S2);

        char posfixo[53];
        int indice = 0;

        // Construir o percurso posfixo
        construirPosfixo(S1, S2, N, posfixo, &indice);

        // Adicionar o caractere nulo no final da string posfixo
        posfixo[indice] = '\0';

        // Imprimir o percurso posfixo
        printf("%s\n", posfixo);
    }

    return 0;
}
