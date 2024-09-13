#include <stdio.h>

int main()
{
    int tamanho, numero, qtdPar = 0, qtdImpar = 0;
    
    scanf("%d", &tamanho);

    int vetor[tamanho];
    
    // Priemiro loop para ter a quantidade de numeros pares e impares
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);

        if(vetor[i]%2 == 0)
            qtdPar++;
        else
            qtdImpar++;
    }

    // Cria os vetores para os respectivos numeros
    int vetorImpar[qtdImpar];
    int vetorPar[qtdPar];

    // Faz a atribuição dos números para o vetor adequado passando o indice
    for (int j = 0, p = 0, i = 0; j < tamanho; j++) {

        if(vetor[j]%2 == 0)
        {
            vetorPar[p] = j;
            p++;
        }
        else
        {
            vetorImpar[i] = j;
            i++;
        }
    }
    
    // imprime o vetor par
    for (int i = 0; i < qtdPar; i++)
    {   
        if(i != 0)
        {
            printf("");
        }
        printf("%d",vetorPar[i]);
    }

    printf("\n");

    // imprime o vetor impar
    for (int i = 0; i < qtdImpar; i++)
    {   
        if(i != 0)
        {
            printf("");
        }
        printf("%d ",vetorImpar[i]);
    }
    
    return 0;
}