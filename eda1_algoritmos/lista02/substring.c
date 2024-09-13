#include <stdio.h>
#include <string.h>

// função que encontra na primeira ocorrência da palavra a posicao do caracter posterior à palavra
int contadorIda(char *string, char *subString, int posicao1, int posicao2, int tamanho2, int qtdIgual)
{   
    // Se a quantidade de caracteres for igual, ou seja, se a palavra está contida já retorna a posicao do caracter posterior à palavra
    if(qtdIgual == strlen(subString)) 
    {
        return posicao1;
    }
    
    if(string[posicao1] == subString[posicao2])
    {
        return contadorIda(string, subString, ++posicao1, ++posicao2, tamanho2, ++qtdIgual); // Se for igual analisa os próximos caracteres
    }
    else if(string[posicao1] == '\0') // Se chegar no final da string retorna -1(que representa que a palavra não está contida)
        return -1;
    else if(string[posicao1] == subString[0]) // Se tiver o caracter igual ao do início da pavra começa a análise
        return contadorIda(string, subString, posicao1, 0, tamanho2, 0);
    else
         return contadorIda(string, subString, ++posicao1, 0, tamanho2, 0); // Se nada disso acontecer analise os próximos caracteres
}

// função que encontra na última ocorrência da palavra e retorna o caracter anterior a ela
int contadorVolta(char *string, char *subString, int posicao1, int posicao2, int tamanho2,int qtdIgual)
{   
    // Se a quantidade de caracteres for igual, ou seja, se a palavra está contida já retorna a posicao do caracter anterior à palavra
    if(qtdIgual == tamanho2)
    {   
        if(posicao1 == -1)
            return posicao1 + 1; // Ajuste para quando a palavra está no começo da string
        else
            return posicao1;
    }

    if(string[posicao1] == subString[posicao2]) // Se for agual parte a análise para os próximos caracteres
    {
        return contadorVolta(string, subString,--posicao1, --posicao2, tamanho2, ++qtdIgual);
    }
    else if(posicao1 == -1) // Se atingir o começo da string retorna -1(que representa que a palavra não está contida)
        return -1;
    else if(string[posicao1] == subString[tamanho2 - 1]) // Se tiver o caracter igual ao do final da pavra começa a análise
        return contadorVolta(string, subString, posicao1, tamanho2 - 1, tamanho2, 0);
    else
        return contadorVolta(string, subString,--posicao1,tamanho2 - 1,tamanho2, 0); // Se nada disso acontecer analise os próximos caracteres
}

int main()
{
    char string[101];
    char subString[101];

    scanf("%s",string);
    scanf("%s",subString);

    // somente para não precisar ficar calculando toda hora
    int tamanho1 = strlen(string);
    int tamanho2 = strlen(subString); 

    // Caracter após a primeira ocorrência da palavra
    int resultado1 = contadorIda(string, subString, 0, 0, tamanho2, 0);

    //Carater anterior a última occorêcnia da palavra
    int resultado2 = contadorVolta(string, subString, (tamanho1 - 1), (tamanho2 - 1),tamanho2, 0); 

    int resultado3 = 0;

    if(resultado1 != -1 && resultado2 != -1)
        resultado3 = resultado2 - resultado1 + (2 * strlen(subString) + 1); // Cálculo para imprimir a quantidade certa

    if(resultado3 != 0 && resultado3 == tamanho2 + 1)
        printf("%d\n",tamanho2); // Caso a palavra apareça apenas uma vez
    else
        printf("%d\n",resultado3);

    return 0;
}