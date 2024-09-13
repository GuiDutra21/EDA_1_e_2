#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void insere_inicio (celula *le, int x)
{   
    celula *novo = malloc(sizeof(celula));
    novo -> dado = x;
    novo -> prox = le -> prox;
    le -> prox = novo;
}

// void imprime(celula *le) {
//     if (le == NULL) {
//         printf("NULL\n");
//     } else {
//         while (le != NULL) {
//             printf("%d -> ", le->dado);
//             le = le->prox;
//         }
//         printf("NULL\n");
//     }
// }

void insere_antes (celula *le, int x, int y)
{
    int inseriu = 0;
    celula *aux = le;

    while(aux -> prox != NULL)
    {
        if(aux -> prox -> dado == y)
        {
          celula *novo = malloc(sizeof(celula));
          novo -> dado = x;
          novo -> prox = aux -> prox;
          aux -> prox = novo;
          inseriu = 1;
          break;
        }
        else 
            aux = aux -> prox;
    }

    if (inseriu == 0)
    {   
        celula *novo = malloc(sizeof(celula));
        aux -> prox = novo;
        novo -> dado = x;
        novo -> prox = NULL;
    }
}

// int main() {
//     // Criando a lista vazia
//     celula *head = malloc(sizeof(celula));
//     head->prox = NULL;

//     // Inserindo elementos
//     insere_inicio(head, 5);
//     insere_inicio(head, 10);
//     insere_inicio(head, 15);
//     insere_inicio(head, 20);

//     // Imprimindo a lista
//     printf("Lista apos insercao no inicio: \n");
//     imprime(head->prox);

//     // Inserindo antes de um elemento existente
//     insere_antes(head, 12, 10);

//     // Imprimindo a lista após a inserção
//     printf("\nLista apos insercao antes de 10: \n");
//     imprime(head->prox);

//     // Inserindo antes de um elemento inexistente
//     insere_antes(head, 12, 5);

//     // Imprimindo a lista após a tentativa de inserção
//     printf("\nLista apos tentativa de insercao antes de 30: \n");
//     imprime(head->prox);

//     return 0;
// }