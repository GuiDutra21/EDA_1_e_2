#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3)
{   
    l1 = l1 -> prox;
    l2 = l2 -> prox;

    while(l1 != NULL || l2 != NULL)
    {
        if(l1 != NULL && l2 != NULL)
        {   if((l1 -> dado < l2 -> dado))
            {
                l3 -> prox = l1; // faz o l3 -> prox apontar para o elemento desejado
                l1 = l1 -> prox; // atualiza o valor do último
                l3 = l3 -> prox; // faz o l3 apontar para o proximo elemento
            }
            else
            {
                l3 -> prox = l2; // faz o l3 -> prox apontar para o elemento desejado
                l2 = l2 -> prox; // atualiza o valor do último
                l3 = l3 -> prox; // faz o l3 apontar para o proximo elemento
            }
        }
        else if (l1 != NULL)
        {
            l3 -> prox = l1; // faz o l3 -> prox apontar para o elemento desejado
            l1 = l1 -> prox; // atualiza o valor do último
            l3 = l3 -> prox; // faz o l3 apontar para o proximo elemento
        }
        else
        {
            l3 -> prox = l2; // faz o l3 -> prox apontar para o elemento desejado
            l2 = l2 -> prox; // atualiza o valor do último
            l3 = l3 -> prox; // faz o l3 apontar para o proximo elemento
        } 
    }
    l3 -> prox = NULL;
}

// void imprime(celula *le) {
//     if (le == NULL) {
//         printf("NULL\n");
//     } else {
//         while (le != NULL) {
//             printf("%d -> ",le -> dado);
//             le = le->prox;
//         }
//         printf("NULL\n");
//     }
// }

// void insere_inicio(celula *le, int x) {
//     celula *novo = malloc(sizeof(celula));
//     novo->dado = x;
//     novo->prox = le->prox;
//     le->prox = novo;
// }

// int main() {
//     // Criando a primeira lista
//     celula *head1 = malloc(sizeof(celula));
//     head1->prox = NULL;

//     // Inserindo elementos na primeira lista
//     insere_inicio(head1, 7);
//     insere_inicio(head1, 6);
//     insere_inicio(head1, 5);

//     // Imprimindo a primeira lista
//     printf("Lista 1: ");
//     imprime(head1->prox);

//     // Criando a segunda lista
//     celula *head2 = malloc(sizeof(celula));
//     head2->prox = NULL;

//     // Inserindo elementos na segunda lista
//     insere_inicio(head2, 4);
//     insere_inicio(head2, 3);

//     // Imprimindo a segunda lista
//     printf("\nLista 2: ");
//     imprime(head2->prox);

//     // Criando a terceira lista
//     celula *head3 = malloc(sizeof(celula));
//     head3->prox = NULL;

//     mescla_listas(head1,head2,head3);
//     imprime(head3->prox);

//     return 0;
// }