#include<stdio.h>
#include<stdlib.h>
#define T 997

typedef struct Referencia
{
    int existe;
    int indiceMatriz;
}ref;

void dfs(int **matriz, int m, int indice, int qtdComponentes, int *visitados)
{   
    visitados[indice] = qtdComponentes;
    for(int i = 0; i < m; i++)
    {
        if(matriz[indice][i] && !visitados[i])
            dfs(matriz,m,i,qtdComponentes,visitados);
    }
}

int busca(int **matriz, int m)
{
    int *visitados = calloc(m, sizeof(int));
    int qtdComponentes = 0;
    
    for(int i = 0; i < m; i++)
    {
        if(!visitados[i])
        {
            dfs(matriz,m,i,++qtdComponentes,visitados);
        }

    }

    return qtdComponentes;
}

// int funcaoHash(char *palavra)
// {
//     long posicao = 0;
//     int i = 0;
    
//     while (palavra[i] != '\0')
//     {
//         posicao = posicao * 256 + palavra[i];
//         i++;
//     }
//     return posicao%307;
// }

int funcaoHash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return (int)(hash % T);
}

// Retorna o indice na matriz
int existe(char *palavra, ref *tabela, int *auxMatriz)
{
    int indice = funcaoHash(palavra);

    if(tabela[indice].existe)
    {
        return tabela[indice].indiceMatriz;
    }
    else
    {
        tabela[indice].existe = 1;
        tabela[indice].indiceMatriz = *auxMatriz;
        (*auxMatriz)++;
        return *auxMatriz - 1;
    }
}

int main()
{
    int m,n;
    scanf("%d %d",&m, &n);

    // Usado para saber se eu armazenei ou nao uma palavra e qual o indice correspondente na matriz de adjacencia
    ref *tabela = calloc(997,sizeof(ref));
    int auxMatriz = 0;


    // Constroi a matriz
    int ** matriz = calloc(m,sizeof(int*));
    for(int i = 0; i < m; i++)
    {
        matriz[i] = calloc(m,sizeof(int));
    }

    char pessoa1[100], relacao[100], pessoa2[100];
    for(int i = 0; i < n; i++)
    {
        scanf("%s %s %s",pessoa1, relacao, pessoa2);
        int indice1 = existe(pessoa1,tabela, &auxMatriz);
        int indice2 = existe(pessoa2,tabela, &auxMatriz);
        matriz[indice1][indice2] = 1;
        matriz[indice2][indice1] = 1;
    }

    int resultado = busca(matriz,m);
    printf("%d\n",resultado);

    for(int i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);
    free(tabela);
    return 0;
}