#include <stdio.h>
#include <stdlib.h>

typedef struct Maca
{
    char tipo;
    int nivel;
    // int esq,dir;
}maca;

typedef struct Nivel
{
    int qtdVerde, qtdVermelho;
}nivel;

int main()
{   
    int n;
    scanf("%d",&n);
    maca arvore[n+1];

    int tipo, esq, dir,qtdNivelAtual = 0;
    scanf("%d %d %d",&tipo ,&esq ,&dir);

    if(esq)
    {
        // arvore[1].esq = esq;
        arvore[esq].nivel = 1;
    }

    if(dir)
    {
        // arvore[1].dir = dir;
        arvore[dir].nivel = 1;
    }
    
    for(int i = 2; i < n+1; i++)
    {
        scanf("%d %d %d",&tipo ,&esq ,&dir);

        // Para o tipo: 1 = verde(g) e 2 = vermelho(r)
        if(tipo == 1)
            arvore[i].tipo = 'g';
        else
            arvore[i].tipo = 'r';

        if(esq)
        {   
            // arvore[i].esq = esq;
            arvore[esq].nivel = arvore[i].nivel + 1;
        }

        if(dir)
        {   
            // arvore[i].dir = dir;
            arvore[dir].nivel = arvore[i].nivel + 1;
        }
    }

    nivel *niveis = calloc(n+1, sizeof(nivel));
    for(int i = 2; i < n+1; i++)
    {   
        if(arvore[i].tipo == 'g')
            niveis[arvore[i].nivel].qtdVerde++;
        else
            niveis[arvore[i].nivel].qtdVermelho++;
    }

    for(int i = 1;i < n; i++)
    {
        if(niveis[i].qtdVerde || niveis[i].qtdVermelho)
            printf("%d %d\n",niveis[i].qtdVerde ,niveis[i].qtdVermelho);
    }
    return 0;
}