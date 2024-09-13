#include <stdio.h>
#include <string.h>

int somar(char *vetor, int posicao)
{
    if(vetor[posicao] == '\0')
    {
        return 0;
    }
    else
    {
       // converte para inteiro e faz a soma
       return (vetor[posicao] - 48) + somar(vetor, ++posicao);
    }
}

int calculoDegrau(int soma, int degrau)
{   
    //printf("degrau %d\n",degrau);
    //printf("soma antes: %d\n",soma);
    int novaSoma = 0;
    int somaInicial = soma;

    if (soma >= 1000) {
        novaSoma += soma / 1000;
        soma = soma % 1000;
    }

    if (soma >= 100) {
        novaSoma += soma / 100;
        soma = soma % 100;
    }

    if (soma >= 10) {
        novaSoma += soma / 10;
        soma = soma % 10;
    }

    novaSoma += soma;

    //printf("soma depois : %d\n",novaSoma);

    if(novaSoma % 9 == 0 && somaInicial > 9)
    {   
        return calculoDegrau(novaSoma,++degrau);
    }
    else
    {
        //printf("%d\n",novaSoma);
        return degrau;
    }
}


int main()
{
    char entrada[1001];

    while(scanf("%s",entrada))
    {
        if(strlen(entrada) == 1  && entrada[0] == '0') // Condição de parada
        break;
        
        if(strlen(entrada) == 1  && entrada[0] == '9')
        {
            printf("9 is a multiple of 9 and has 9-degree 1.\n");
        }
        else
        {
            int soma = somar(entrada,0);

            if(soma % 9 == 0) 
            {   
                int degrais = calculoDegrau(soma,1);
                printf("%s is a multiple of 9 and has 9-degree %d.\n",entrada,degrais);
            }
            else
            {
                printf("%s is not a multiple of 9.\n",entrada);
            }
        }
    }
    return 0;
}