#include <stdio.h>
#include <string.h>

void troca(char *string, int inicio, int fim)
{   
    if(inicio < fim) // vai trocando os elementos do inicio com os elementos do fim
    { 
        char aux = string[inicio];
        string[inicio] = string[fim];
        string[fim] = aux;

        troca(string, ++inicio, --fim);
    }
}

int main()
{   
    char entrada[501];
    scanf("%s",entrada);
    troca(entrada,0, strlen(entrada) - 1);
    printf("%s\n",entrada);

    return 0;
}