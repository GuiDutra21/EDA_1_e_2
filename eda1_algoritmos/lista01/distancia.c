#include <stdio.h>

int main()
{   
    int linhaMaria, colunaMaria, linhaDestino, colunaDestino;

    scanf("%d %d",&linhaMaria ,&colunaMaria);
    scanf("%d %d",&linhaDestino ,&colunaDestino);

    //Calcula a quantidade de linhas que ela precisa andar,em modulo
    int sub1 = linhaDestino - linhaMaria;
    if(sub1 < 0) sub1*=(-1);

    //Calcula a quantidade de colunas que ela precisa andar, em modulo
    int sub2 = colunaDestino - colunaMaria;
    if(sub2 < 0) sub2*=(-1);

    //a soma representa a quantidade de cruzamentos
    printf("%d\n",sub1 + sub2);

    return 0;
}