#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha pilha;

struct Pilha
{
    char simbolo;
    pilha *prox;
};

void empilha(pilha *cabeca, char caracter)
{
    pilha *novo = malloc(sizeof(pilha));
    novo -> simbolo = caracter;
    novo -> prox = cabeca -> prox;
    cabeca -> prox = novo;
}

void desempilha(pilha *cabeca)
{
    pilha *remove = malloc(sizeof(pilha));
    remove = cabeca -> prox;
    cabeca -> prox = cabeca -> prox -> prox;
    free(remove);
}

int main()
{   
    int tamanho;
    scanf("%d",&tamanho);
    char str[100000];

    int i = 0;
    int j = 0;
    while(i < tamanho)
    {
        scanf("%s",str);
        // se for um fechamento já no primeiro caracter ou se tiver apenas um elemento está errado,
        // então já pula para a próxima leitura
        if(str[0] == ']' || str[0] == ')' || str[0] == '}' || strlen(str) == 1)
        {
            printf("N\n");
            i++;
            continue;
        } 
        
        // empilha o primeiro
        pilha *cabeca = malloc(sizeof(pilha));
        cabeca -> prox = NULL;
        empilha(cabeca, str[0]);

        for(j = 1; str[j] != '\0'; j++)
        {
            if(str[j] == '[' || str[j] == '{' || str[j] == '(')
                empilha(cabeca, str[j]);
            else if( cabeca -> prox != NULL && ((str[j] == ')' && cabeca->prox->simbolo == '(') ||
                    (str[j] == '}' && cabeca->prox->simbolo == '{') ||
                    (str[j] == ']' && cabeca->prox->simbolo == '[')))
                desempilha(cabeca);
            else
            {
                //printf("N\n");
                break;
            }
        }
        if(str[j] == '\0' && cabeca -> prox == NULL)
            printf("S\n");
        else
            printf("N\n");
        cabeca -> prox = NULL;
        i++;
    }
    return 0;
}