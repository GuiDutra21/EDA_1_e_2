#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define swap(a,b) {int t; t = a; a = b; b = t;}

// a posição de índice 0 é ignorada
void inserir(int *heap, int placa, int posicaoLivre)
{   
    heap[posicaoLivre] = placa;
  
    // Arruma a primoridade da heap
    int pai = posicaoLivre/2, aux = posicaoLivre;
    while (pai > 0 && heap[pai] > heap[aux])
    {
        swap(heap[pai],heap[aux]);
        aux = pai;
        pai = pai/2;
    }
}

void retiraMenor(int *heap, int *tam, int qtdRetirar, int *vetAux)
{
    int i = 0;
    while(i < qtdRetirar)
    {   
        printf("%d ",heap[1]);
        vetAux[i] = heap[1];
        swap(heap[*tam],heap[1]);
        (*tam)--;

        // Conserta a heap
        int aux = 1;
        int menor;
        while(aux * 2 <= *tam)
        {   
            menor = 2 * aux;
            if(menor < *tam && heap[menor] > heap[menor + 1]) menor++;
            if(heap[aux] > heap[menor]) 
            {
                swap(heap[aux], heap[menor]);
                aux = menor;
            }
            else 
                break;
        }
        i++;
    }
    printf("\n");
}

int main()
{
    int acao, placa, qtdImpressao, tamanho = 1000000, reinserir = 0;
    int *heap = malloc(1000000 * sizeof(int)); // Heap com prioridade mínima
    int vetAux[100]; // Para reinserir os elementos retirados

    heap[0] = 0;
    int qtdPlaca = 0;
    while(scanf("%d",&acao) != EOF)
    {   
        // Reinsere os elementos que foram colocados no final da heap
        if(reinserir == 1)
        {   
            for(int i = 0;i < qtdImpressao;i++)
            {   
                qtdPlaca++;
                inserir(heap,vetAux[i],qtdPlaca);
            }
            reinserir = 0;
        }

        if(acao == 1) // Quando é 1 insere
        {
            qtdPlaca++;
            if(qtdPlaca == tamanho)
            {
                heap = realloc(heap,tamanho * 2 * sizeof(int));
                tamanho *= 2;
            }
            
            scanf("%d",&placa);
            inserir(heap, placa, qtdPlaca);
        }
        else  // Quando é 2 imprime X caracteres
        {   
            scanf("%d",&qtdImpressao);
            if(qtdImpressao == 1)
                printf("%d\n",heap[1]);
            else
            {   
                if(qtdImpressao >qtdPlaca) qtdImpressao = qtdPlaca;
                retiraMenor(heap, &qtdPlaca, qtdImpressao, vetAux);
                reinserir = 1;
            }
        }
    }

    free(heap);
    return 0;
}