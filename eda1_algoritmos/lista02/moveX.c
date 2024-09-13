#include <stdio.h>
#include <string.h>

void move(char *string, int comeco, int fim) // vai trocando o elemento de um por um até o final da string
{
    if((fim - 1) != comeco) // termina a procura quando atingir o final da string
    {
        if (string[comeco + 1] != 'x') // Se o próximo elemento for algum 'x' não precisa continuar porque o resto já será x
        {
            int aux = string[comeco];
            string[comeco] = string[comeco + 1];
            string[comeco + 1] = aux;
            comeco++;
            move(string, comeco, fim);
        }
    }
}

// analisa posicao por posicao de forma decrescente, ou seja, começa da última
void identifica(char *string, int posicao) 
{
    if((-1) != posicao) // termina a procura quando atingir o incio da string
    {
        if(string[posicao] == 'x')
        {
            move(string, posicao, strlen(string)); // move o elemento
        }
        
        posicao--;
        identifica(string, posicao); // passa para o próximo elemento
    }
}

int main()
{
    char string[1001];
    scanf("%s",string);

    identifica(string,strlen(string));
    printf("%s\n",string);
    return 0;
}