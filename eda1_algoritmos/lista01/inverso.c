#include <stdio.h>

int main()
{
    char string[1001];

    scanf("%s",&string);

    int tamanho = 0;

    for (int  i = 0; string[i] != '\0'; i++)
    {
        tamanho++;
    }
    

    for(int i = tamanho - 1; i >=0 ; i--)
    {
        printf("%c",string[i]);
    }
    printf("\n");

    return 0;
}