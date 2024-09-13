#include <stdio.h>

int main()
{   
    int casos;
    int teste = 1;
    while ((scanf("%d", &casos)) && casos != 0)
    {   
        int aldoFinal = 0, betoFinal = 0;
        int aldoAtual, betoAtual;
        for(int i = 0;i < casos; i++)
        {   
            scanf("%d", &aldoAtual);
            aldoFinal += aldoAtual; 
            scanf("%d", &betoAtual);
            betoFinal += betoAtual;
        }

        printf("Teste %d\n",teste);
        if(aldoFinal > betoFinal)
            printf("Aldo\n\n");
        else
            printf("Beto\n\n");
        teste++;
    }
    return 0;
}