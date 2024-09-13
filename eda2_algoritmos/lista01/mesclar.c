#include <stdio.h>
#include <stdlib.h>
typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

// // Função para imprimir os elementos da lista encadeada
// void imprimir_lista(celula *cabeca)
// {
//     celula *temp = cabeca->prox;
//     while (temp != NULL)
//     {
//         printf("%d ", temp->dado);
//         temp = temp->prox;
//     }
//     printf("\n");
// }

void mescla_listas(celula *l1, celula *l2, celula *l3)
{
    l1 = l1->prox;
    l2 = l2->prox;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->dado < l2->dado)
        {
            l3->prox = l1;
            l1 = l1->prox;
        }
        else
        {
            l3->prox = l2;
            l2 = l2->prox;
        }
        l3 = l3->prox;
    }

    if (l1 != NULL)
    {
        l3->prox = l1;
    }

    if (l2 != NULL)
    {
        l3->prox = l2;
    }
}

// int main()
// {
//     // Inicialização das listas
//     celula *lista1 = malloc(sizeof(celula));
//     celula *lista2 = malloc(sizeof(celula));
//     celula *lista3 = malloc(sizeof(celula));

//     // Alocando espaço para o segundo elemento e atribuindo um valor
//     lista1->prox = malloc(sizeof(celula));
//     lista1->prox->dado = 1;
//     lista1->prox->prox = NULL;

//     // Alocando espaço para o terceiro elemento e atribuindo um valor
//     lista1->prox->prox = malloc(sizeof(celula));
//     lista1->prox->prox->dado = 5;
//     lista1->prox->prox->prox = NULL;

//     // Alocando espaço para o quarto elemento e atribuindo um valor
//     lista1->prox->prox->prox = malloc(sizeof(celula));
//     lista1->prox->prox->prox->dado = 9;
//     lista1->prox->prox->prox->prox = NULL;

//     // Alocando espaço para o segundo elemento e atribuindo um valor
//     lista2->prox = malloc(sizeof(celula));
//     lista2->prox->dado = 3;
//     lista2->prox->prox = NULL;

//     // Alocando espaço para o terceiro elemento e atribuindo um valor
//     lista2->prox->prox = malloc(sizeof(celula));
//     lista2->prox->prox->dado = 4;
//     lista2->prox->prox->prox = NULL;

//     // Alocando espaço para o quarto elemento e atribuindo um valor
//     lista2->prox->prox->prox = malloc(sizeof(celula));
//     lista2->prox->prox->prox->dado = 7;
//     lista2->prox->prox->prox->prox = NULL;

//     // Impressão das listas
//     printf("Lista 1: ");
//     imprimir_lista(lista1);
//     printf("Lista 2: ");
//     imprimir_lista(lista2);

//     mescla_listas(lista1, lista2, lista3);
//     imprimir_lista(lista3);

//     return 0;
// }