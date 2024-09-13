#include <stdio.h>
#include <stdlib.h>
typedef struct lista lista;

struct lista
{
    int numero;
    lista *prox;
};

int main()
{
    lista *p1 = malloc(sizeof(lista));
    lista *p2 = malloc(sizeof(lista));
    lista *p3 = malloc(sizeof(lista));

    p1 -> numero = 1;
    p1 -> prox = p2;
    p2 -> numero = 2;
    p2 -> prox = p3;
    p3 -> numero = 3;
    p3 -> prox = NULL;

    lista *aux = malloc(sizeof(lista));

    aux = p1;
    aux -> prox = p3; // muda o apontamento de p1 tambem

    printf("%d %d\n",p1 -> prox -> numero, aux -> prox ->numero );

}