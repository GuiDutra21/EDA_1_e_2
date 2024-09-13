#include <stdio.h>
#include <stdlib.h>
typedef struct celula {
int dado;
struct celula *prox;
} celula;

void divide_lista(celula *l, celula *l1, celula *l2)
{   
    while(l -> prox != NULL)
    {   
        if(l -> prox -> dado % 2 == 0)
        {
            l2 -> prox = l -> prox;
            l2 = l2 -> prox;
        }
        else
        {
            l1 -> prox = l -> prox;
            l1 = l1 -> prox;
        }
        l = l -> prox;
    }
    l1 ->prox = NULL;
    l2 ->prox = NULL;
}