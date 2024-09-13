#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x)
{
    celula *aux = malloc(sizeof(celula));
    aux->dado = x;
    aux->prox = le->prox;
    le->prox = aux;
}

void insere_antes(celula *le, int x, int y)
{
    while (le->prox != NULL)
    {
        if (le->prox->dado == y)
            break;
        le = le->prox;
    }

    celula *aux = malloc(sizeof(celula));
    aux->dado = x;
    aux->prox = le->prox;
    le->prox = aux;
}