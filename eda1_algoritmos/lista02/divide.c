#include <stdio.h>
#include <stdlib.h>
typedef struct celula {
int dado;
struct celula *prox;
} celula;

void divide_lista(celula *l, celula *l1, celula *l2)
{   

    celula *l1_atual = l1;
    celula *l2_atual = l2;

    while(l -> prox != NULL)
    {   
        if(l -> prox -> dado % 2 == 0)
        {
            l2_atual -> prox = l -> prox;
            l2_atual = l2_atual -> prox;
        }
        else
        {
            l1_atual -> prox = l -> prox;
            l1_atual = l1_atual -> prox;
        }

        l = l -> prox;
    }
    l1_atual ->prox = NULL;
    l2_atual ->prox = NULL;
}

// void print(celula *aux) {
//     if (aux != NULL) 
//     {
//         printf("%d\t", aux->dado);
//         print(aux->prox);
//     }
//     printf("\n");
// }

// int main()
// {

//     celula *l = malloc(sizeof(celula));
//     l -> dado = 0;
//     l -> prox = malloc(sizeof(celula));
//     l -> prox -> dado = 15;
//     l -> prox -> prox = malloc(sizeof(celula));
//     l -> prox -> prox ->  dado = 10;
//     l -> prox -> prox -> prox = malloc(sizeof(celula));
//     l -> prox -> prox -> prox ->  dado = 11;
//     l -> prox -> prox-> prox -> prox = malloc(sizeof(celula));
//     l -> prox -> prox -> prox -> prox ->  dado = 10;
//     l -> prox -> prox -> prox -> prox -> prox = NULL;

//     celula *aux = l;
//     celula *l1 = malloc(sizeof(celula));
//     l1 -> prox = NULL;
//     celula *l2 = malloc(sizeof(celula)); 
//     l2 -> prox = NULL;
//     print(aux);
//     divide_lista(l,l1,l2);
//     print(l1);
//     print(l2);
   
//    return 0;
// }