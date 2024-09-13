#include <stdio.h>

int main()
{
    int n;
    long long int media = 0;
    int numero;
    int temMaior = 0;
    int primeiroPrint = 1;

    scanf("%d", &n);
    int vetor[n];

    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &numero);
        vetor[i] = numero;
        media += numero;
    }
    media = media / n;

    for (i = 0; i < n; i++)
    {
        if (vetor[i] > media)
        {
            if (primeiroPrint)
                printf("%d", vetor[i]);
            else
                printf(" %d", vetor[i]);

            temMaior = 1;
            primeiroPrint = 0;
        }
    }

    if (!temMaior)
        printf("0");
    printf("\n");
    return 0;
}