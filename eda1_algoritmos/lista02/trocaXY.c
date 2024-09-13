#include <stdio.h>
#include <string.h>

void troca(char *string, int tamanho, int posicao)
{   
    // vai analisando de dois em dois
    if(posicao <= tamanho) 
    {
        if(string[posicao] == 'x')
            string[posicao] = 'y';
        
        if(posicao + 1 <= tamanho)
            if(string[posicao + 1] == 'x')
                string[posicao + 1] = 'y';
        troca(string, tamanho, posicao + 2);
    }
}

int main()
{
    char entrada[81];
    scanf("%s",entrada);

    troca(entrada,strlen(entrada),0);
    printf("%s\n",entrada);

    return 0;
}