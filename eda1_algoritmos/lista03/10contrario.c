#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha pilha;

struct Pilha
{
    char letra;
    pilha* prox;
};

void empilha(pilha * cabeca, char caracter)
{
    pilha *novo = malloc(sizeof(pilha));
    novo -> letra = caracter;
    novo -> prox = cabeca -> prox;
    cabeca -> prox = novo;
}

char desempilha(pilha * cabeca)
{
    char aux = cabeca -> prox -> letra;
    pilha * aux2 = cabeca -> prox;
    cabeca -> prox = cabeca -> prox -> prox;
    free(aux2);
    return aux;
}


int main()
{   
    char str[501];
    scanf("%s",str);
    int i = 0;
    pilha *cabeca = malloc(sizeof(pilha));
    cabeca -> prox = NULL;
    while(str[i] != '\0')
    {   
        empilha(cabeca,str[i]);
        i++;
    }

    while(cabeca -> prox != NULL)
    {
        printf("%c",desempilha(cabeca));
    }
    printf("\n");
    return 0;
}