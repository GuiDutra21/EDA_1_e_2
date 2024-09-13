# include <stdio.h>
# include <stdlib.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}

int buscaBinaria(int *v, int l, int r, int buscar)
{
    if( l > r) return -1;
    
    int meio = (l + r)/2;
    if(v[meio] == buscar)
    {
        return 1;
    }

    if(buscar < v[meio])
        return  buscaBinaria(v,l,meio - 1,buscar);
    else
        return  buscaBinaria(v,meio + 1,r,buscar);
    
}
   

int partition(int *v,int l, int r)
{   
    int i = l -1;
    int j = r;
    int pivo = v[r];
    
    while(i < j)
    {
        while(v[++i] < pivo);
        while(v[--j] >= pivo && j > l );
        if(i < j)   swap(v[j],v[i]);
    }

    swap(v[r],v[i]);

    return i;
}

int quickSort(int *v, int l, int r)
{   
    if(l < r)
    {   
        // calcula a mediana de 3 e bota a mediana na ultima posicao
        int meio = (l + r)/2;

        if(v[meio] > v[r]) swap(v[meio], v[r]);
        if(v[l] > v[meio]) swap(v[l], v[meio]);
        if(v[r] > v[meio]) swap(v[r],v[meio]);


            int p = partition(v,l,r);
            quickSort(v, l, p - 1);
            quickSort(v, p + 1, r);
    }
}

int main()
{   
    int n;  
    scanf("%d",&n);

    int vetor[n];
    int i;
    for( i = 0; i < n; i++)
    {
        scanf("%d",&vetor[i]);
    }

    quickSort(vetor,0, i - 1);

    int entrada;
    while((scanf("%d",&entrada)) != EOF)
    {
        if(buscaBinaria(vetor ,0 , i - 1, entrada) == 1)
            printf("sim\n");
        else
            printf("nao\n");
    }

    return 0;
}