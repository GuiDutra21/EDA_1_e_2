#include<stdio.h>
#include <stdlib.h>
#define swap(a,b){int aux; aux = a; a = b; b = aux;}
// int vetor[9];

int partition(int *vetor, int l, int r)
{
    int i = l, j = l, pivo = vetor[r];

    while(j < r)
    {
        if(vetor[j] <= pivo)
        {
            swap(vetor[i], vetor[j]);
            i++;
        }
        j++;
    }

    swap(vetor[i], vetor[r]);
    return i;
}

void quickSelect(int *vetor, int l, int r, int k)
{
    if(l < r)
    {
        int meio = (l + r) /2;
        if(vetor[meio] > vetor[r]) swap(vetor[meio],vetor[r]);
        if(vetor[meio] < vetor[l]) swap(vetor[meio],vetor[l]);
        if(vetor[meio] < vetor[r]) swap(vetor[meio],vetor[r]);

        int pivo = partition(vetor, l, r);

        if(k < pivo) quickSelect(vetor, l, pivo - 1,k);
        else if(k > pivo) quickSelect(vetor, pivo + 1, r, k);
    }

}

void quickSort(int *vetor, int l, int r)
{
    if(l < r)
    {
        int meio = (l + r) /2;
        if(vetor[meio] > vetor[r]) swap(vetor[meio],vetor[r]);
        if(vetor[meio] < vetor[l]) swap(vetor[meio],vetor[l]);
        if(vetor[meio] < vetor[r]) swap(vetor[meio],vetor[r]);

        int pivo = partition(vetor, l, r);

        quickSort(vetor, l, pivo - 1);
        quickSort(vetor, pivo + 1, r);
    }

}

int main()
{
    int qtdProdutos, pagina, qtdProdutosPagina, id;

    scanf("%d %d %d",&qtdProdutos, &pagina, &qtdProdutosPagina);
    
    int *vetor =  malloc(sizeof(int) * qtdProdutos);
    for(int i = 0;i < qtdProdutos; i++)
    {
        scanf("%d",&id);
        vetor[i] = id;
    }

    // Índice do primeiro elemento da página
    int primeiroPagina  =  pagina * qtdProdutosPagina;
    
    quickSelect(vetor, 0, qtdProdutos - 1, primeiroPagina);
    quickSort(vetor,primeiroPagina,  qtdProdutos - 1);

    for(int i = primeiroPagina; i < qtdProdutos && i < primeiroPagina + qtdProdutosPagina; i++)
        printf("%d\n",vetor[i]);

    free(vetor);
    return 0;
}