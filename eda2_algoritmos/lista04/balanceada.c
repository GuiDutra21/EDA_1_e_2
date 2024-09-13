#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int preenchido;
    int alturaEsq;
    int alturaDir;
    int elemento;
    int pai;

}no;

int main()
{

    int tamanho;
    scanf("%d",&tamanho);
    no *arvore = calloc(tamanho * 2,sizeof(no));
    arvore[0].preenchido = 1;
    arvore[0].elemento = 1;

    int filho;
    int pai;
    for(int i = 0; i < tamanho - 1; i++)
    {
        scanf("%d",&pai);
        pai--;
        filho = (pai * 2) + 1;
        if(arvore[filho].preenchido != 0)
            filho++;
        arvore[filho].preenchido = 1; // Marca como preenchido a posicao que o filho ocupa
        arvore[filho].elemento = i + 2;
        arvore[filho].pai = pai + 1;
    }
    
    int difAlt;
    int maiorAlt;
    while(filho > 0) // Calcular a altura de cada no
    {   
        if(arvore[filho].preenchido != 0) // Se o no não existir passa para o próximo
        {
            difAlt = arvore[filho].alturaEsq - arvore[filho].alturaDir;
            if(difAlt < -1 || difAlt > 1) // Se a diferença entre as alturas for maior do que um
            {
                printf("Nao\n");
                return 0;
            }
            
            maiorAlt = arvore[filho].alturaDir;
            if(arvore[filho].alturaEsq > arvore[filho].alturaDir)
                maiorAlt = arvore[filho].alturaEsq;
            
            int pai = filho - 1;
            while(arvore[filho].pai != arvore[pai].elemento)
                pai--;

            if(filho%2) // Se o índice do filho for impar ele é da subárvore a esquerda
                arvore[pai].alturaEsq = maiorAlt + 1;
            else
                arvore[pai].alturaDir = maiorAlt + 1;
        }
        filho--;
    }
    
    if(arvore[0].alturaEsq - arvore[0].alturaDir < -1 || arvore[0].alturaDir - arvore[0].alturaEsq > 1)
    {
        printf("Nao\n");
        return 0;
    }

    printf("Sim\n");

    return 0;
}