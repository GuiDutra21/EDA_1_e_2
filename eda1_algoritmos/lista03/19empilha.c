#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;


int empilha(celula *p, int x)
{
    celula *novo = malloc(sizeof(celula));
    if(novo)
    {
        novo -> dado = x;
        novo -> prox = p -> prox;
        p -> prox = novo;
        return 1;
    }
    return 0;
}
