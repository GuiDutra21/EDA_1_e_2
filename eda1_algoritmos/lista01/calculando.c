#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int qtdEntradas,i,resposta,teste = 0,numero;
    
    while (scanf("%d",&qtdEntradas) && qtdEntradas != 0)
    {  
        // Zera o resultado a cada interacao para nao acumular 
        resposta = 0;
        char dados;


        // Le o primeiro numero
        scanf("%d",&resposta);

        // Le a operacao e depois o numero fazendo, assim, as operacoes informadas
        i = 1;
        while(i < (2 * qtdEntradas) - 1)
        {
            scanf("%c",&dados);
            if (dados == '+')
            {
                scanf("%d",&numero);
                resposta += numero;
                i+=2;
            }
            else
            {
                scanf("%d",&numero);
                resposta -= numero;
                i+=2;
            }
        }

       teste++;
       printf("Teste %d\n%d\n\n",teste,resposta);
        
    }

    return 0;
}