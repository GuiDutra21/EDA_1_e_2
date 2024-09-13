#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3)
{   
    celula *ultimo_l1 = l1->prox;
    celula *ultimo_l2 = l2->prox;
    celula *atual = l3; // Usado para rastrear o último elemento em l3

    while (ultimo_l1 != NULL && ultimo_l2 != NULL)
    {
        if (ultimo_l1->dado < ultimo_l2->dado)
        {
            atual->prox = ultimo_l1;
            ultimo_l1 = ultimo_l1->prox;
        }
        else
        {
            atual->prox = ultimo_l2;
            ultimo_l2 = ultimo_l2->prox;
        }
        atual = atual->prox;
    }

    // Adiciona o restante da lista não nula a l3
    if (ultimo_l1 != NULL)
        atual->prox = ultimo_l1;
    else
        atual->prox = ultimo_l2;
}


void imprime(celula *le) {
    if (le == NULL) {
        printf("NULL\n");
    } else {
        while (le != NULL) {
            printf("%d -> ",le -> dado);
            le = le->prox;
        }
        printf("NULL\n");
    }
}

void insere_inicio(celula *le, int x) {
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
}

int main() {
    // Criando a primeira lista
    celula *head1 = malloc(sizeof(celula));
    head1->prox = NULL;

    // Inserindo elementos na primeira lista
    insere_inicio(head1, 7);
    insere_inicio(head1, 6);
    insere_inicio(head1, 5);

    // Imprimindo a primeira lista
    printf("Lista 1: ");
    imprime(head1->prox);

    // Criando a segunda lista
    celula *head2 = malloc(sizeof(celula));
    head2->prox = NULL;

    // Inserindo elementos na segunda lista
    insere_inicio(head2, 4);
    insere_inicio(head2, 3);

    // Imprimindo a segunda lista
    printf("\nLista 2: ");
    imprime(head2->prox);

    // Criando a terceira lista
    celula *head3 = malloc(sizeof(celula));
    head3->prox = NULL;

    mescla_listas(head1,head2,head3);
    imprime(head3->prox);
    imprime(head2->prox);
    imprime(head1->prox);
    return 0;
}
