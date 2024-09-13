#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *v;
    int N;
    int topo;
}pilha;


void empilha(pilha *p, int x)
{
    if(p -> topo + 1 == p -> N)
    {
        p -> v = realloc(p -> v, sizeof(int)*(2 * (p -> N)));
        p -> N *= 2;
    }
        p -> v[p -> topo++] = x;    
}

int desempilha(pilha *p, int *y)
{
    if(p -> topo == 0)
        return 0;
    
    *y = p -> v[p -> topo - 1];
    p -> topo--;
    return 1;
}