#include <stdio.h>
#include <stdlib.h>

typedef struct Celula
{
    int num;
    struct Celula *prox;

} celula;

void inserir(celula *cabeca, int novo)
{
    celula *no = malloc(sizeof(celula));
    no->prox = cabeca->prox;
    no->num = novo;
    cabeca->prox = no;
}

void print(celula *no)
{
    while (no != NULL)
    {
        printf("%d\t", no->num);
        no = no->prox;
    }
    printf("\n");
}

// Caso desejar alterar os apontamentos fora da função
// void print(celula **no)
// {
//     while (*no != NULL)
//     {
//         printf("%d\t", (*no)->num);
//         *no = (*no)->prox;
//     }
//     printf("\n");
// }

int main()
{
    celula *cabeca = malloc(sizeof(celula));
    inserir(cabeca, 3);
    inserir(cabeca, 2);
    inserir(cabeca, 1);
    print(cabeca->prox);
    printf("%d", cabeca->prox->num);

    return 0;
}