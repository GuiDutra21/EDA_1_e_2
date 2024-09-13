#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct no
{
    int quantidade;
    char palavra[17];
    struct no *prox;
}no;

typedef struct hash
{   
    no *colisoes;
}hash;

long funcaoHash(char *palavra)
{
    long posicao = 0;
    int i = 0;
    
    while (palavra[i] != '\0')
    {
        posicao = posicao * 256 + palavra[i];
        i++;
    }
    return posicao%997;
}

void computa(no **raiz, char *palavra)
{
    if(*raiz == NULL)
    {
        no *novo = malloc(sizeof(no));
        strcpy(novo->palavra, palavra);
        novo ->quantidade = 1;
        novo -> prox = NULL;
        *raiz = novo;
    }
    else
    {
        no* aux = *raiz;

        // Procura uma palavra igual
        while(aux != NULL)
        {
            if(!(strcmp(aux->palavra, palavra))) // Se for igual soma 1
            {
                aux ->quantidade++;
                return;
            }
            aux = aux ->prox;
        }

        // Chega aqui somente se não encontrar um palavra igual
        no *novo = malloc(sizeof(no));
        strcpy(novo->palavra, palavra);
        novo ->quantidade = 1;
        novo -> prox = (*raiz) -> prox;
        (*raiz) -> prox = novo;

    }
}

void print(no *raiz, char *palavra)
{
    while(raiz != NULL)
    {
        if(!(strcmp(raiz->palavra, palavra)))
        {
            printf("%d\n",raiz->quantidade);
            return;
        }
        raiz= raiz->prox;
    }
    printf("0\n"); // Caso não achar 
}

void reseta(no *raiz, char *palavra)
{
    while(raiz != NULL)
    {
        if(!(strcmp(raiz->palavra, palavra)))
        {
            raiz->quantidade = 0;
            return;
        }
        raiz= raiz->prox;
    }
}

int main()
{
    int voto;
    char palavra[17];
    hash *tabela = calloc(997, sizeof(hash));

    while(scanf("%d",&voto) != EOF)
    {   
        getchar();
        scanf("%s",palavra);
        if(voto == 1)
            computa(&tabela[funcaoHash(palavra)].colisoes, palavra);
        else if(voto == 2)
            print(tabela[funcaoHash(palavra)].colisoes, palavra);
        else
            reseta(tabela[funcaoHash(palavra)].colisoes, palavra);
    }

    free(tabela);
    return 0;
}