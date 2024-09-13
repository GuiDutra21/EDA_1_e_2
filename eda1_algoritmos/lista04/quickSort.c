# include <stdio.h>
# include <stdlib.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}

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

return i ;
}

void quickSort(int v[], int l, int r)
{
    if(l < r)
    {
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