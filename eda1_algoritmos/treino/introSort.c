# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}

typedef int Item;

void insertionSort(int *vetor, int l, int r)
{
    int i = l, j;
    while (i < r)
    {   
        j = i + 1;
        while(j - 1 >= l && vetor[j] < vetor[j - 1])
        {
            swap(vetor[j], vetor[j - 1]);
            j--;
        }
        i++;
    }
    
}

// k = índice do elemento em análise
void fixDown(Item k, Item n, Item *pq)
{   
    int j;

    //tem filho?
    while(2*k <= n)
    {
        j = 2 * k; // recebe o índice do filho

        // pega o maior filho
        if(j < n && pq[j] < pq[j + 1])
            j++;
        
        // se o maior filho for menor que o pai ja pode parar
        if(pq[k] > pq[j])
            return;

        swap(pq[k], pq[j]);
        k = j; // atualiza o índice do elemento
    }
}

void heapSort(int *vetor, int l, int r)
{
    int *pq = vetor + l - 1;

    int n = r - l  + 1;
    for(int k = n/2; k >= 1; k-- ) 
    {
        fixDown(k,n,pq);
    }

    while(n > 1)
    {
        swap(pq[1],pq[n]);
        fixDown(1, (--n), pq);
    }
}

int partition(int *v, int l, int r)
{
    int i = l - 1;
    int j = r;
    int pivo = v[r];

    while(i < j)
    {
        while(v[++i] < pivo);
        while(v[--j] >= pivo && j > l);
        if(i < j)   swap(v[i], v[j]);
    }

    swap(v[i], v[r]);

    return i;
}

void introSort(int *v, int l, int r, int maxdepth)
{
    if( r - l <= 15)
    {
        insertionSort(v,l,r);
        return;
    }
    else if(maxdepth == 0)
    {
        heapSort(v,l,r);
        // mergeSort(v,l,r);
    }
    else
    {

        int p = partition(v,l,r);
        introSort(v,l, p - 1, maxdepth - 1);
        introSort(v, p + 1, r, maxdepth - 1);
    }
}


int main()
{
    int n;
    scanf("%d",&n);
    int v[n];
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d",&v[i]);
    }
    int maxdepth = 2*((int)log2((double)n-1));

    introSort(v,0, n-1,maxdepth);
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
    return 0;
}