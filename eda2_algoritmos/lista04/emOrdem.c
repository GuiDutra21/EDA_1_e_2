#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int dado;
   struct no *esq, *dir;
} no;

typedef struct pilha
{
    struct no *no;
    struct pilha *prox;
}pilha;

void empilha(pilha * cabeca, no *no)
{   
    pilha *novo = malloc(sizeof(pilha));
    novo -> no = no;
    novo -> prox = cabeca -> prox;
    cabeca -> prox = novo;
}

no *desempilha(pilha *cabeca)
{
    pilha *aux = cabeca -> prox;
    if(cabeca -> prox != NULL)
    {
        cabeca -> prox = aux -> prox;
        no *n = aux -> no;
        free(aux);
        return n;
    }
    else
        return NULL;
}

void em_ordem (no *raiz)
{  
    if(raiz == NULL)
        return;

    pilha *cabeca = malloc(sizeof(pilha));
    cabeca ->prox = NULL;
    no *atual = raiz;

    while (atual != NULL)
    {
        if(atual ->esq != NULL && atual -> dir != NULL)
        {
            empilha(cabeca, atual);
            atual = atual -> esq;
        }
        else if(atual -> esq != NULL)
        {
            empilha(cabeca, atual);
            atual = atual -> esq;
        }
        else if( atual -> dir != NULL)
        {
            printf("%d ",atual -> dado);
            atual = atual -> dir;
        }
        else
        {
            printf("%d ",atual -> dado);
            atual = desempilha(cabeca);

            if(atual == NULL)
            {
                printf("\n");
                return;
            }

            while(atual != NULL)
            {
                printf("%d ",atual -> dado);
                if(atual -> dir == NULL)
                    atual = desempilha(cabeca);
                else
                {
                    atual = atual -> dir;
                    break;
                }
            }
        }
    }
    printf("\n");
}

// // Função para criar um novo nó
// no* novoNo(int dado) {
//     no* node = (no*)malloc(sizeof(no));
//     node->dado = dado;
//     node->esq = NULL;
//     node->dir = NULL;
//     return node;
// }

// int main() {
//     // Criação dos nós conforme a imagem
//     // no* raiz = novoNo(2);
//     // raiz->esq = novoNo(5);
//     // raiz->dir = novoNo(7);

//     // raiz->esq->esq = novoNo(3);
//     // raiz->esq->dir = novoNo(8);
//     // raiz->esq->dir->esq = novoNo(4);

//     // raiz->dir->esq = novoNo(1);
//     // raiz->dir->dir = novoNo(6);
//     // raiz->dir->esq->dir = novoNo(9);
    
//     // Criação dos nós conforme a imagem
//     no* raiz = novoNo(1);
//     raiz->esq = novoNo(2);
//     raiz->dir = NULL;

//     raiz->esq->esq = novoNo(3);
//     raiz->esq->dir = NULL;

//     raiz->esq->esq->esq = novoNo(4);
//     raiz->esq->esq->dir = NULL;
//     // Impressão da árvore em pré-ordem
//     printf("Pre-ordem da árvore: ");
//     em_ordem(raiz);

//     return 0;
// } 