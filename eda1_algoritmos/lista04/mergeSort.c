# include <stdio.h>
# include <stdlib.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}

void merge(int *vetor, int l, int m, int r)
{
    int tamanho = r - l + 1;
    int *vetorAux = malloc(tamanho * (sizeof(int)));

    if(vetorAux)
    {   
        int vetorDireita = m + 1; // inicio do sub-vetor a direita
        int vetorEsquerda = l;  // inicio do sib-vetor a esquerda

        int i = 0;
        while(vetorEsquerda <= m && vetorDireita <= r)
        {
            if(vetor[vetorEsquerda] < vetor[vetorDireita]) // se o elemento da esquerda for menor que o da direita entao coloca o da esquerda
                vetorAux[i++] = vetor[vetorEsquerda++];
            else
                    vetorAux[i++] = vetor[vetorDireita++];
                
        }

        // se ja tiver colocado todos os elementos da esquerda, tem que colocar os elementos que sobraram na direita
        if(vetorEsquerda == m + 1) 
        {   
           // printf("a\n");
            while(vetorDireita <= r) vetorAux[i++] = vetor[vetorDireita++];
        }
        else  // se ja tiver colocado todos os elementos da direita, tem que colocar os elementos que sobraram na esquerda
        {   
            //printf("b\n");
            while(vetorEsquerda <= m)  vetorAux[i++] = vetor[vetorEsquerda++];
        }

        i = 0;
        while(i < tamanho)
        {   
           // printf(" %d",vetorAux[i]);
            vetor[l++] =  vetorAux[i++];
        }
        //printf("\n");
        free(vetorAux);
    }
}

void mergeSort(int *vetor, int l, int r)
{
    if(l < r)
    {
        int m = (l + r)/2;
        mergeSort(vetor, l, m);
        mergeSort(vetor, m + 1, r);
        merge(vetor, l, m, r);
    }
}


int main()
{   
    int tamanho;
    scanf("%d",&tamanho);
    int vetor[tamanho];
    int i = 0;
    while (i < tamanho)
    {   
        scanf("%d",&vetor[i]);
        i++;
    }

    mergeSort(vetor,0,tamanho - 1);
    
    i = 1;
    printf("%d",vetor[0]);
    while(i < tamanho)
    {
        printf(" %d",vetor[i]);
        i++;
    }

    printf("\n");
    return 0;
}