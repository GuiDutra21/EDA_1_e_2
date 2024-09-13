#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void empilha(celula *p, int x)
{
    celula *novo = malloc(sizeof(celula));
    if(novo)
    {
        novo -> dado = x;
        novo -> prox = p -> prox;
        p -> prox = novo; 
    }
}

int desempilha(celula *p, int *y)
{
    if(p -> prox == NULL)
        return 0;

    celula *aux;
    aux = p -> prox;
    *y = p -> prox -> dado;
    p -> prox = p -> prox -> prox;
    
    free(aux);
    return 1;

}
