#include <stdio.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

celula *busca(celula *le, int x)
{
    while (le->prox != NULL)
    {
        if (le->prox->dado == x)
        {
            return le->prox;
        }
        le = le->prox;
    }

    return NULL;
}

celula *busca_rec(celula *le, int x)
{
    if (le->prox != NULL)
    {
        if (le->prox->dado == x)
        {
            return le->prox;
        }
        else
        {
            return busca_rec(le->prox, x);
        }
    }
    else
    {
        return NULL;
    }
}