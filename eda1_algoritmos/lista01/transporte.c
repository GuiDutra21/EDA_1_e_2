#include <stdio.h>

int main()
{   
    int containerA, containerB, containerC, barcoA, barcoB, barcoC;

    scanf("%d %d %d", &containerA, &containerB, &containerC);
    scanf("%d %d %d", &barcoA, &barcoB, &barcoC);

    // Caso alguam dimensao do container seja maior do que a do barco ja imprime zero
    if(containerA > barcoA || containerB > barcoB || containerC > barcoC)
    {
        printf("0\n");
    }    
    else
    {   // Divide os tamanhos e gera o resultado multiplicando tudo
        int qtdA = barcoA/containerA;
        int qtdB = barcoB/containerB;
        int qtdC = barcoC/containerC;
        printf("%d",qtdA * qtdB *qtdC);
    }

    return 0;
}