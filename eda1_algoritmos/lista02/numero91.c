#include <stdio.h>

int maldicao(int n) // Função recursiva
{
    if(n >= 101)
        return n - 10;
    else
        return maldicao(maldicao(n + 11));
}

int main()
{   
    int entrada;
    while(scanf("%d",&entrada) && entrada != 0)
    {   
        int resultado = maldicao(entrada);
        printf("f91(%d) = %d\n",entrada, resultado);
    }
    return 0;
}