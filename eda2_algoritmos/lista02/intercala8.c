#include<stdio.h>
#include<stdlib.h>
#define T 1000001

int main()
{
    int *vetor = calloc(sizeof(int), T);
    int casosTestes = 8, tamanho, numero, repeticao;
    while(casosTestes > 0)
    {
        scanf("%d",&tamanho);
        for(int i = 0; i < tamanho; i++)
        {
            scanf("%d",&numero);
            vetor[numero]++;
        }
        casosTestes--;
    }

    for(int i = 0; i < T; i++)
    {
        repeticao = vetor[i];
        if(repeticao > 0)
        {
            for(int j = 0; j < repeticao;j++)
            {
                printf("%d ",i);
            }
        }
    }
    printf("\n");
    free(vetor);
    return 0;
}