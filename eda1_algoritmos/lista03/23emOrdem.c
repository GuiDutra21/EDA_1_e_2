#include <stdio.h>
#include <stdlib.h>
typedef struct no {
int dado;
struct no *esq, *dir;
} no;

typedef struct Pilha pilha;
typedef struct Cabeca cabeca;

struct Pilha
{
    pilha *prox;
    no *atual;
    int jaFoiEsq;
};

struct Cabeca
{
    pilha *ultimo;
};


void empilhar(cabeca *cabecuda, no *novo) // insere no inicio
{
    pilha *aux = malloc(sizeof(pilha));
    aux -> atual = novo;
    aux -> jaFoiEsq = 0;

    if(cabecuda -> ultimo == NULL)
    {
        aux -> prox = NULL;
        cabecuda -> ultimo = aux;
    }
    else
    {
        aux -> prox = cabecuda -> ultimo;
        cabecuda -> ultimo = aux;
    }
}

void desempilhar(cabeca *cabecuda) 
{   
    cabecuda -> ultimo = cabecuda -> ultimo -> prox;
}

void em_ordem (no *raiz)
{
    if(raiz != NULL)
    {

        cabeca *cabeca1 = malloc(sizeof(cabeca));

        empilhar(cabeca1, raiz);

        while(cabeca1 -> ultimo != NULL)
        {
            no *atual = cabeca1 -> ultimo -> atual;

            if(atual -> esq == NULL || cabeca1 -> ultimo -> jaFoiEsq)
            {
                printf("%d ",atual -> dado);
                desempilhar(cabeca1);

                if(atual -> dir != NULL)
                    empilhar(cabeca1, atual -> dir);
            }
            else 
            {   
                cabeca1 -> ultimo -> jaFoiEsq = 1;
                empilhar(cabeca1, atual -> esq);
            }
        }

        printf("\n");
    }
}

// int main() {
    // Criando a árvore binária
    // no *raiz = malloc(sizeof(no));
    // raiz->dado = 1;

    // raiz->esq = malloc(sizeof(no));
    // raiz->esq->dado = 2;

    // raiz->dir = malloc(sizeof(no));
    // raiz->dir->dado = 3;

    // raiz->esq->esq = malloc(sizeof(no));
    // raiz->esq->esq->dado = 4;

    // raiz->esq->dir = malloc(sizeof(no));
    // raiz->esq->dir->dado = 5;

    // raiz->dir->esq = malloc(sizeof(no));
    // raiz->dir->esq->dado = 6;

    // raiz->dir->dir = malloc(sizeof(no));
    // raiz->dir->dir->dado = 7;

    // // Testando a função de ordem
    // printf("Árvore binária em ordem: ");
    // em_ordem(raiz);
    // printf("\n");

    // // Lembre-se de liberar a memória alocada após o uso
    // //free(raiz->esq->esq);
    // //free(raiz->esq->dir);
    // //free(raiz->dir->esq);
    // //free(raiz->dir->dir);
    // free(raiz->esq);
    // free(raiz->dir);
    // free(raiz);

//     return 0;
// }