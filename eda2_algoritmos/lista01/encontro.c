#include <stdio.h>

// eu fiz algumas alterações no significado de alguns dados
// para ficar mais fácil de solucionar
// Dei um giro na matriz para a direita no sentido horário também

// Readaptação dos comandos
// 1 - Leste
// 2 - Oeste
// 3 - Sul
// 4 - Norte

void printSaiu(int pessoa, int linha, int coluna, int passo)
{
    if (pessoa)
        printf("PB saiu na posicao (%d,%d) no passo %d\n", linha, coluna, passo);
    else
        printf("PA saiu na posicao (%d,%d) no passo %d\n", linha, coluna, passo);
}

int main()
{
    int linhas, colunas, passoPa, passoPb, passos, saiu = 0, encontrou = 0;
    scanf("%d %d", &linhas, &colunas);

    int paLinha = 0, paColuna = 0, pbLinha = linhas - 1, pbColuna = colunas - 1;

    scanf("%d", &passos);

    for (int i = 0; i < passos; i++)
    {
        scanf("%d %d", &passoPa, &passoPb);

        switch (passoPa)
        {
        case 1:
            paColuna++;
            break;
        case 2:
            paColuna--;
            break;
        case 3:
            paLinha++;
            break;
        case 4:
            paLinha--;
            break;
        default:
            break;
        };

        if ((paColuna == colunas || paColuna < 0 || paLinha < 0 || paLinha == linhas) && saiu == 0)
        {
            printSaiu(0, paLinha + 1, paColuna + 1, i + 1);
            saiu = 1;
        }

        switch (passoPb)
        {
        case 1:
            pbColuna++;
            break;
        case 2:
            pbColuna--;
            break;
        case 3:
            pbLinha++;
            break;
        case 4:
            pbLinha--;
            break;
        default:
            break;
        };

        if ((pbColuna == colunas || pbColuna < 0 || pbLinha < 0 || pbLinha == linhas) && saiu == 0)
        {
            printSaiu(1, pbLinha + 1, pbColuna + 1, i + 1);
            saiu = 1;
        }

        if (paLinha == pbLinha && paColuna == pbColuna && saiu == 0 && encontrou == 0)
        {
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", paLinha + 1, pbColuna + 1, i + 1);
            encontrou = 1;
        }
    }

    if (!encontrou && !saiu)
        printf("Nao se encontraram\n");

    return 0;
}