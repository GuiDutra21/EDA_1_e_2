# include <stdio.h>
# include <stdlib.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}

void shellSort(int v[],int l, int r)
{
    int h = 1;
    while(h < r - l + 1)
        h = 3 * h + 1;
    
    while(h >= 1)
    {   
        //printf("h : %d\n",h);
        
        for(int i = h; i <= r ;i++)
        {
            for(int j = i; j >= l + h && v[j] < v[j - h]; j -= h )
            {
                swap(v[j], v[j - h]);
            }

            // for(int h = l; h <= r; h++)
            // {
            //     printf(" %d",v[h]);
            // }

            // printf("\n");
        }

        h /= 3;
    }
}


int main()
{
    int vetor[1000];
    int dado, i = 0, j = 1;

    while (scanf("%d",&dado) != EOF)
    {
        vetor[i] = dado;
        i++;
    }

    shellSort(vetor,0,--i);

    return 0;
}