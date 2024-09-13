#include <stdio.h>

int main()
{   
    int cartas[5];

    // le o vetor
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &cartas[i]);
    }

    // Se começar descrescendo analisa de uma forma
    if(cartas[0] > cartas[1])
    {
        if(cartas[1] > cartas[2] && cartas[2] > cartas[3] && cartas[3] > cartas[4])
        {
            printf("D\n");
        }
        else
        {
            printf("N\n");// caso nao de certo printa N
        }
    }
    else // Se começar crescendo analisa de uma outra forma
    {
        if(cartas[1] < cartas[2] && cartas[2] < cartas[3] && cartas[3] < cartas[4])
        {
            printf("C\n");
        }
        else
        {
            printf("N\n");// caso nao de certo printa N
        }
    }
    return 0;
}