#include <stdio.h>

int main()
{
    int tamanho,menor,indice = 0;
    scanf("%d",&tamanho);

    int vetor[tamanho];
    for(int i = 0; i < tamanho; i++)
    {
        scanf("%d",&vetor[i]);

        // Considera o priemiro o menor e depois vai comparando
        if(i == 0)
            menor = vetor[0];
        else
            if(menor > vetor[i])
            {
                menor = vetor[i];
                indice = i;
            }
    }
    printf("%d\n",indice);
    
    return 0;
}