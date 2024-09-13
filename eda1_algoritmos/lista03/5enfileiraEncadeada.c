#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
}celula;

celula *enfileira(celula *f, int x)
{
        celula *novo = malloc(sizeof(celula));
        if(novo)
        {   
            novo -> prox = f -> prox;
            f -> dado = x;
            f -> prox = novo;
            return novo;
        }
        return NULL;
}