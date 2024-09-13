#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }

void insertionSort(int *vetor, int l, int r)
{

    int aux, j;
    int i = l + 1;
    while (i <= r)
    {
        aux = vetor[i];
        j = i;
        while (j > l && aux < vetor[j - 1])
        {
            vetor[j] = vetor[j - 1];
            j--;
        }

        vetor[j] = aux;
        i++;
    }
}

void merge(int *vetor, int l, int m, int r)
{
    int tamanho = r - l + 1;
    int *vetorAux = malloc(tamanho * (sizeof(int)));

    if (vetorAux)
    {
        int vetorDireita = m + 1; // inicio do sub-vetor a direita
        int vetorEsquerda = l;    // inicio do sub-vetor a esquerda

        int i = 0;
        while (vetorEsquerda <= m && vetorDireita <= r)
        {
            if (vetor[vetorEsquerda] < vetor[vetorDireita]) // se o elemento da esquerda for menor que o da direita entao coloca o da esquerda
                vetorAux[i++] = vetor[vetorEsquerda++];
            else
                vetorAux[i++] = vetor[vetorDireita++];
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

void mergeSort(int *vetor, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(vetor, l, m);
        mergeSort(vetor, m + 1, r);
        merge(vetor, l, m, r);
    }
}

void merge2(int *vetor, int *vetorIndice, int l, int m, int r)
{
    int tamanho = r - l + 1;
    int *vetorAux = malloc(tamanho * (sizeof(int)));
    int *vetorAuxPosicao = malloc(tamanho * (sizeof(int)));

    if (vetorAux)
    {
        int vetorDireita = m + 1; // inicio do sub-vetor a direita
        int vetorEsquerda = l;    // inicio do sib-vetor a esquerda

        int i = 0;
        while (vetorEsquerda <= m && vetorDireita <= r)
        {
            // se o elemento da esquerda for menor que o da direita entao coloca o da esquerda
            if (vetor[vetorEsquerda] < vetor[vetorDireita])
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
        while (vetorDireita <= r)
        {
            vetorAux[i] = vetor[vetorDireita];
            vetorAuxPosicao[i++] = vetorIndice[vetorDireita++];
        }

        // se ja tiver colocado todos os elementos da direita, tem que colocar os elementos que sobraram na esquerda
        while (vetorEsquerda <= m)
        {
            vetorAux[i] = vetor[vetorEsquerda];
            vetorAuxPosicao[i++] = vetorIndice[vetorEsquerda++];
        }

        i = 0;
        while (i < tamanho)
        {
            vetor[l] = vetorAux[i];
            vetorIndice[l++] = vetorAuxPosicao[i++];
        }
        free(vetorAux);
    }
}

void mergeSort2(int *vetor, int *posicoes, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort2(vetor, posicoes, l, m);
        mergeSort2(vetor, posicoes, m + 1, r);
        merge2(vetor, posicoes, l, m, r);
    }
}

void elegeIguais(int *cadidatos, int l, int r, int *quantidadeVagas)
{
    for (int i = r; i >= l; i--)
    {
        if (*quantidadeVagas == 0)
            return;
        printf("%d ", cadidatos[i]);
        --*quantidadeVagas;
    }
}

void elegeCandidato(int *votos, int *candidato, int l, int r, int quantidadeVagas)
{
    int fimIguais;

    for (int i = r; l <= i; i--)
    {
        if (quantidadeVagas == 0)
            return;
        if (i == l)
        {
            printf("%d", candidato[l]);
            continue;
        }
        if (votos[i] > votos[i - 1])
        {
            printf("%d ", candidato[i]);
            quantidadeVagas--;
            continue;
        }

        fimIguais = i;
        for (; votos[i] == votos[i - 1]; i--)
            ;
        insertionSort(candidato, i, fimIguais);
        elegeIguais(candidato, i, fimIguais, &quantidadeVagas);

        i++;
    }
}

int main()
{
    int vagasSenadores, vagasFederais, vagasEstaduais;
    int votosValidos = 0;
    int votosInvalidos = 0;
    int tamPresidente = 1000, *presidentes = malloc(sizeof(int) * tamPresidente), p = -1;
    int tamSenadores = 1000, *senadores = malloc(sizeof(int) * tamSenadores), s = -1;
    int tamFederais = 1000, *federais = malloc(sizeof(int) * tamFederais), df = -1;
    int tamEstaduais = 1000, *estaduais = malloc(sizeof(int) * tamEstaduais), de = -1;

    scanf("%d %d %d", &vagasSenadores, &vagasFederais, &vagasEstaduais);
    int numeroCandidato;
    while ((scanf("%d", &numeroCandidato)) != EOF)
    {
        if (numeroCandidato < 0)
        {
            votosInvalidos++;
            continue;
        }

        votosValidos++;

        if (numeroCandidato < 100)
        {
            if (++p == tamPresidente)
            {
                tamPresidente *= 2;
                presidentes = realloc(presidentes, sizeof(int) * tamPresidente);
            }
            presidentes[p] = numeroCandidato;
        }
        else if (numeroCandidato < 1000)
        {
            if (++s == tamSenadores)
            {
                tamSenadores *= 2;
                senadores = realloc(senadores, sizeof(int) * tamSenadores);
            }
            senadores[s] = numeroCandidato;
        }
        else if (numeroCandidato < 10000)
        {
            if (++df == tamFederais)
            {
                tamFederais *= 2;
                federais = realloc(federais, sizeof(int) * tamFederais);
            }
            federais[df] = numeroCandidato;
        }
        else
        {
            if (++de == tamEstaduais)
            {
                tamEstaduais *= 2;
                presidentes = realloc(estaduais, sizeof(int) * tamEstaduais);
            }
            estaduais[de] = numeroCandidato;
        }
    }

    mergeSort(presidentes, 0, p);
    mergeSort(senadores, 0, s);
    mergeSort(federais, 0, df);
    mergeSort(estaduais, 0, de);

    int *votosPresidente = calloc(p, sizeof(int));
    votosPresidente[0] = 1;
    int rearanjaPresidentes = 0;

    for (int i = 1; i <= p; i++)
    {
        if (presidentes[i] != presidentes[i - 1])
        {
            votosPresidente[++rearanjaPresidentes]++;
            presidentes[rearanjaPresidentes] = presidentes[i];
        }
        else
            votosPresidente[rearanjaPresidentes]++;
    }

    mergeSort2(votosPresidente, presidentes, 0, rearanjaPresidentes);

    printf("%d %d\n", votosValidos, votosInvalidos);

    if ((votosPresidente[rearanjaPresidentes] * 100) / (p + 1) >= 51)
        printf("%d\n", presidentes[rearanjaPresidentes]);
    else
        printf("segundo turno\n");

    free(presidentes);
    free(votosPresidente);

    int *votosSenadores = calloc(s, sizeof(int));
    votosSenadores[0] = 1;
    int rearanjaSenadores = 0;

    for (int i = 1; i <= s; i++)
    {
        if (senadores[i] != senadores[i - 1])
        {
            votosSenadores[++rearanjaSenadores]++;
            senadores[rearanjaSenadores] = senadores[i];
        }
        else
            votosSenadores[rearanjaSenadores]++;
    }
    mergeSort2(votosSenadores, senadores, 0, rearanjaSenadores);

    if (rearanjaSenadores == 0)
        printf("%d", senadores[0]);
    else
        elegeCandidato(votosSenadores, senadores, 0, rearanjaSenadores, vagasSenadores);

    free(senadores);
    free(votosSenadores);

    printf("\n");

    int *votosFederais = calloc(df, sizeof(int));
    votosFederais[0] = 1;
    int rearanjaFederais = 0;

    for (int i = 1; i <= df; i++)
    {
        if (federais[i] != federais[i - 1])
        {
            votosFederais[++rearanjaFederais]++;
            federais[rearanjaFederais] = federais[i];
        }
        else
            votosFederais[rearanjaFederais]++;
    }
    mergeSort2(votosFederais, federais, 0, rearanjaFederais);

    if (rearanjaFederais == 0)
        printf("%d", federais[0]);
    else
        elegeCandidato(votosFederais, federais, 0, rearanjaFederais, vagasFederais);

    free(federais);
    free(votosFederais);

    printf("\n");

    int *votosEstaduais = calloc(de, sizeof(int));
    votosEstaduais[0] = 1;
    int rearanjaEstaduais = 0;

    for (int i = 1; i <= de; i++)
    {
        if (estaduais[i] != estaduais[i - 1])
        {
            votosEstaduais[++rearanjaEstaduais]++;
            estaduais[rearanjaEstaduais] = estaduais[i];
        }
        else
            votosEstaduais[rearanjaEstaduais]++;
    }
    mergeSort2(votosEstaduais, estaduais, 0, rearanjaEstaduais);

    if (rearanjaEstaduais == 0)
        printf("%d", estaduais[0]);
    else
        elegeCandidato(votosEstaduais, estaduais, 0, rearanjaEstaduais, vagasEstaduais);

    free(estaduais);
    free(votosEstaduais);

    printf("\n");
}