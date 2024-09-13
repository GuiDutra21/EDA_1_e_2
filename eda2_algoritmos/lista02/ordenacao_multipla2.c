#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double dado;
    int linha;
    int coluna;
}elemento;

void swap(elemento *a, elemento *b)
{
    elemento aux = *a;
    *a = *b;
    *b = aux;
}

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

void mergeSort(elemento *vet, int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;
        mergeSort(vet, l , m);
        mergeSort(vet, m + 1, r);
        merge(vet,l,r,m, (r - l) + 1);
    }
}

int main()
{
    int repeticoesTotal, linhas, colunas, indice, tamanho;
    double numeros;
    int i,j;

    scanf("%d",&repeticoesTotal);

    while(repeticoesTotal > 0)
    {
        scanf("%d %d",&linhas, &colunas);
        indice = 0;
        tamanho = linhas * colunas;

        elemento *vet = malloc(sizeof(elemento) * tamanho);
        for(i = 0, j = 0; i < linhas; i++)
        {
            for(j = 0; j < colunas; j++)
            {
                scanf("%lf",&numeros);
                vet[indice].dado = numeros;
                vet[indice].linha = i + 1;
                vet[indice].coluna = j + 1;
                indice++;
            }
        }
       
        mergeSort(vet,0, tamanho - 1);

        printf("%d,%d",vet[0].linha, vet[0].coluna);
        for(i = 1; i < tamanho; i++)
        {
        //         printf("%lf ",vet[i].dado);
        //         printf("(%d ",vet[i].linha);
        //         printf("%d) ",vet[i].coluna);
                    printf(" %d,%d",vet[i].linha, vet[i].coluna);
        }
                printf("\n");
        repeticoesTotal --;
        free(vet);
    }

    return 0;
}