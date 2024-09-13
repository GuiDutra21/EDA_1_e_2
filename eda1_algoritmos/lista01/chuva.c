#include <stdio.h>

int main()
{
    int tamanho, quantidade, j = 0;

    scanf("%d",&tamanho);

    int mapa[tamanho * tamanho];// Vetor que representa o mapa
    for(int i = 0; i < 2 * tamanho * tamanho; i++ )
    {   
        scanf("%d",&quantidade);

        // Quando pular para o segundo mapa zera o contador
        if(i == (tamanho * tamanho))
            j = 0;

        if(i < tamanho * tamanho)
            mapa[j] = quantidade; // No primeiro mapa atribui
        else
            mapa[j] += quantidade; // No segundo mapa soma
        
        j++;
    }

    // Printa o mapa, o resto ai dentro e apenas para imprimir no estilo como a questão pede
    j = 0;
    for(int i = 0; i < tamanho * tamanho; i++)
    {   
            printf("%d",mapa[i]);
            if(j < tamanho)
                printf(" ");

        if(j == tamanho - 1)
        {
            printf("\n");
            j = 0;
        }
        else
            j++;
    }

    return 0;
}