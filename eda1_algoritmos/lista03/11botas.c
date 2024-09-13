#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha pilha;

struct Pilha
{
    int tamanho;
    char pe;
    pilha *prox;
};

void empilhar(pilha *cabeca, int tamanho, char pe)
{
    pilha *novo = malloc(sizeof(pilha));
    novo -> pe = pe;
    novo -> tamanho = tamanho;
    novo -> prox = cabeca -> prox;
    cabeca -> prox = novo;
}

void desempilha(pilha *cabeca, pilha *anterior)
{   
    pilha *aux = anterior -> prox;
    if(anterior == cabeca)
        cabeca -> prox = anterior -> prox -> prox;
    else
        anterior -> prox = anterior -> prox -> prox;
    free(aux);
    
}

pilha * procuraPar(pilha *atual, int tamanho, char pe)
{
    if(atual -> prox == NULL) // condicao de parada
        return NULL;
    else if(tamanho == atual ->  prox -> tamanho && pe != atual -> prox -> pe)
    {
        return atual;
    }
    else
        return procuraPar(atual = atual -> prox, tamanho, pe);
}
 
int main()
{
    int tamanho;
    char pe;
    int totalPares = 0;
    pilha *cabeca = malloc(sizeof(pilha));
    cabeca -> prox = NULL; 

    while(scanf("%d",&tamanho) != EOF)
    {
        scanf(" %c",&pe);
        
        pilha *par = procuraPar(cabeca, tamanho, pe);
        if(par)
        {
            totalPares++;
            desempilha(cabeca, par);
        }
        else
            empilhar(cabeca,tamanho,pe);
   
    }    

    printf("%d\n",totalPares);
    return 0;
}