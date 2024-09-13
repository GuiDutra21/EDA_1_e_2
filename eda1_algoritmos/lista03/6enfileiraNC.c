#include <stdio.h>
#include <stdlib.h>
typedef struct fila
{
    int *dados;
    int N,p,u;
}fila;

int enfileira(fila *f, int x)
{
    if(f -> u == f -> N)
    {
        int *novo = realloc(f -> dados, 2 * (f -> N) * sizeof(int));
        if(novo)
        {
            f -> dados = novo;
            f -> N = 2 * (f -> N);
        }
        else
        {
            return 0;
        }
    }
    f -> dados[f -> u++] = x;
    return 1;
}