# include <stdio.h>
# include <stdlib.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}



void insertionSort(int *vetor, int l, int r)
{
    int aux,j;
    int i = l + 1;
    while(i <= r)
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

int partition( int *v , int l , int r )
{
    int i = l;
    int j = l ;
    int pivo = v[r];

    while (i < r)
    {
        if(v[i] < pivo)
        {   
            if(i != j)
                swap(v[i], v[j]);
            j++;
        }
        i++;
    }
    
    swap (v[j] ,v[r]);

    return j;
}

void quickSort(int v[], int l, int r)
{
    if(l < r)
    {   
        // coloca a mediana na ultima posicao, mediana de 3
        int meio = (l + r)/2; 

        if(v[meio] > v[r]) swap(v[meio], v[r]);
        if(v[l] > v[meio]) swap(v[l], v[meio]);
        if(v[r] > v[meio]) swap(v[r],v[meio]);

        if(r - l + 1 <= 15 )
            insertionSort(v, l, r);
        else
        {
            int p = partition(v, l, r);
            quickSort(v, l, p-1);
            quickSort(v, p+1, r);
        }
    }
}

int main()
{
    int vetor[100000];
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