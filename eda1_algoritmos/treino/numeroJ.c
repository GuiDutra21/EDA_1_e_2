# include <stdio.h>
# include <stdlib.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}

int main()
{   
    int n;  
    scanf("%d",&n);

    int vetor[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&vetor[i]);
    }

    int entrada;
    while(scanf("%d",&entrada) != EOF);
    return 0;
}