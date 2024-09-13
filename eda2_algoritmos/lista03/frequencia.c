#include <stdio.h>
#include <stdlib.h>

typedef struct vet
{
    char caracter;
    int frequencia;
} vet;

void merge(vet *vetor, int l, int m, int r)
{
    int tamanho = r - l + 1;
    vet *vetorAux = malloc(tamanho * (sizeof(vet)));

    if (vetorAux)
    {
        int vetorDireita = m + 1; // inicio do sub-vetor a direita
        int vetorEsquerda = l;    // inicio do sub-vetor a esquerda

        int i = 0;
        while (vetorEsquerda <= m && vetorDireita <= r)
        {
            // se o elemento da esquerda for menor ou igual que o da direita entao coloca o da esquerda
            if (vetor[vetorEsquerda].frequencia < vetor[vetorDireita].frequencia ||
                (vetor[vetorEsquerda].frequencia == vetor[vetorDireita].frequencia && vetor[vetorEsquerda].caracter < vetor[vetorDireita].caracter))
            {
                vetorAux[i++] = vetor[vetorEsquerda++];
            }
            else
            {
                vetorAux[i++] = vetor[vetorDireita++];
            }
        }

        // se ja tiver colocado todos os elementos da esquerda, tem que colocar os elementos que sobraram na direita
        while (vetorDireita <= r)
            vetorAux[i++] = vetor[vetorDireita++];

        // se ja tiver colocado todos os elementos da direita, tem que colocar os elementos que sobraram na esquerda
        while (vetorEsquerda <= m)
            vetorAux[i++] = vetor[vetorEsquerda++];

        i = 0;
        while (i < tamanho)
        {
            vetor[l++] = vetorAux[i++];
        }
        free(vetorAux);
    }
}

void mergeSort(vet *vetor, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(vetor, l, m);
        mergeSort(vetor, m + 1, r);
        merge(vetor, l, m, r);
    }
}

int main()
{
    vet *vet;
    int i;

    char palavra[1001];
    while ((scanf("%s", palavra)) != EOF)
    {

        vet = calloc(94, sizeof(vet));
        i = 0;
        while (palavra[i] != '\0')
        {
            vet[palavra[i] - 33].caracter = palavra[i];
            vet[palavra[i] - 33].frequencia++;
            i++;
        }

        mergeSort(vet, 0, 93);

        while (i < 94)
        {
            if (vet[i].frequencia != 0)
            {
                printf("%d %d\n", vet[i].caracter, vet[i].frequencia);
            }
            i++;
        }
        free(vet);
        printf("\n");
    }
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef struct vet
// {
//     char caracter;
//     int frequencia;
// } vet;

// void merge(vet *vetor, int l, int m, int r)
// {
//     int tamanho = r - l + 1;
//     vet *vetorAux = malloc(tamanho * sizeof(vet));

//     if (vetorAux)
//     {
//         int vetorDireita = m + 1;
//         int vetorEsquerda = l;

//         int i = 0;
//         while (vetorEsquerda <= m && vetorDireita <= r)
//         {
//             if (vetor[vetorEsquerda].frequencia < vetor[vetorDireita].frequencia ||
//                 (vetor[vetorEsquerda].frequencia == vetor[vetorDireita].frequencia && vetor[vetorEsquerda].caracter < vetor[vetorDireita].caracter))
//             {
//                 vetorAux[i++] = vetor[vetorEsquerda++];
//             }
//             else
//             {
//                 vetorAux[i++] = vetor[vetorDireita++];
//             }
//         }

//         while (vetorDireita <= r)
//             vetorAux[i++] = vetor[vetorDireita++];
//         while (vetorEsquerda <= m)
//             vetorAux[i++] = vetor[vetorEsquerda++];

//         for (i = 0; i < tamanho; i++)
//         {
//             vetor[l + i] = vetorAux[i];
//         }

//         free(vetorAux);
//     }
// }

// void mergeSort(vet *vetor, int l, int r)
// {
//     if (l < r)
//     {
//         int m = (l + r) / 2;
//         mergeSort(vetor, l, m);
//         mergeSort(vetor, m + 1, r);
//         merge(vetor, l, m, r);
//     }
// }

// int main()
// {
//     vet *vetor;
//     char palavra[1001];
//     int first = 1;

//     while (scanf("%s", palavra) != EOF)
//     {
//         vetor = calloc(94, sizeof(vet));

//         int i = 0;
//         while (palavra[i] != '\0')
//         {
//             vetor[palavra[i] - 33].caracter = palavra[i];
//             vetor[palavra[i] - 33].frequencia++;
//             i++;
//         }

//         mergeSort(vetor, 0, 93);

//         if (!first)
//         {
//             printf("\n");
//         }
//         first = 0;

//         for (i = 0; i < 94; i++)
//         {
//             if (vetor[i].frequencia != 0)
//             {
//                 printf("%d %d\n", vetor[i].caracter, vetor[i].frequencia);
//             }
//         }

//         free(vetor);
//     }

//     printf("\n");
//     return 0;
// }