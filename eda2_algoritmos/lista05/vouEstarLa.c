#include <stdio.h>
#include <stdlib.h>


int main()
{   
    // N,M,J indicando, respectivamente, o número de locais do bairro, o número de locais em que Juliano já esteve e o número de locais que deseja-se saber se Juliano estará
    int n,m,j;
    scanf("%d %d %d",&n ,&m ,&j);
    char **matriz = calloc(n, sizeof(char*));
    int *sujo = calloc(n,sizeof(int));
    for(int i = 0; i < n; i++)
    {
        matriz[i] = calloc(n,sizeof(char));
    }

    int qtd;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&qtd);
        int vizinho;
        for(int j = 0; j < qtd; j++)
        {   
            scanf("%d",&vizinho);
            matriz[i][vizinho] = 1;
            matriz[vizinho][i] = 1;
        }
    }

    int lugarVisitado;
    for(int i = 0; i < m; i++)
    {
        scanf("%d",&lugarVisitado);
        sujo[lugarVisitado] = 1;
        for(int i = 0; i < n; i++)
        {
            if(matriz[lugarVisitado][i])
            {
               sujo[i] = 1;
            }
        }
    }

    int procurar;
    for(int i = 0; i < j; i++)
    {
        scanf("%d",&procurar);
        if(sujo[procurar])
        {
            printf("Eu vou estar la\n");
        }
        else
            printf("Nao vou estar la\n");
    }

    return 0;
}