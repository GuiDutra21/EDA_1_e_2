#include <stdio.h>

void move(int *v, int *n)
{
    int aux = v[1];
    int i = 2;
    int j = 0;
    while(i < *n)
    {
        v[j] = v[i];
        j++;
        i++; 
    }
    *n -= 1;
    v[*n - 1] = aux;

}

int main()
{
    int n;
    scanf("%d",&n);

    int pilha[n];

    int i = 0;
    while(i < n)
    {
        pilha[i] = i + 1;
        i++;
    }

    printf("Cartas descartadas:");
    printf(" %d",pilha[0]);
    move(pilha,&n);
    

    while(n >= 2)
    {   
        printf(", %d",pilha[0]);
        move(pilha, &n);
    }

    printf("\nCarta restante: %d\n",pilha[0]);

    // for(int k = 0; k < 5; k++)
    // {
    //     printf("%d ",pilha[k]);
    // }
    return 0;
}