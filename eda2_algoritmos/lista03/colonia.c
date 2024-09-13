#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct no
{
    int id;
    char palavra[11];
    struct no *prox;
} no;

typedef struct hash
{
    no *colisoes;
} hash;

int funcaoHash(int id)
{
    return id % 104729;
}

void verifica(no **raiz, char *palavra, int id)
{
    if (*raiz == NULL) // Se for NULL apenas acrescenta
    {
        no *novo = malloc(sizeof(no));
        strcpy(novo->palavra, palavra);
        novo->id = id;
        novo->prox = NULL;
        *raiz = novo;
    }
    else
    {
        no *aux = *raiz;
        // Procura um id igual
        while (aux != NULL)
        {
            if (aux->id == id)
            {
                if (!(strcmp(palavra, aux->palavra))) // Se o mantimento for igual printa o id
                {
                    printf("%d\n", id);
                    return;
                }
            }
            aux = aux->prox;
        }

        // Chega aqui somente quando precisa acrescentar um novo mantimento
        no *novo = malloc(sizeof(no));
        strcpy(novo->palavra, palavra);
        novo->id = id;
        novo->prox = (*raiz)->prox;
        (*raiz)->prox = novo;
    }
}

int main()
{
    int id;
    char palavra[11];
    hash *tabela = calloc(104729, sizeof(hash));

    while (scanf("%d", &id) != EOF)
    {
        getchar();
        scanf("%s", palavra);
        verifica(&tabela[funcaoHash(id)].colisoes,palavra,id);
    }
    free(tabela);
    return 0; 
}