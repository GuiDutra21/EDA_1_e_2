#include <stdio.h>
#include <stdlib.h>

long int vetor[81];

long int guarda(int n,long int *vetor)
{
    if(n ==1 || n==2 )
    {
        vetor[n] = 1;
        return 1;
    }
    else
    {
        vetor[n] = vetor[n-1] + vetor[n-2];
        
        return vetor[n];
    }
}

long int r(int n, int i)
{
    if(n > 0)
    {
        guarda(i,vetor);
        return r(--n, ++i);
    }
    else
    {
        return guarda(i-1,vetor);
    }
}

long int fibonacci(int n)
{
    return r(n,1);
}

int main()
{
    long int t = fibonacci(11);
    printf("\n%ld\n",t);
}