#include <stdio.h>
typedef struct fila
{
    int *dados;
    int N, p, u;
}fila;

int desenfileira(fila *f, int *y)
{
    if(f -> u != f -> p)
    {
        *y = f-> dados[f -> p];
        f -> p++;
        return 1;
    }
    return 0;
}