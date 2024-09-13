#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned int codigo;
    int nota;
}semente;

void swap(semente *a, semente *b)
{
    semente aux = *a;
    *a = *b;
    *b = aux;
}

int less(semente s1, semente s2)
{
    if(s1.nota < s2.nota)
        return 1;
    
    if(s1.nota == s2.nota && s1.codigo < s2.codigo)
        return 1;

    return 0;
}

int partition(semente *v , int l , int r )
{
    int i = l;
    int j = r -1;
    semente pivo = v[r];

    while (i < j)
    {
       while(less(v[i],pivo))i++;
       while(j > l && less(pivo,v[j]))j--;
       if(i < j) swap(&v[i], &v[j]);
    }
    
    swap (&v[i], &v[r]);

    return i;
}


void quickSelect(semente vetor[], int l, int r, int k)
{
    if(l < r)
    {   
        // coloca a mediana na ultima posicao, mediana de 3
        int meio = (l + r)/2; 

        if(less(vetor[r],vetor[meio])) swap(&vetor[meio], &vetor[r]);
        if(less(vetor[meio], vetor[l])) swap(&vetor[meio], &vetor[l]);
        if(less(vetor[meio],vetor[r])) swap(&vetor[meio], &vetor[r]);

        int pivo = partition(vetor, l, r);
        if(k < pivo)
            quickSelect(vetor, l, pivo-1, k);
        if(k > pivo)
            quickSelect(vetor, pivo+1, r, k);
    }
}

void merge(semente *vetor, int l, int m, int r)
{
    int tamanho = (r - l) + 1;
    semente *aux = malloc(sizeof(semente) * tamanho);
    int i = l, j = m + 1, indiceAux = 0;

    while(i < m + 1 && j < r + 1)
    {
        if(vetor[i].codigo < vetor[j].codigo)
            aux[indiceAux++] = vetor[i++];
        else
            aux[indiceAux++] = vetor[j++];
    }

    while(i < m + 1) aux[indiceAux++] = vetor[i++];
    while(j < r + 1) aux[indiceAux++] = vetor[j++];

    indiceAux = 0;
    while(l <= r)
    {
        vetor[l++] = aux[indiceAux++];
    }
    free(aux);
}

void mergeSort(semente *vetor, int l, int r)
{
    if(l < r)
    {
        int meio = (l + r)/2;
        mergeSort(vetor,l, meio);
        mergeSort(vetor,meio + 1, r);
        merge(vetor, l, meio, r);
    }
}

int main()
{
    int qtdSelecionar, nota;
    unsigned int codigo;
    scanf("%d",&qtdSelecionar);
    semente vetor[10000000];

    int i = 0;
    while( (scanf("%u %d",&codigo, &nota)) != EOF)
    {
        vetor[i].codigo = codigo;
        vetor[i].nota = nota;
        i++;
    }

    quickSelect(vetor,0, i - 1, qtdSelecionar - 1);
    mergeSort(vetor, 0, qtdSelecionar - 1);
    
    for(i = 0; i < qtdSelecionar; i++)
    {
        printf("%u %d\n",vetor[i].codigo, vetor[i].nota);
    }
    
    return 0;
}