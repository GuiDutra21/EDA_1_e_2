#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int qtdAeroporto, qtdVoos, *vetor, saida, chegada, qtdTestes = 1, maior;
    while(scanf("%d %d",&qtdAeroporto, &qtdVoos) && qtdAeroporto != 0 && qtdVoos != 0)
    {   
        // De forma dinâmica cria o vetor que cada índice corresponde aos aeroportos
        vetor = calloc(qtdAeroporto, sizeof(int));

        if(vetor)// Verificação
        {   
            // Dado os voos soma em cada aeroporto(índice)
            for(int i = 0; i < qtdVoos; i++)
            {
                scanf("%d %d",&saida, &chegada);

                vetor[saida - 1]++;
                vetor[chegada - 1]++;
            }

            // Procura o maior elemento
            maior = vetor[0];
            for(int i = 1; i < qtdAeroporto; i++)
            {
                if(vetor[i] > maior)
                    maior = vetor[i];
            }

            printf("Teste %d\n",qtdTestes);
            // Imprime os Aeroporto com a maior quantidade de voos
            for(int i = 0; i < qtdAeroporto; i++)
            {
                if(vetor[i] == maior)
                    printf("%d ",i + 1);
                    
            }
            
            printf("\n\n");
            qtdTestes++;
            free(vetor); // Limpa a memória
            
        }
        
    }
}