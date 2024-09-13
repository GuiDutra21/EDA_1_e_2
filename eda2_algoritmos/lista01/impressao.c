#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;

} celula;

void imprime(celula *le)
{
    while (le->prox != NULL)
    {
        printf("%d -> ", le->prox->dado);
        le = le->prox;
    }
    printf("NULL\n");
}

void imprime_rec(celula *le)
{
    if (le->prox == NULL)
        printf("NULL\n");
    else
    {
        printf("%d -> ", le->prox->dado);
        imprime_rec(le->prox);
    }
}