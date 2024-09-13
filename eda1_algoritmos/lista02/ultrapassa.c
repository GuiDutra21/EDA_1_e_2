#include <stdio.h>

void somar(int *vetor, int limite, int indice, int tamanhoVetor, int soma, int resposta)
{   
    if(indice != tamanhoVetor) // Qunado chegar no fim da função para a chamada recursiva
    {
            if(soma + vetor[indice] > limite) // Se ultrapassar armazena o valor para impirmir depois e zera a soma
            {
                resposta = vetor[indice];
                soma = 0;
            }
            else
            {   
                soma += vetor[indice]; // Se não ultrapassar apenas faz a soma normal
            }

        somar(vetor, limite, indice + 1, tamanhoVetor, soma, 0);

        if(resposta != 0)
            printf("%d\n",resposta);
    }
}

int main()
{
    int vetor[10000];
    int i = 0;
    int numeros;
    int limite;

    while(scanf("%d",&numeros) && numeros != 0)
    {
        vetor[i] = numeros;
        i++;
    } // lê os valores, armazena no vetor e quando for zero para

    scanf("%d",&limite);

    somar(vetor, limite, 0, i, 0, 0);

    return 0;
}