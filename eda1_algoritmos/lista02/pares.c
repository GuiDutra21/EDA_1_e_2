#include <stdio.h>
#include <string.h>

int contador(char *entrada, int tamanho, int posicao, int pares)
{   
    if(posicao < tamanho - 1) // Quando possível faz a análise de dois em dois
    {
        if(entrada[posicao] == entrada[posicao + 2])
            pares++;

        if(posicao + 1 < tamanho - 1)
        {
            if(entrada[posicao + 1] == entrada[posicao + 3])
                pares++;
        }
            return contador(entrada, tamanho,posicao + 2 , pares);
    }
    else // chegou na penúltima posição do vetor, logo não precisa mais analisar
        return pares;

}

int main()
{
    char entrada[201];
    scanf("%s",entrada);

    int pares = contador(entrada,(strlen(entrada)), 0, 0);
    printf("%d\n",pares);

    return 0;
}