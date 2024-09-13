#include <stdio.h>
#include <stdlib.h> 

typedef struct no
{
    int dado;
    struct no *prox;
}no;

typedef struct 
{
    no *colisoes;
}tabela;

void insere(no **raiz, int dado)
{
    no *novo = malloc(sizeof(no));
    novo -> dado = dado;
    novo -> prox = NULL;

    if(*raiz == NULL)
    {
        *raiz = novo;
    }
    else
    {   
        no *temp = *raiz;
        // Vai até o final para inserir o novo elemento
        while(temp -> prox != NULL)
            temp = temp -> prox;
        temp -> prox = novo;
    }
}

void print(tabela *tabela, int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        printf("%d -> ",i);
        no *temp = tabela[i].colisoes;
        while(temp != NULL)
        {
            printf("%d -> ",temp->dado);
            temp = temp ->prox;
        }
        printf("\\\n");
    }
}



int main()
{
    int qtdTeste;
    scanf("%d",&qtdTeste);
    tabela *tabela;
    while(qtdTeste)
    {   
        int tamTabela;
        scanf("%d",&tamTabela);
        tabela = malloc(sizeof(tabela) * tamTabela);
        for(int i = 0; i < tamTabela; i++)
        {
            tabela[i].colisoes = NULL;
        }

        int qtdChaves,chave,indice;
        scanf("%d",&qtdChaves);
        while(qtdChaves)
        {
            scanf("%d",&chave);
            indice = chave%tamTabela;
            insere(&tabela[indice].colisoes,chave);
            qtdChaves--;
        }

        print(tabela,tamTabela);
        printf("\n");

        for(int i = 0; i < tamTabela; i++)
        {
            no *temp = tabela[i].colisoes;
            while(temp != NULL)
            {
                no *prox = temp -> prox;
                free(temp);
                temp = prox;
            }
        }

        free(tabela);
        qtdTeste--;
    }

    return 0;
}
