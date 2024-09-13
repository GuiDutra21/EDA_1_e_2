# include <stdio.h>
# include <stdlib.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}

void selectionSort(int *vetor, int tamanho)
{   
    int i = 0, j;
    int indiceMenor;
    while(i < tamanho - 1)
    {   
        j = i + 1;
        indiceMenor = i;
        while(j < tamanho)
        {
            if(vetor[indiceMenor] > vetor[j])   indiceMenor = j;
            j++;
        }
        if(indiceMenor != i)
            swap(vetor[i], vetor[indiceMenor])
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

    selectionSort(vetor, i);

    printf("%d",vetor[0]);
    while(j < i)
    {
        printf(" %d",vetor[j]);
        j++;
    }

    printf("\n");
    return 0;
}