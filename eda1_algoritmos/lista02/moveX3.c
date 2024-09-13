#include <stdio.h>
#include <string.h>

void mover(char *entrada, char *aux, int tamanho, int posicao, int posicaoAux)
{   
    if(tamanho >= posicaoAux)
    {
        if(entrada[posicao] == 'x') // se for um X salva no final
        {  
            aux[tamanho] = entrada[posicao];
            tamanho--;
        }
        else // se não for um X salva no inicio
        {
            aux[posicaoAux] = entrada[posicao];
            posicaoAux++;
        }

        posicao++;
        mover(entrada, aux, tamanho, posicao,posicaoAux);
    }
}

int main()
{
    char entrada[1001];
    char aux[1001];

    scanf("%s",entrada);
    int tamanho = strlen(entrada);
    mover(entrada, aux, tamanho - 1, 0, 0);
    aux[tamanho] = '\0';
    printf("%s\n",aux);

    return 0;
}