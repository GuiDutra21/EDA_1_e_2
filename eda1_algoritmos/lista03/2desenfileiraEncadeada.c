#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int desenfileira(celula *f, int *y)
{   
    if(f -> prox != NULL)
    {
        celula *aux = f -> prox;
        if(aux)
        {
            f -> prox = aux -> prox;
            *y = aux -> dado;
            free(aux);
            return 1;
        }
    }
    return 0;
}