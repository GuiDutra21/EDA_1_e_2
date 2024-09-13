# include <stdio.h>
# include <stdlib.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}

// selection
int procuraMenor(int *v, int j, int indiceMenor, int n)
{   
    if(j > n - 1)
        return indiceMenor;

    if(v[j] < v[indiceMenor])
        indiceMenor = j;

    return procuraMenor(v,++j, indiceMenor, n);
}

void laco(int *v, int i, int n)
{   
    if(i == n)
        return ;
        
    int menor = procuraMenor(v, i + 1, i, n);
    if(menor != i)
        swap(v[i], v[menor]);

    laco(v, ++i, n);

}

void ordena (int *v, int n)
{   
    laco(v, 0, n);
}

// int main()
// {
    // int vetor[1000];
    // int dado, i = 0, j = 1;

    // while (scanf("%d",&dado) != EOF)
    // {
    //     vetor[i] = dado;
    //     i++;
    // }

//     int j = 1;
//     int vetor[] = {5,2,4, 1,3};
//     ordena(vetor, 5);

//     printf("%d",vetor[0]);
//     while(j < 5)
//     {
//         printf(" %d",vetor[j]);
//         j++;
//     }

//     printf("\n");

//     return 0;
// }