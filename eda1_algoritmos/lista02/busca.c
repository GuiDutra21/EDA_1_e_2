#include <stdio.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

celula *busca (celula *le, int x)
{   
    celula *aux = le; 

    while(aux != NULL)
    {   
        if(aux -> dado == x)
            return aux;
        else
            aux = aux -> prox;
    }
    return NULL;
}

celula *busca_rec (celula *le, int x)
{
    if(le -> dado == x)
    {
        return le;
    }
    else if(le -> prox == NULL)
    {
        return NULL;
    }
    else
    {
        return busca_rec(le -> prox, x);
    }
}