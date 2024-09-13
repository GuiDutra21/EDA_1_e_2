typedef struct fila {
int *dados;
int N, p, u;
} fila;

int desenfileira(fila *f, int *y)
{
    if (f->p == f->u) // Verifica se a fila está vazia
    {
        return 0; // Retorna 0 se a fila estiver vazia
    }
    
    *y = f->dados[f->p];
    if(f -> p + 1 == f -> N)
    {
        f -> p = 0;
        return 1;
    }
    f->p++;
    return 1; // Retorna 1 se o desenfileiramento for bem-sucedido
}