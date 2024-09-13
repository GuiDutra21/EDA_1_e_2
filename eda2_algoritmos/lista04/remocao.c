#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no *remover(no *r, int x)
{
    if(r == NULL)
        return NULL;
    
    if(r -> chave == x)
    {   
        if(r-> esq == NULL)
        {
            no *aux = r -> dir;
            free(r);
            return aux;
        }
        else
        {
            no *paiAux = r, *maiorDosMenores = r -> esq;
            while(maiorDosMenores -> dir != NULL) // Se for NULL a direita não existe ninguém maior que ele
            {
                paiAux = maiorDosMenores;
                maiorDosMenores = maiorDosMenores -> dir;
            }
            
            r->chave = maiorDosMenores ->chave;

            if(paiAux != r)
                paiAux ->dir = maiorDosMenores ->esq;
            else
                paiAux->esq = maiorDosMenores->esq;
            free(maiorDosMenores);

            return r;
        }
    }
    else if(r->chave < x)
        r -> dir = remover(r -> dir,x);
    else
       r -> esq = remover(r->esq,x);
    
    return r;
}