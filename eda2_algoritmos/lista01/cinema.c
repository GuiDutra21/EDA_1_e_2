#include <stdio.h>

int main()
{
    int f, l, acentoNumero;
    char acentoLetra;
    scanf("%d %d", &f, &l);

    int matriz[f][l];

    // zerar a matriz
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < l; j++)
        {
            matriz[i][j] = 0;
        }
    }

    // salva os lugares na matriz
    while ((scanf(" %c", &acentoLetra)) != EOF)
    {
        scanf("%d", &acentoNumero);
        matriz[acentoLetra - 'A'][acentoNumero - 1] = 1;
    }

    // Começa os prints

    // Print dos números
    printf(" ");
    for (int i = 1; i < l + 1; i++)
    {
        printf(" %.2d", i);
    }
    printf("\n");

    // Print das letras e acentos
    for (int i = f - 1; i > -1; i--)
    {
        printf("%c", i + 'A');
        for (int j = 0; j < l; j++)
        {
            if (matriz[i][j])
                printf(" XX");
            else
                printf(" --");
        }
        printf("\n");
    }

    return 0;
}