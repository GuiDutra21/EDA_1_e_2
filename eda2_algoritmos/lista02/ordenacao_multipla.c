#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double dado;
    int linha;
    int coluna;
}elemento;

void merge(elemento *vet, int l, int r, int m, int tamanho)
{
    elemento *vetAux = malloc(sizeof(elemento) * tamanho);
    int i = l, j = m + 1, indiceAux = 0;

    while(i < m +1  && j < r + 1)
    {   
        if(vet[i].dado > vet[j].dado)
            vetAux[indiceAux++] = vet[i++];

        else if(vet[i].dado < vet[j].dado)
            vetAux[indiceAux++] = vet[j++];
        
        else  // Critérios de desempate baseado na linha e na coluna
        {
            if(vet[i].linha == vet[j].linha)
            {
                if(vet[i].coluna < vet[j].coluna)
                    vetAux[indiceAux++] = vet[i++];
                else
                    vetAux[indiceAux++] = vet[j++];
            }
            else if(vet[i].linha < vet[j].linha)
                vetAux[indiceAux++] = vet[i++];
            else
                vetAux[indiceAux++] = vet[j++];
        }
    }

    while(i < m + 1)
        vetAux[indiceAux++] = vet[i++];

    while(j < r + 1)
        vetAux[indiceAux++] = vet[j++];

    indiceAux=0;
    while(l < r + 1)
        vet[l++] = vetAux[indiceAux++];
    
    free(vetAux);
}

// Estratégia de ordenar os vetores de dois em dois e assim sucessivamente até não restar nenhum
void mergeSort(elemento *vet,int l, int qtdVetores, int tamVetor)
{   
    int tamInicial = tamVetor;
    int tamanhoTotal = qtdVetores * tamInicial;

    // Caso tenhamos uma quantidade ímpar de vetores a serem ordenados
    // Vou deixar para ordenar apenas no final o último vetor no conjunto todo
    if(qtdVetores%2 != 0)
    {    
        // Quando o laço terminar, ainda restará 2 vetores
        // um que resulta da ordenção de todos os outros e um que não foi alterado
        for(int i = 0; qtdVetores > 2;i++)
        {   
            l = 0;
            tamVetor*=2;

            // Laço para fazer o merge entre dois vetores a cada iteração
            while(l + tamVetor <= tamanhoTotal)
            {
                merge(vet,l, (l + tamVetor) - 1,tamVetor/2 + l - 1, tamVetor);
                qtdVetores --;
                l += tamVetor;
            }
        }   

        // Último merge com o vetor que foi deixado de lado 
        merge(vet, 0, tamanhoTotal - 1,tamanhoTotal - tamInicial - 1, tamanhoTotal);
    }
    else
    {
         for(int i = 0; qtdVetores > 1;i++)
        {   
            l = 0;
            tamVetor*=2;

            // Laço para fazer o merge entre dois vetores a cada iteração
            while(l + tamVetor <= tamanhoTotal)
            {
                merge(vet,l, (l + tamVetor) - 1,tamVetor/2 + l - 1, tamVetor);
                qtdVetores --;
                l += tamVetor;
            }
        }   
    }
}

int main()
{
    int repeticoesTotal, linhas, colunas, posicao;
    double numeros;
    int i,j;
    scanf("%d",&repeticoesTotal);
    while(repeticoesTotal > 0)
    {
        scanf("%d %d",&linhas, &colunas);
        posicao = 0;

        elemento *vet = malloc(sizeof(elemento) * linhas * colunas);
        for(i = 0, j = 0; i < linhas; i++)
        {
            for(j = 0; j < colunas; j++)
            {
                scanf("%lf",&numeros);
                vet[posicao].dado = numeros;
                vet[posicao].linha = i + 1;
                vet[posicao].coluna = j + 1;
                posicao++;
            }
        }
       
        mergeSort(vet,0,linhas,colunas);
        printf("%d,%d",vet[0].linha, vet[0].coluna);
        for(i = 1; i < linhas * colunas; i++)
        {
                // printf("%lf ",vet[i].dado);
                // printf("(%d ",vet[i].linha);
                // printf("%d) ",vet[i].coluna);
                printf(" %d,%d",vet[i].linha, vet[i].coluna);
        }
                printf("\n");
        repeticoesTotal --;
        free(vet);
    }

    return 0;
}
        