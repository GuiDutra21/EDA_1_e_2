#include <stdio.h>
typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;


no *maximo (no *r)
{
    if(r->dir != NULL)
    {
        maximo(r -> dir);
    }
    else
        return r;
}
