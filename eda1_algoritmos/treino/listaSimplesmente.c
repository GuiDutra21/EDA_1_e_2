// Lista Simplesmente encadeada com cabeça,
// sendo a cabeça um dado diferente do nó

#include <stdio.h>
#include <stdlib.h>

// nó
typedef struct No No;
typedef int Item;

struct No
{
    Item item;
    No *prox;
};

// cabeca
typedef struct Cabeca Cabeca;

struct Cabeca
{
    No *prox;
    No *ultimo;
    int qtdTotal;
};

Cabeca *criarLista()
{
    Cabeca *Cabeca = malloc(sizeof(Cabeca));
    if (Cabeca) // verifica se a alocação foi bem sucedida
        Cabeca->prox = NULL;
    Cabeca->ultimo = NULL;
    Cabeca->qtdTotal = 0;

    return Cabeca;
}

void criarPrimeiroNo(Cabeca *cabeca, Item novoItem)
{
    No *elemento = malloc(sizeof(No));
    if (elemento) // verifica se a alocação foi bem sucedida
    {
        if (cabeca->prox == NULL) // A cabeca está vazia
        {
            cabeca->prox = elemento;
            cabeca->ultimo = elemento;
            cabeca->qtdTotal++;
            elemento->prox = NULL;
            elemento->item = novoItem;
        }
    }
}

void inserirInicio(Cabeca *cabeca, Item novoItem)
{
    No *elemento = malloc(sizeof(No));
    if (elemento) // verifica se a alocação foi bem sucedida
    {
        elemento->prox = cabeca->prox;
        cabeca->prox = elemento;
        cabeca->qtdTotal++;
        elemento->item = novoItem;
    }
}

void inserirFinal(Cabeca *cabeca, Item novoItem)
{
    No *elemento = malloc(sizeof(No));
    if (elemento) // verifica se a alocação foi bem sucedida
    {
        cabeca->ultimo->prox = elemento;
        cabeca->ultimo = elemento;
        elemento->prox = NULL;
        elemento->item = novoItem;
        cabeca->qtdTotal++;
    }
}

No *procurarNo(Item item, No *elemento)
{
    if (elemento == NULL)
        return NULL; // caso não tenha numnhum elemento

    if (elemento->item == item)
        return elemento;
    else
        return procurarNo(item, elemento->prox);
}

void inserirAposOElemento(Cabeca *cabeca, Item novoItem, Item itemReferencia)
{
    No *novoNo = malloc(sizeof(No));
    No *noReferencia = procurarNo(itemReferencia, cabeca->prox);
    if (novoNo && noReferencia) // verifica se a alocação foi bem sucedida e se existe o elemento de referência
    {
        // Se o elemento de referência for o último, apenas chama a função de inserir no final
        if (cabeca->ultimo == noReferencia)
            inserirFinal(cabeca, novoItem);
        else
        {
            novoNo->prox = noReferencia->prox;
            noReferencia->prox = novoNo;
            novoNo->item = novoItem;
            cabeca->qtdTotal++;
        }
    }
}

No *procurarNoAnterior(Item item, No *elemento)
{
    if (elemento == NULL)
        return NULL; // caso não tenha numnhum elemento

    if (elemento->prox->item == item)
        return elemento;
    else
        return procurarNoAnterior(item, elemento->prox);
}

void inserirAntesDoElemento(Cabeca *cabeca, Item novoItem, Item itemReferencia)
{
    No *elemento = malloc(sizeof(No));

    // Se o elemento passado como referência for o primeiro, basta chamar a função de inserir no início
    if (elemento && itemReferencia == cabeca->prox->item)
    {
        inserirInicio(cabeca, novoItem);
    }
    else
    {
        // Literalmente o nó anterioir ao que desejamos inserir
        No *anterioir = procurarNoAnterior(itemReferencia, cabeca->prox);
        if (anterioir) // verifica se passou o elemento
        {
            elemento->prox = anterioir->prox;
            anterioir->prox = elemento;
            elemento->item = novoItem;
            cabeca->qtdTotal++;
        }
    }
}

void removerInicio(Cabeca *cabeca)
{
    if (cabeca->prox)
    {
        No *aux = cabeca->prox;
        cabeca->prox = cabeca->prox->prox;
        cabeca->qtdTotal--;
        free(aux);
    }
}

void removerFinal(Cabeca *cabeca)
{
    if (cabeca->prox)
    {
        No *novoUltimo = procurarNoAnterior(cabeca->ultimo->item, cabeca->prox);
        if (novoUltimo) // verifica se a alocação foi bem sucedida
        {
            free(cabeca->ultimo);
            cabeca->ultimo = novoUltimo;
            novoUltimo->prox = NULL;
            cabeca->qtdTotal--;
        }
    }
}

void removerElemento(Cabeca *cabeca, Item item)
{
    No *aux = procurarNoAnterior(item, cabeca->prox);
    if (aux)
    {
        No *aux2 = aux->prox;
        aux->prox = aux->prox->prox;
        cabeca->qtdTotal--;
        free(aux2);
    }
}

void printDaLista(No *elemento)
{
    printf("%d ", elemento->item); // printa os elementos

    if (elemento->prox == NULL) // quando chega no fim printa apenas o quebra de linha e para a funcao
        printf("\n");
    else
        printDaLista(elemento->prox);
}

int main()
{

    Cabeca *cabeca = criarLista();
    criarPrimeiroNo(cabeca, 10);
    inserirInicio(cabeca, 15);
    inserirFinal(cabeca, 22);
    inserirInicio(cabeca, 3);
    inserirAposOElemento(cabeca, 101, 10);
    inserirAntesDoElemento(cabeca, 99, 3);
    inserirAntesDoElemento(cabeca, 777, 101);
    removerInicio(cabeca);
    removerFinal(cabeca);
    removerElemento(cabeca, 10);

    printDaLista(cabeca->prox);
    printf("quantidade total de elementos %d\n", cabeca->qtdTotal);

    return 0;
}