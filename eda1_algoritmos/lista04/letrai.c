

# include <stdio.h>
# include <stdlib.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}

void merge(int *vetor, int *vetorIndice, int l, int m, int r)
{
    int tamanho = r - l + 1;
    int *vetorAux = malloc(tamanho * (sizeof(int)));
    int *vetorAuxPosicao = malloc(tamanho * (sizeof(int)));

    if(vetorAux)
    {   
        int vetorDireita = m + 1; // inicio do sub-vetor a direita
        int vetorEsquerda = l;  // inicio do sib-vetor a esquerda

        int i = 0;
        while(vetorEsquerda <= m && vetorDireita <= r)
        {   
            // se o elemento da esquerda for menor que o da direita entao coloca o da esquerda
            if(vetor[vetorEsquerda] < vetor[vetorDireita])
            {
                vetorAux[i] = vetor[vetorEsquerda];
                vetorAuxPosicao[i++] = vetorIndice[vetorEsquerda++];
            }
            else
            {
                vetorAux[i] = vetor[vetorDireita];
                vetorAuxPosicao[i++] = vetorIndice[vetorDireita++];
            }
        }

        // se ja tiver colocado todos os elementos da esquerda, tem que colocar os elementos que sobraram na direita
        while(vetorDireita <= r)
        {
            vetorAux[i] = vetor[vetorDireita];
            vetorAuxPosicao[i++] = vetorIndice[vetorDireita++];
        }
        
        // se ja tiver colocado todos os elementos da direita, tem que colocar os elementos que sobraram na esquerda   
        while(vetorEsquerda <= m)
        {
            vetorAux[i] = vetor[vetorEsquerda];
            vetorAuxPosicao[i++] = vetorIndice[vetorEsquerda++];
        }

        i = 0;
        while(i < tamanho)
        {   
            vetor[l] =  vetorAux[i];
            vetorIndice[l++] = vetorAuxPosicao[i++];
        }
        free(vetorAux);
    }
}


void mergeSort(int *vetor,int *vetorIndice, int l, int r)
{
    if(l < r)
    {
        int m = (l + r)/2;
        mergeSort(vetor,vetorIndice, l, m);
        mergeSort(vetor, vetorIndice, m + 1, r);
        merge(vetor, vetorIndice, l, m, r);
    }
}

int buscaBinaria(int *vetorBusca,int l, int r, int elemento)
{
    if(l > r)
        return -1;
    
    int meio = (l + r)/2;
    if(elemento == vetorBusca[meio])
        return meio;

    if(elemento < vetorBusca[meio])
        return buscaBinaria(vetorBusca, l, meio - 1, elemento);
    return buscaBinaria(vetorBusca, meio + 1, r, elemento);
    
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int vetorBusca[n], vetorElementos[m], vetorPosicao[n];
    int i, j;
    for(i = 0; i < n;i++)
    {
        scanf("%d",&vetorBusca[i]);
        vetorPosicao[i] = i;
    }
    
    for(j = 0; j < m; j++)
        scanf("%d",&vetorElementos[j]);
    
    mergeSort(vetorBusca, vetorPosicao, 0, n - 1);

    for(int l = 0; l < m; l++)
    {
        if(vetorElementos[l] == vetorBusca[0])
            printf("%d\n",vetorPosicao[0]);
        else if(vetorElementos[l] == vetorBusca[n - 1])
            printf("%d\n",vetorPosicao[n - 1]);
        else
        {
            int posicao = buscaBinaria(vetorBusca,0, n, vetorElementos[l]);
            if(posicao == -1)
                printf("-1\n");
            else
                printf("%d\n",vetorPosicao[posicao]);
        }
    }
    return 0;
}