#include <stdio.h>

int main()
{
    int linhas, colunas,maior = 0,soma = 0;

    scanf("%d %d",&linhas, &colunas);

    int campo[linhas][colunas];

    // ao mesmo tempo que le a matriz ja calcula qual a maior linha
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            scanf("%d",&campo[i][j]);
            soma += campo[i][j];  
        }
        
        if(soma > maior)
        {
            maior = soma;
        }
            soma = 0;
        
    }
    // compara agora as colunas
    soma = 0;
    for(int i = 0; i < colunas; i++)
    {
        for(int j = 0; j < linhas; j++)
        {
            soma += campo[j][i];
        }
        
        if(soma > maior)
        {
            maior = soma;
        }
            soma = 0;
    }

    printf("%d\n",maior);


    return 0;
}