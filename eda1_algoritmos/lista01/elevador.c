#include <stdio.h>

int main()
{
    int linhas,tamanhoMax, qtdAtual = 0, entrou, saiu, ultrapassou = 0;

    scanf("%d %d", &linhas, &tamanhoMax);

    for (int i = 0; i < linhas; i++)
    {
        scanf("%d %d", &saiu, &entrou);// leitura de quantos entraram e quantos sairam
        qtdAtual -= saiu;
        qtdAtual += entrou;
        if(qtdAtual > tamanhoMax)// verifica se extrapolou a quantidade permitida
            ultrapassou = 1;
    }
    
    if (ultrapassou)// se ultrapssar imprime S
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }
    
    
    return 0;
}