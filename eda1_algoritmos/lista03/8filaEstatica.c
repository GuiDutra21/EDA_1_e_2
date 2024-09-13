#include <stdio.h>
#include <stdlib.h>

typedef struct {
int *v; // Vetor que representa a fila
int N; // Tamanho da fila
int inicio, fim; // Indicadores de inicio e final da fila
} fila;


int enfileira (fila *f, int x)
{   
   if((f -> fim + 1 == f -> inicio) || (f -> fim  + 1== f -> N && f -> inicio == 0)) // se estiver cheia
   {
        return 0;
   }
   else
   {
        if(f -> fim + 1 == f -> N) // Se o fim "apontar" para o último elemento
        {
            f -> v[f -> fim] = x;
            f -> fim = 0;
        }
        else
            f -> v[f -> fim++] = x;

        return 1;
   }
}

int desenfileira (fila *f, int *y)
{
    if( f -> inicio != f -> fim) // verifica se não esta vazia
    {
        *y = f -> v[f -> inicio];

        if(f -> inicio + 1 == f -> N) // Caso em que o elemento está no final do vetor
            f -> inicio = 0;
        else
            f-> inicio++;

        return 1;
    }
    return 0; // se estiver vazia retorna 0
}

// int main()
// {
//     fila teste;
//     int vector[] = {0,1,2,3,4,5};
//     teste.v = vector;
//     teste.fim = 3;
//     teste.inicio = 5;
//     teste.N = 6;

//     int qualquer = enfileira(&teste, 999);
//     printf("funcionou ? %d\n",qualquer);
//     for(int i = 0;i < 6;i++)
//     {
//         printf("%d ",teste.v[i]);
//     }

//     // int retira;
//     // int qualquer2 = desenfileira(&teste, &retira);
//     // printf("funcionou ? %d\n",qualquer2);
//     // printf("valor desenfileirado ? %d\n",retira);

//         printf("\n");
//     // printf("%d\n",teste.v[1]);

// }