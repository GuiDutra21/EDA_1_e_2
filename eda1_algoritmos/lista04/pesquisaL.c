# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define swap(a,b) {dado t; t = a; a = b; b = t;}

typedef struct Dado dado;

struct Dado
{
    int numero;
    char palavra[16];
};

int partition(dado *vetor, int l, int r)
{
    int i = l - 1;
    int j = r;
    int pivo = vetor[r].numero;
    while (i < j)   
    {
        while(vetor[++i].numero < pivo);
        while(vetor[--j].numero >= pivo && j > l);
        if(i < j)
        {   
            swap(vetor[j], vetor[i]);
        }
    }

    swap(vetor[i], vetor[r]);
    return i;   
    
}

void quickSort(dado *vetor, int l, int r)
{
    if(l < r)
    {
        int p = partition(vetor, l, r);
        quickSort(vetor, l, p - 1);
        quickSort(vetor, p + 1,r);
    }
}

int buscaBinaria(dado *vetor,int l, int r, int buscar)
{

    if(l > r) return -1;

    int meio = (l + r)/2;

    if(buscar == vetor[meio].numero)
        return meio;
    
    if(buscar < vetor[meio].numero)
        return buscaBinaria(vetor,l, meio - 1, buscar);
    return buscaBinaria(vetor, meio + 1, r, buscar);
    
}


int main()
{
    int n;
    scanf("%d",&n);

    dado vetor[n];
    int i = 0;
    while(i < n)
    {
        scanf("%d",&vetor[i].numero);
        scanf("%s",vetor[i].palavra);
        i++;
    }

    quickSort(vetor,0 , n - 1);
    
    int numero, resultadoBusca;
    

    while ((scanf("%d",&numero)) != EOF)
    {   
        resultadoBusca = buscaBinaria(vetor,0,n-1,numero);
        if( resultadoBusca != -1)
            printf("%s\n",vetor[resultadoBusca].palavra);
        else
            printf("undefined\n");
    }
    return 0;
}