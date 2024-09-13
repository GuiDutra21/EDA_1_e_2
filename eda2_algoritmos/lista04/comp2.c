#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define swap(a, b) { int t = a; a = b; b = t; }

void heapify_down(int *heap, int tam, int idx, bool minHeap) {
    int left = 2 * idx, right = 2 * idx + 1, largest = idx;
    if (left <= tam && ((minHeap && heap[left] < heap[largest]) || (!minHeap && heap[left] > heap[largest]))) {
        largest = left;
    }
    if (right <= tam && ((minHeap && heap[right] < heap[largest]) || (!minHeap && heap[right] > heap[largest]))) {
        largest = right;
    }
    if (largest != idx) {
        swap(heap[largest], heap[idx]);
        heapify_down(heap, tam, largest, minHeap);
    }
}

void heapify_up(int *heap, int idx, bool minHeap) {
    int parent = idx / 2;
    while (parent > 0 && ((minHeap && heap[parent] > heap[idx]) || (!minHeap && heap[parent] < heap[idx]))) {
        swap(heap[parent], heap[idx]);
        idx = parent;
        parent = idx / 2;
    }
}

int espia(int *heap, int tam) {
    if (tam == 0)
        return 0;
    else
        return heap[1];
}

int retirar(int *heap, int *tam, bool minHeap) {
    int removido = heap[1];
    heap[1] = heap[*tam];
    (*tam)--;
    heapify_down(heap, *tam, 1, minHeap);
    return removido;
}

void inserir(int *heap, int valor, int *tam, bool minHeap) {
    heap[++(*tam)] = valor;
    heapify_up(heap, *tam, minHeap);
}

int main() {
    int qtdComponentes, limite, tamA = 0, tamB = 0;
    scanf("%d %d", &qtdComponentes, &limite);

    int *heapA = (int *)malloc((qtdComponentes + 1) * sizeof(int));
    int *heapB = (int *)malloc((qtdComponentes + 1) * sizeof(int));
    int *combinacoes = (int *)malloc((qtdComponentes + 1) * sizeof(int));

    int mineral, diferenca, menorA, maiorB, tamComponentes = 0;

    for (int i = 0; i < qtdComponentes; i++) {
        scanf("%d", &mineral);
        inserir(heapA, mineral, &tamA, true);
    }

    menorA = retirar(heapA, &tamA, true);
    inserir(heapB, menorA, &tamB, false);

    while (tamA > 0) {
        int dadoA = espia(heapA, tamA);
        int dadoB = espia(heapB, tamB);
        diferenca = abs(dadoA - dadoB);

        if (diferenca > 0 && diferenca <= limite) {
            menorA = retirar(heapA, &tamA, true);
            maiorB = retirar(heapB, &tamB, false);
            combinacoes[tamComponentes++] = menorA + maiorB;
        }

        if (tamA > 0) {
            menorA = retirar(heapA, &tamA, true);
            inserir(heapB, menorA, &tamB, false);
        }
    }

    printf("%d\n", tamComponentes);
    for (int j = 0; j < tamComponentes; j++) {
        printf("%d ", combinacoes[j]);
    }
    printf("\n");

    free(heapA);
    free(heapB);
    free(combinacoes);

    return 0;
}
