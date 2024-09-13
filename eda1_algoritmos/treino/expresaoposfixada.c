#include <stdio.h>
#include <stdlib.h>
typedef int Item;

typedef struct registro node;
struct registro
{
    Item info;
    node *prox;
};

typedef struct cabeca head;
struct cabeca
{
    int num_itens;
    node * prox;
    node *ultimo;
};

head *criar_pilha()
{
    head *le = malloc(sizeof(head));
    le -> num_itens = 0;
    le -> prox = NULL;
    le -> ultimo = NULL;
    return le;
}

node *criar_no(Item x)
{
    node *no = malloc(sizeof(node));
    no -> prox = NULL;
    no -> info = x;
    return no;
}

int vazia(head *p)
{
    return (p -> prox == NULL);
}

Item espia(head *p)
{
    return (p -> prox -> info);
}

void empilha(head *lista, Item x)
{
    node *novo = criar_no(x);
    if(novo)
    {
        if(vazia(lista)) lista -> ultimo = novo;

        novo -> prox = lista -> prox;
        lista -> prox = novo;
        lista -> num_itens++;
    }
}

Item desempilha(head *lista)
{
    node *topo = lista -> prox;
    lista -> prox = topo -> prox;

    if(topo == lista -> ultimo) lista -> ultimo = NULL;

    Item x = topo -> info;
    free(topo);
    return x;

}

int main (int argc, char *argv[])
{
    char *a = "5 9 8 + 4 6 * * 7 + *";

    head *pilha = criar_pilha();

    for (int i = 0; a[i] != '\0'; i++)
    {
        // operacao do operador sobre os ultimos operandos lidos
        if(a[i] == '+')
            empilha(pilha,desempilha(pilha) + desempilha(pilha));
        if (a[i] == '*')
            empilha(pilha, desempilha(pilha) * desempilha(pilha));
        
        //colocar zero a esquerda
        if((a[i] >= '0') && (a[i] <= '9')) empilha (pilha,0);

        // calcular o equivalente numerico de uma sequencia de caracters
        while((a[i] >= '0') && (a[i]<= '9'))
            empilha(pilha, 10 * desempilha(pilha) + (a[i++] - '0'));
            // calcual o decimal, centena  ... + valor valor numerico
    }

    printf("%d\n",desempilha(pilha));
}
