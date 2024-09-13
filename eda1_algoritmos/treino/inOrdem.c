#include <stdio.h>
#include <stdlib.h>

typedef struct No no;

struct No
{
    int dado;
    no *esq, *dir;
};

typedef struct Pilha pilha;

struct Pilha
{
    no *atual;
    pilha *prox;
};

void empilha(pilha *cabeca, no *novo)
{
    pilha *novoP = malloc(sizeof(pilha));
    novoP->atual = novo;
    novoP->prox = cabeca->prox;
    cabeca->prox = novoP;
}

no *desempilha(pilha *cabeca)
{
    pilha *aux = cabeca->prox;

    if (cabeca->prox != NULL)
        cabeca->prox = cabeca->prox->prox;
    else
        cabeca->prox = NULL;

    return aux->atual;
}

void loop(pilha *cabeca, no *atual)
{
    int voltando = 0;
    while (cabeca->prox != NULL)
    {
        if (voltando)
        {
            printf("%d ", atual->dado);
            if (atual->dir != NULL)
                atual = atual->dir;
            voltando = 0;
        }
        else
        {
            if (atual->esq != NULL)
            {
                empilha(cabeca, atual);
                atual = atual->esq;
            }
            else
            {
                printf("%d ", atual->dado);
                if (atual->dir != NULL)
                    atual = atual->dir;
                else
                    atual = desempilha(cabeca);
                voltando = 1;
            }
        }
    }
}

void inOrdem(no *raiz)
{
    pilha *cabeca = malloc(sizeof(pilha));

    // a raiz tem filho a esquerda?
    if (raiz->esq != NULL)
    {
        empilha(cabeca, raiz);
        loop(cabeca, raiz->esq);
    }
    // no *atual = raiz;
}

int main()
{
    // Criando a árvore binária
    no *raiz = malloc(sizeof(no));
    raiz->dado = 1;

    raiz->esq = malloc(sizeof(no));
    raiz->esq->dado = 2;

    raiz->dir = malloc(sizeof(no));
    raiz->dir->dado = 3;

    inOrdem(raiz);
    return 0;
}