#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p)
{
    if (p->prox != NULL)
    {
        celula *aux = p->prox;
        p->prox = aux->prox;
        free(aux);
    }
}

void remove_elemento(celula *le, int x)
{
    while (le->prox != NULL)
    {
        if (le->prox->dado == x)
        {
            celula *aux = le->prox;
            le->prox = aux->prox;
            free(aux);
            break;
        }
        else
            le = le->prox;
    }
}

void remove_todos_elementos(celula *le, int x)
{
    while (le->prox != NULL)
    {
        if (le->prox->dado == x)
        {
            celula *aux = le->prox;
            le->prox = le->prox->prox;
            free(aux);
        }
        else
            le = le->prox;
    }
}