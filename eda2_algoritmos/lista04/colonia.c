#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    char alimento[11];
    struct No *esq, *dir;
} no;

typedef struct Colonia
{   
    int idColonia;
    no *raiz;
} colonia;

int inserir(no **raiz, char *palavra)
{   
    if (*raiz == NULL)
    {
        no *novo = malloc(sizeof(no));
        novo->esq = NULL;
        novo->dir = NULL;
        strcpy(novo->alimento, palavra);
        *raiz = novo;
        return 0; 
    }
    int compara = strcmp((*raiz)->alimento, palavra);
    if (compara == 0) // Se for igual
    {
        return 1;
    }
    else if (compara > 0)
    {
        return inserir(&(*raiz)->esq, palavra);
    }
    else
    {
        return inserir(&(*raiz)->dir, palavra);
    }
}

int hash(int idColonia)
{
    return idColonia % 1048573;
}

int main()
{
    colonia *colonias = calloc(1048576, sizeof(colonia));

    int idColonia;
    char alimento[11];
    while (scanf("%d %s", &idColonia, alimento) != EOF)
    {   
        int posicao = hash(idColonia);
        while (idColonia != colonias[posicao].idColonia)
        {
            if (colonias[posicao].idColonia == 0)
            {
                colonias[posicao].idColonia = idColonia;
                break;
            }
            else
                posicao = (posicao + 1) % 1048576;
        }
        
        if (colonias[posicao].raiz == NULL)
        {
            colonias[posicao].raiz = malloc(sizeof(no));
            strcpy(colonias[posicao].raiz->alimento, alimento);
            colonias[posicao].raiz->esq = NULL;
            colonias[posicao].raiz->dir = NULL;
        }
        else
        {
            if (inserir(&colonias[posicao].raiz, alimento))
            {
                printf("%d\n", idColonia);
            }
        }
    }
    
    return 0;
}