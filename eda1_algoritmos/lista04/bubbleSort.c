# include <stdio.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}

void bubbleSort(int *vetor, int tamanho)
{   
    int j = 0, i = 0, iteracoes;
    iteracoes = tamanho - 1;

    while(i < tamanho)
    {
        j = 0;
        while(j < iteracoes)
        {
            if(vetor[j] > vetor[j + 1]) swap(vetor[j], vetor[j + 1]);
            j++;
        }
        iteracoes--;
        i++;
    }
}

int main()
{
    int vetor[1000];
    int dado, i = 0, j = 1;

    while (scanf("%d",&dado) != EOF)
    {
        vetor[i] = dado;
        i++;
    }

    bubbleSort(vetor, i);

    printf("%d",vetor[0]);
    while (j < i)
    {   
        printf(" %d",vetor[j]);
        j++;
    }
    printf("\n");
    return 0;
}