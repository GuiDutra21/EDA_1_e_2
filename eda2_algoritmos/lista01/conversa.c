#include <stdio.h>
#include <stdlib.h>
// Assim como em outras questõe eu vou
// fazer um giro para a direita na direção horária na matriz

// 1 - Leste
// 2 - Oeste
// 3 - Sul
// 4 - Norte

int main()
{
    int colunas, linhas, micLinha, micColuna, repeticoes, movimento;
    int suspeitoLinha = 0, suspeitoColuna = 0, minutos = 0;
    scanf("%d %d", &colunas, &linhas);
    scanf("%d %d", &micLinha, &micColuna);
    scanf("%d", &repeticoes);

    for (int i = 0; i < repeticoes; i++)
    {
        scanf("%d", &movimento);

        switch (movimento)
        {
        case 1:
            suspeitoColuna++;
            break;
        case 2:
            suspeitoColuna--;
            break;
        case 3:
            suspeitoLinha++;
            break;
        case 4:
            suspeitoLinha--;
            break;

        default:
            break;
        }

        // if ((abs(micColuna - suspeitoColuna) + abs(micLinha - suspeitoLinha)) < 2)
        // {
        //     minutos++;
        // }
        // else if ((abs(micColuna - suspeitoColuna) < 2) && abs(micLinha - suspeitoLinha) < 2)
        if ((abs(micColuna - suspeitoColuna) < 2) && abs(micLinha - suspeitoLinha) < 2)
        {
            minutos++;
        }
        // printf("%d %d\n", abs(micColuna - suspeitoColuna), abs(micLinha - suspeitoLinha));
    }
    printf("%d\n", minutos);

    return 0;
}