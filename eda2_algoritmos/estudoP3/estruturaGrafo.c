#include <stdio.h>
#include <stdlib.h>

// Matriz de adjacencia
typedef struct GrafoM
{
    int tam;
    int **matriz;
}grafoM;

// Lista de adjacencia
typedef struct No
{
    int dado;
    struct No *prox;
}no;

typedef struct GrafoL
{
    int tam;
    no *listas;
}grafoL;


grafoM * cria_matrizAdj(int n)
{
    grafoM *g = malloc(sizeof(grafoM));
    g -> matriz = malloc(n * sizeof(int*));
    g -> tam = n;
    for(int i = 0; i < n; i++)
        g -> matriz[i] = calloc(n,sizeof(int));
    return g;
}

grafoL * cria_ListaAdj(int n)
{
    grafoL *g = malloc(sizeof(grafoL));
    g -> tam = n;
    g -> listas = malloc(n * sizeof(no));
    return g;
}


int busca_rec(grafoM *g,int *visitados, int w, int v)
{
    if(w == v) return 1;

    visitados[w] = 1;

    for(int i = 0; i < g -> tam; i++)
    {
        if(g->matriz[w][i] && !visitados[i])
            if(busca_rec(g, visitados, i, v))
            {   
                printf("%d ",i);
                return 1;
            }
    }
    return 0;
}
int existe_caminho(grafoM * g, int u, int v)
{
    int *visitados = malloc(g ->tam * sizeof(int));
    int encontrou = busca_rec(g,visitados,u,v);
    free(visitados);
    return encontrou;
}

// Função para adicionar uma aresta ao grafo
void adicionaAresta(grafoM *g, int origem, int destino) {
    if (origem < g->tam && destino < g->tam) {
        g->matriz[origem][destino] = 1;
        g->matriz[destino][origem] = 1;  // Para grafos não direcionados, comente esta linha se for direcionado
    }
}

// Função para imprimir a matriz de adjacência
void imprimeMatrizAdjacencia(grafoM *g) {
    printf("Matriz de Adjacência:\n");
    for (int i = 0; i < g->tam; i++) {
        for (int j = 0; j < g->tam; j++)
            printf("%d ", g->matriz[i][j]);
        printf("\n");
    }
}

// Função para liberar a memória alocada para a matriz de adjacência
void liberaMatrizAdj(grafoM *g) {
    for (int i = 0; i < g->tam; i++)
        free(g->matriz[i]);
    free(g->matriz);
    free(g);
}

int main()
{

    int n = 10;
    grafoM *g = cria_matrizAdj(n);

    // Adicionando arestas para garantir que todos os vértices estejam conectados

    adicionaAresta(g, 0, 1);
    adicionaAresta(g, 0, 2);
    adicionaAresta(g, 1, 2);
    adicionaAresta(g, 1, 3);
    adicionaAresta(g, 2, 4);
    adicionaAresta(g, 3, 2);
    adicionaAresta(g, 4, 5);
    adicionaAresta(g, 5, 8);
    adicionaAresta(g, 5, 9);
    adicionaAresta(g, 8, 9);
    adicionaAresta(g, 7, 3);

    existe_caminho(g, 0, 6);

    // Imprimindo a matriz de adjacência
    // imprimeMatrizAdjacencia(g);

    // Liberando a memória alocada
    liberaMatrizAdj(g);

    return 0;
}