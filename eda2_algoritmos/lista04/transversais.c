#include<stdio.h>
#include<string.h>

void constroiPos(char *preOrdem, char *emOrdem, char *posOrdem, int qtdNos, int *i)
{
    // Quantidade de Nós na arvore/subarvore 
    if(qtdNos == 0)
        return;
    
    char raiz = preOrdem[0];

    // Procura o índice da raiz da preOrdem no perscusso emOrdem
    // posicaoRaiz = a posição da raiz na string da emOrdem, representa quantos nós tem a esquerda daquele nó,
    // ou seja, tamanho da subarvore a esquerda
    int posicaoRaiz = strchr(emOrdem, raiz) - emOrdem;

    // Vai para a subarvore a esquerda
    constroiPos(preOrdem + 1, emOrdem, posOrdem, posicaoRaiz, i);

    // Vai para a subarvore a direita
    constroiPos(preOrdem + posicaoRaiz + 1, emOrdem + posicaoRaiz + 1, posOrdem, qtdNos - posicaoRaiz - 1, i);

    posOrdem[(*i)++] = raiz;

}

int main()
{
    int qtdTestes;
    int tamArvore;
    char preOrdem[53];
    char emOrdem[53];
    char posOrdem[53];

    scanf("%d",&qtdTestes);
    while (qtdTestes > 0)
    {   
        scanf("%d %s %s",&tamArvore, preOrdem, emOrdem);
        int i = 0;
        
        constroiPos(preOrdem,emOrdem, posOrdem, tamArvore,&i);
        posOrdem[i] = '\0';

        printf("%s\n",posOrdem); 
        qtdTestes--;
    }
    
    return 0;
}