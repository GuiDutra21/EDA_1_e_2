# include <stdio.h>
# include <stdlib.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}

typedef int Item;

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


int main()
{
    int vetor[] = {7,2,5,4,1,6,3,1};

    heapSort(vetor,0,7);

    for(int i = 0; i < 8; i++)
    {
        printf("%d ",vetor[i]);
    }
    printf("\n");
    return 0;
}