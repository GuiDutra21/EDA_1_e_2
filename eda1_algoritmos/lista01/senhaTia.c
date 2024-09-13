#include <stdio.h>

int main()
{   
    int qtdEsperado, miniEsperado, superEsperado, numerosEsperado;
    int qtdReal = 0, miniReal = 0, superReal = 0, numeroReal = 0;
    char palavra[1001];

    scanf("%d %d %d %d",&qtdEsperado, &miniEsperado, &superEsperado, &numerosEsperado);

    scanf("%s",palavra);
    
    for(int i = 0; palavra[i] != '\0'; i++)
    {
        qtdReal++;
        if(palavra[i] > 64 && palavra[i] < 91)
            superReal++;

        if(palavra[i] > 96 && palavra[i] < 123)
            miniReal++;

        if(palavra[i] > 47 && palavra[i] < 58)
            numeroReal++;
    }   
        //printf("%d %d %d %d\n",qtdReal, miniReal, superReal, numeroReal);

        if(miniEsperado <= miniReal && qtdEsperado <= qtdReal && superEsperado <= superReal && numerosEsperado <= numeroReal)
            printf("Ok =/\n");
        else
            printf("Ufa :)\n");
    return 0;
}