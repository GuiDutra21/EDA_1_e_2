#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) { int t; t = a; a = b; b = t;}

int partition(int *vetor, int l, int r)
{
    int i = l, k = l;
    int pivo = vetor[r];
    while (k < r)
    {
        if (vetor[k] < pivo)
        {
            swap(vetor[i], vetor[k]);
            i++;
        }
        k++;
    }

    swap(vetor[i], vetor[r]);
    return i;
}

void quickSort(int *vetor, int l, int r)
{
    if (l < r)
    {
        int meio = (l + r) / 2;
        if(vetor[meio] > vetor[r]) swap(vetor[meio], vetor[r]);
        if(vetor[meio] < vetor[l]) swap(vetor[meio], vetor[l]);
        if(vetor[meio] < vetor[r]) swap(vetor[meio], vetor[r]);
        int pivo = partition(vetor, l, r);
        quickSort(vetor, l, pivo - 1);
        quickSort(vetor, pivo + 1, r);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int vetor[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    quickSort(vetor, 0, n - 1);

    printf("%d", vetor[0]);
    for (int i = 1; i < n; i++)
    {
        printf(" %d", vetor[i]);
    }
    printf("\n");

    return 0;
}