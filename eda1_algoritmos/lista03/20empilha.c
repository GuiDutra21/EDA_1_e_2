#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *dados;
    int N, topo;
}pilha;


int empilha(pilha *p, int x)
{
    if(p -> topo + 1 == p -> N)
    {
        p -> dados = realloc(p -> dados, sizeof(int)*(2 * (p -> N)));
        p -> N *= 2;
    }
        p -> dados[p -> topo++] = x;
    
    return 1;
}