#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define show(n) printf("%d\n", n);
#define entrou printf("ENTROU\n");
#define swap(c1, c2) {int c = c1; c1 = c2; c2 = c;}
#define MAIN main

typedef struct dado_ {
	int tamanho;
	char caracter;
	int inicio;
} dado;

void merge(dado *vet, int l, int media, int r)
{
	dado *aux;
	int x, i, j;

	aux = malloc(sizeof(dado) * (r + 1 - l));
	x = 0;
	i = l;
	j = media + 1;

	while (i <= media && j <= r)
		aux[x++] = vet[i].tamanho >= vet[j].tamanho ? vet[i++] : vet[j++];

	while (i <= media)
		aux[x++] = vet[i++];

	while (j <= r)
		aux[x++] = vet[j++];

	x = 0;
	for (i = l; i <= r; i++)
		vet[i] = aux[x++];

	free(aux);
}

void merge_sort(dado *vet, int l, int r)
{
	int media;

	if (l >= r)
		return;

	media = l + (r - l)/2;
	merge_sort (vet, l, media);
	merge_sort (vet, media + 1, r);
	merge (vet, l, media, r);
}

int MAIN(void)
{
	char c, ant, i, posicao;
	dado *vet;

	i = posicao = 0;
	vet = malloc(sizeof(dado)*100001);
	
	c = getchar();
	vet[i].tamanho = 1;
	vet[i].caracter = c;
	vet[i].inicio = posicao;
	posicao = 1;	
	ant = c;
	while ((c = getchar()) != '\n') {
		if (ant != c) {
			i++;
			vet[i].tamanho = 1;
			vet[i].caracter = c;
			vet[i].inicio = posicao;
		}
		else
			vet[i].tamanho += 1;
		posicao++;
		ant = c;
	}
	merge_sort(vet, 0, i);

	for (int j = 0; j <= i; j++) 
		printf("%d %c %d\n", vet[j].tamanho, vet[j].caracter, vet[j].inicio);

	return 0;
}