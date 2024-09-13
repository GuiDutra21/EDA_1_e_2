#include<stdio.h>
#include<stdlib.h>
#define swap(a,b) {int t; t = a; a = b; b = t;}

int espia(int *heap, int tam)
{   
    if(tam == 0)
        return 0;
    else
        return heap[1];
}

// A variável min representa qual heap está sendo passada
int retirar(int *heap, int *tam)
{
    int removido = heap[1];
    swap(heap[1],heap[*tam]);
    (*tam)--;

    int aux = 1;
    int menor;
    // Conserta a heap para minimo (fixDown)
        while(aux * 2 <= *tam)
        {   
            menor = 2 * aux;
            if(menor < *tam && heap[menor] > heap[menor + 1]) menor++;
            if(heap[menor] < heap[aux])
            {
                swap(heap[menor],heap[aux]);
                aux = menor;
            }
            else
                break;
        }
    
    return removido;
}


void inserir(int *heap, int minerio, int posicaoLivre)
{   
    heap[posicaoLivre] = minerio;
  
    // Arruma a primoridade da heap de mínimo (fixUp)
    int pai = posicaoLivre/2, aux = posicaoLivre;
        while (pai > 0 && heap[pai] > heap[aux])
        {
            swap(heap[pai],heap[aux]);
            aux = pai;
            pai = pai/2;
        }
}

int main()
{
    int qtdComponentes,limite,tamA = 0, tamB = 0;
    scanf("%d %d",&qtdComponentes ,&limite);

    // a posição de índice 0 é ignorada na heap
    int heapA[qtdComponentes + 1];
    int tuboB[qtdComponentes + 1];


    int mineral, diferenca, dadoA, tamComponentes = 0;
    int combinacoes[qtdComponentes + 1];

    // Insere todos os minerais na heap (tubo A)
    for(int i = 0; i < qtdComponentes; i++)
    {
        scanf("%d",&mineral);
        tamA++;
        inserir(heapA,mineral,tamA);
    }
        tuboB[tamB++] = retirar(heapA,&tamA); // Ja coloca o menor elemento de A em B

    while(espia(heapA,tamA))
    {   
        dadoA = retirar(heapA,&tamA);
        // printf("dadoA : %d\n",dadoA);
        // diferenca = dadoA - tuboB > 0 ? dadoA - tuboB : tuboB - dadoA;
        diferenca = dadoA - tuboB[tamB - 1];
        if(diferenca > 0 && diferenca <= limite)
        {  
            combinacoes[tamComponentes] = dadoA + tuboB[--tamB];
            tamComponentes++;
            if(tamB == 0)
                tuboB[tamB++] = retirar(heapA,&tamA);
        }
        else
            tuboB[tamB++] = dadoA;
        
    }
    printf("%d\n",tamComponentes);
    for(int j = 0; j < tamComponentes; j++)
    {
        printf("%d ",combinacoes[j]);
    }
    if(tamComponentes != 0)
        printf("\n");
    return 0;
}