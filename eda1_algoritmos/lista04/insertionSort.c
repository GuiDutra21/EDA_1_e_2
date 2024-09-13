# include <stdio.h>
# include <stdlib.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}

void insertionSort(int *vetor, int tamanho)
{
    int i = 0, j;
    while (i < tamanho - 1)
    {   
        j = i + 1;
        while(j - 1 >= 0 && vetor[j] < vetor[j - 1])
        {
            swap(vetor[j], vetor[j - 1]);
            j--;
        }
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

    insertionSort(vetor, i);

    printf("%d",vetor[0]);
    while(j < i)
    {
        printf(" %d",vetor[j]);
        j++;
    }

    printf("\n");

    return 0;
}