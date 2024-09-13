#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int *dados;
    int N, p, u;
} fila;

int enfileira (fila *f, int x)
{   
    if(f -> u + 1 == f -> p ) // fila cheia, caso em que o último elemento tem um índice menor que o primeiro
    {
        int *novo = malloc(2 * (f -> N) * sizeof(int));
        if(novo)
        {
            int i = 0, j = f -> p;
            while (i != f -> N) 
            {   
                if(j == f -> N)
                    j = 0;
                novo[i++] = f ->dados[j++];
            }
            f -> u = i;
            f -> p = 0;
            f -> dados = novo;
            f -> N *= 2;
            f -> dados[f -> u] = x;
            return 1;
        }
    }
    else if (f -> u + 1 == f -> N && f-> p == 0) // fila cheia, caso em que o último elemento tem um índice menor que o primeiro
    {
        f -> dados = realloc( f -> dados, 2 * (f -> N) * sizeof(int));
        if(f -> dados)
        {
            f -> N *= 2;
            f -> dados[f -> u++];
            f -> dados[f -> u] = x;    
            return 1;
        }
        return 0;
    }
    else
    {
        if(f -> u + 1 == f -> N) // Caso em que o último elemento tem um índice menor que o primeiro, mas a fila não está cheia
        {
            f -> u = 0;
            f -> dados[f -> u] = x;
            return 1;
        }
        else // Caso em que a fila não está cheia e o último elemento tem um índice maior que o primeiro
        {
            f -> dados[++(f -> u)] = x;
            return 1;
        }
    }
}

// int main()
// {
//     fila *f = (fila *)malloc(sizeof(fila));
//     f -> dados = malloc(5 * sizeof(int));
//     int i;
    
//     // while(i < 5)
//     // {
//     //     f -> dados[i] = i;
//     //     i++;
//     // }

//     f -> dados[0] = 3;
//     f -> dados[1] = 4;
//     f -> dados[2] = 5;
//     f -> dados[3] = 1;
//     f -> dados[4] = 2;

//     f -> p = 0;
//     f -> u = 4;
//     f -> N = 5;
//     if(enfileira(f,8))
//     {   
//         i = 0;
//         while(i < 6)
//         {
//             printf("%d\t",f ->dados[i++]);
//         }
//     }
//     printf("\n");
//     free(f);
// }