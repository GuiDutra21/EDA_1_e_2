# include <stdio.h>
# include <stdlib.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}

void insertionSort(int *vetor, int tamanho)
{

    int aux,j;
    int i = 1;
    while(i < tamanho)
    {
        aux = vetor[i];
        j = i;
        while(j  > 0 && aux < vetor[j - 1])
        {
            vetor[j] = vetor[j - 1];
            j--;
        }

        vetor[j] = aux;
        i++;
    }
    
}
    
int main()
{
     int vetor[50000];
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