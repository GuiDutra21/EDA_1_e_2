# include <stdio.h>
# include <stdlib.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}

int partition( int *v , int l , int r )
{
    int i = l - 1;
    int j = r;
    int pivo = v[r];

    while (i < j)
    {
       while(v[++i] < pivo);
       while(v[--j] >= pivo && j > l);
       if(i < j) swap(v[i], v[j]);
    }
    
    swap (v[i] ,v[r]);

    return i;
}

void quickSort(int v[], int l, int r)
{
    if(l < r)
    {   
        // coloca a mediana na ultima posicao, mediana de 3
        int meio = (l + r)/2; 

        if( v[meio] < v[l]) swap(v[meio], v[l]);
        if( v[r] < v[l]) swap(v[l], v[r]);
        if( v[meio] < v[r]) swap (v[r] ,v[meio]);

        int p = partition(v, l, r);
        quickSort(v, l, p-1);
        quickSort(v, p+1, r);
    }
}

int main()
{
    int vetor[1000];
    int dado, i = 0, j = 1, l;
    scanf("%d",&l);
    while (i < l)
    {   
        scanf("%d",&dado);
        vetor[i] = dado;
        i++;
    }

    quickSort(vetor, 0,--i);

    printf("%d",vetor[0]);
    while (j <= i)
    {   
        printf(" %d",vetor[j]);
        j++;
    }
    printf("\n");


    return 0;
}