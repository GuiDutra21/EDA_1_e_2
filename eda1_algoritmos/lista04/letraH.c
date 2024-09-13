# include <stdio.h>
# include <stdlib.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}

void buscaBinaria(int *v, int l, int r, int elemento)
{  
    int meio = (l + r)/2;
    if(elemento <= v[meio] && elemento > v[meio - 1])
    {
        printf("%d\n",meio);
    }
    else
    {   
        if(elemento < v[meio])
            buscaBinaria(v, l, meio, elemento);
        else   
            buscaBinaria(v, meio, r, elemento);
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    int vetorBusca[n], vetorElementos[m];
    int i, j;
    for(i = 0; i < n; i++)
        scanf("%d",&vetorBusca[i]);
    
    
    for(j = 0; j < m; j++)
        scanf("%d",&vetorElementos[j]);
    
    for(int l = 0; l < m; l++)
    {
        if(vetorElementos[l] <= vetorBusca[0])
            printf("0\n");
        else if(vetorElementos[l] > vetorBusca[n - 1])
            printf("%d\n",n);
        else
            buscaBinaria(vetorBusca, 0, n, vetorElementos[l]);
    }

    return 0;
}