typedef struct pilha {
int *dados;
int N, topo;
} pilha;

int desempilha(pilha *p, int *y)
{
    if(p -> topo == 0)
        return 0;
    
    *y = p -> dados[p -> topo - 1];
    p -> topo--;
    return 1;
}