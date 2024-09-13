#include <stdio.h>
#include <stdlib.h>

typedef struct Fila fila;
typedef struct Cabeca cabeca;

struct Fila
{
    int numero;
    fila *prox;
};

void enfileira(fila **ultimo, int numero)
{
    fila *novo = malloc(sizeof(fila));
    novo -> numero = numero;
    novo -> prox = NULL;
    (*ultimo) -> prox = novo;
    *ultimo = novo;
}

void remover(fila *anterior)
{   
    fila *aux = malloc(sizeof(fila));
    aux = anterior -> prox;
    anterior -> prox = anterior -> prox -> prox;
    free(aux);
}

int main()
{
    int participantes,rodadas,teste = 1, resultado, pAtual, pRestantes, ordem, acao;

    fila *cabeca = malloc(sizeof(cabeca));


        while (scanf("%d %d",&participantes, &rodadas) && (participantes != 0 || rodadas != 0))
    {
        resultado = 0;

        scanf("%d",&pAtual);
        fila *primeiro = malloc(sizeof(fila));
        primeiro -> prox = NULL;
        primeiro -> numero = pAtual; 
        cabeca -> prox = primeiro; // já enfileira o primeiro

        fila *ultimo = malloc(sizeof(fila));
        ultimo = primeiro; // variável para auxiuliar no enfileiramento

        for(int i = 1; i < participantes; i++) // leitura e alocação da posição das pessoas
        {
            scanf("%d",&pAtual);
            enfileira(&ultimo,pAtual);
        }

        // while(cabeca ->prox != NULL)
        // {
        //     printf("%d ", cabeca -> prox -> numero);
        //     cabeca -> prox = cabeca -> prox -> prox;
        // }

        fila *anterior = malloc(sizeof(fila));

        for(int i = 0; i < rodadas; i++) // leitura de cada rodada do chefe
        {
            scanf("%d",&pRestantes);
            scanf("%d",&ordem);

            anterior = cabeca;

            for(int j = 0;j < pRestantes ;j++) // leitura de vivo ou morto de cada pessoa
            {   
                scanf("%d",&acao);
                if(acao != ordem)
                    remover(anterior);
                else if(( anterior -> prox -> prox != NULL))
                    anterior = anterior -> prox;            
            }
        }

        resultado = cabeca -> prox -> numero;
        // remove o último elemento que sobrou
        fila *restante = malloc(sizeof(fila));
        restante = cabeca -> prox;
        cabeca ->prox = NULL;
        free(restante);

        printf("Teste %d\n",teste);
        printf("%d\n\n",resultado);   
        teste++;
    }
    return 0;
}