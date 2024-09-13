#include <stdio.h>
#include <stdlib.h>
typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no *inserir(no *r, int x)
{
   if(r == NULL)
   {  
      no* novo = malloc(sizeof(no));
      novo ->chave = x;
      novo -> esq = NULL;
      novo -> dir = NULL;
      return novo;
   }

   if(r-> chave == x)
      return r;
   

   if(r -> chave < x)
      r -> dir = inserir(r ->dir, x);
   else
      r -> esq = inserir(r->esq,x);

   return r;
}