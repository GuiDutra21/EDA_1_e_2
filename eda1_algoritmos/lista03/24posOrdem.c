#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

typedef struct Pilha pilha;
typedef struct Cabeca cabeca;

struct Pilha
{
    no *atual;
    pilha *prox;
    int jaFoiEsq;
    int jaFoiDir;
};

struct Cabeca
{
    pilha *topo;
};

void empilhar(cabeca *cabecona, no *novo)
{
    pilha *pilhona = malloc(sizeof(pilha));
    pilhona ->atual = novo;
    pilhona -> jaFoiDir = 0;
    pilhona -> jaFoiEsq = 0;

    pilhona -> prox = cabecona -> topo;
    cabecona -> topo = pilhona;
}

void desempilhar(cabeca *cabecona)
{
    cabecona -> topo = cabecona -> topo -> prox;
}

void pos_ordem(no *raiz)
{
    if(raiz != NULL)
    {
        cabeca *cabeca1 = malloc(sizeof(cabeca));
        empilhar(cabeca1, raiz);
        no *atual;

        while(cabeca1 -> topo != NULL)
        {   
            atual = cabeca1 -> topo -> atual;

            if((atual -> esq == NULL && atual -> dir == NULL) || (cabeca1 -> topo -> jaFoiDir && cabeca1 -> topo -> jaFoiEsq))
            {
                printf("%d ",atual -> dado);
                desempilhar(cabeca1);
            }
            else if(atual -> esq == NULL || atual -> dir == NULL)
            {
                if(atual -> dir == NULL)
                {
                    cabeca1 -> topo -> jaFoiDir = 1;
                    cabeca1 -> topo -> jaFoiEsq = 1;
                    empilhar(cabeca1, atual -> esq);
                }
                else
                {
                    cabeca1 -> topo -> jaFoiEsq = 1;
                    cabeca1 -> topo -> jaFoiDir = 1;
                    empilhar(cabeca1, atual -> dir);
                }
            }
            else if(atual -> esq != NULL && cabeca1 -> topo -> jaFoiEsq != 1)
            {
                cabeca1 -> topo -> jaFoiEsq = 1;
                empilhar(cabeca1, atual -> esq);
            }          
            else if(atual -> dir != NULL && cabeca1 -> topo -> jaFoiDir != 1)
            {
                cabeca1 -> topo -> jaFoiDir = 1;
                empilhar(cabeca1, atual -> dir);
            }          
        }
        printf("\n");
    }
}   

// int main() {
//     //Criando a árvore binária
//     no *raiz = malloc(sizeof(no));
//     raiz->dado = 1;

//     raiz->esq = malloc(sizeof(no));
//     raiz->esq->dado = 2;

//     raiz->dir = malloc(sizeof(no));
//     raiz->dir->dado = 3;

//     raiz->esq->esq = malloc(sizeof(no));
//     raiz->esq->esq->dado = 4;

//     raiz->esq->dir = malloc(sizeof(no));
//     raiz->esq->dir->dado = 5;

//     raiz->dir->esq = malloc(sizeof(no));
//     raiz->dir->esq->dado = 6;

//     raiz->dir->dir = malloc(sizeof(no));
//     raiz->dir->dir->dado = 7;

//     // Testando a função de ordem
//     printf("Árvore binária em ordem: ");
//     pos_ordem(raiz);
//     printf("\n");

//     // Lembre-se de liberar a memória alocada após o uso
//     //free(raiz->esq->esq);
//     //free(raiz->esq->dir);
//     //free(raiz->dir->esq);
//     //free(raiz->dir->dir);
//     free(raiz->esq);
//     free(raiz->dir);
//     free(raiz);

//     return 0;
// }