#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha pilha;

struct Pilha 
{
    int dado;
    pilha *anterior;
    pilha *prox;
};


void empilha(pilha *cabeca, int numero)
{   
    pilha *novo = malloc(sizeof(pilha));
    novo -> dado = numero;
    if(cabeca -> prox != NULL)
        cabeca -> prox -> anterior = novo;

    novo -> prox = cabeca -> prox;
    novo -> anterior = cabeca;
    cabeca -> prox = novo;

}

void empilhaAntes(pilha *atual, pilha *novo)
{
    novo -> prox = atual;
    novo -> anterior = atual -> anterior;
    atual -> anterior = novo;
    novo -> anterior -> prox = novo; 
}

pilha *desempilha(pilha *atual)
{
    atual -> anterior -> prox = atual -> prox;
    if(atual -> prox != NULL)
        atual -> prox -> anterior = atual -> anterior;
    return atual;
}

int main()
{
    int qtdCaminhao, caminhao, errado = 0;
    pilha *ruaPrinciapal = malloc(sizeof(pilha));
    pilha *ruaAuxiliar = malloc(sizeof(pilha));
    pilha *base;
    pilha *atual;
    while(scanf("%d",&qtdCaminhao) && qtdCaminhao != 0)
    {   
        ruaAuxiliar -> prox = NULL;
        ruaPrinciapal -> prox = NULL;
        for(int i = 0; i < qtdCaminhao; i++) // empilhamento dos caminhões
        {
            scanf("%d",&caminhao);
            empilha(ruaPrinciapal, caminhao);

            if(i == 0)
                base = ruaPrinciapal -> prox;
        }

        errado = 0;
        atual = base;
        while(atual != ruaPrinciapal)
        {   
            if(atual -> dado >= atual -> anterior -> dado) // se o atual for maior que o anterior
            {
                if(ruaAuxiliar -> prox == NULL)
                    empilha(ruaAuxiliar, desempilha(atual) -> dado); // se a pilha auxiliar estiver vazia pode adicionar

                // caso em que o elemento que eu vou empilhar é maior que o que já está empilhado, já anula tudo
                else if(atual -> dado > ruaAuxiliar -> prox -> dado) 
                {
                    atual = ruaPrinciapal;
                    errado = 1;
                    continue;
                }
                else 
                    empilha(ruaAuxiliar, atual -> dado); // empilha normalmente na ruaAxiliar
                    
                atual = atual -> anterior;
            }

            // se o elemento atual não for menor uma unidade que o antecessor dele
            else if(atual -> dado != atual -> anterior -> dado - 1) 
            {   
                // Se o atual não for o último elemento da rua principal e o último elemento da ruaAuxiliar é o elemento uma 
                // unidade superior que o antecessor do atual, ai pode colocar entre eles
                if(atual -> anterior != ruaPrinciapal && atual -> dado == ruaAuxiliar -> prox -> dado - 1)
                    empilhaAntes(ruaPrinciapal, desempilha(atual));
                else
                    atual = atual -> anterior;
            }

            // Caso em que terminou a verificação e ainda resta elementos na ruaAuxiliar
            else if(atual -> anterior == ruaPrinciapal)
            {
                atual = ruaPrinciapal;
            }
            else
                atual = atual -> anterior;
        }

        if(errado)
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}