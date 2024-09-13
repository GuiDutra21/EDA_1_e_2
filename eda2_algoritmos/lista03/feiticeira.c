#include <stdio.h>
#include <stdlib.h> 

typedef struct no
{
    long id;
    long quantidade;
    struct no *prox;
}no;

typedef struct tabela
{   
    no *colisoes;
}tabela;

void insere(no **raiz, long id, long quantidade)
{
    
    if(*raiz == NULL)
    {   
        no *novo = malloc(sizeof(no));
        novo -> id = id;
        novo -> prox = NULL;
        novo -> quantidade = quantidade;
        *raiz = novo;
    }
    else
    {   
        no *temp = *raiz;
        if(temp -> id == id)
        {
            temp -> quantidade += quantidade;
            return;
        }

        // loop para verificar se não existe um elemento com o mesmo id
        while(temp -> prox != NULL)
        {
            if(temp -> id == id)
            {
                temp -> quantidade += quantidade;
                return;
            }
            temp = temp -> prox;
        }
        no *novo = malloc(sizeof(no));
        novo -> id = id;
        novo -> prox = NULL;
        novo -> quantidade = quantidade;
        temp -> prox = novo;
    }
}

long hash(int valor, int tamanho)
{
    return valor % tamanho;
}

void subtrai(tabela *tabela, long id, long quantidade, long tamanhoVet, long *soma)
{   
    no *temp = tabela[hash(id,tamanhoVet)].colisoes; 
    while(temp != NULL)
    {
        if(temp -> id == id)
        {   
            // Se a quantidade a ser retirada for maior que a existente para aquele ID
            if (quantidade * (-1) >= temp -> quantidade) 
            {   
                *soma -= temp ->quantidade;
                temp -> quantidade = 0;
            }
            else
            {   
                *soma += quantidade;
                temp -> quantidade += quantidade;
            }
            return ;
        }
        temp = temp -> prox;
    }
}


int main()
{
    int qtd,id;
    long quantidade;
    long soma = 0;
    scanf("%d",&qtd);
    long novoQtd = qtd*20;
    tabela tabela[novoQtd];
    
    int i;
    for(i = 0; i < novoQtd; i++)
    {
        tabela[i].colisoes = NULL;
    }

    for (i = 0; i < qtd; i++)
    {
        scanf("%d %ld",&id,&quantidade);
        id += 536870912;
        if(quantidade > 0)
        {   
            soma += quantidade;
            insere(&tabela[hash(id,novoQtd)].colisoes, id, quantidade);
        }
        else
            subtrai(tabela, id, quantidade,novoQtd,&soma);
    }

    printf("%ld\n",soma);
    return 0;
}

/////////////////////////////////////////////////////////////////

// #include <stdio.h>
// #include <stdlib.h> 
// // #define tamanho 104729

// typedef struct tabela
// {   
//     int dado;
//     int quantidade;
// }tabela;


// int hash(int valor,int tamanho)
// {
//     return valor % tamanho;
// }

// void insere(tabela *tabela, int dado, int quantidade, long *soma, int tamanhoVet)
// {
//     int indice = hash(dado,tamanhoVet);

//     // Procura a primeira posição livre ou a posição do dado
//     while(tabela[indice].quantidade != 0 && tabela[indice].dado != dado)
//     {
//         indice = (indice + 1)%tamanhoVet;
//     }

//     // Se for igual apenas soma a quantidade
//     if(tabela[indice].dado == dado)
//         tabela[indice].quantidade += quantidade;
//     else
//     {
//         tabela[indice].dado = dado;
//         tabela[indice].quantidade = quantidade;
//     }
//     *soma += quantidade;
// }

// void retira(tabela *tabela, int dado, int quantidade, long *soma, int tamanhoVet)
// {
//     int indice = hash(dado,tamanhoVet);

//     int i = 0;
//     while(tabela[indice].dado != dado)
//     {
//         indice = (indice + 1)%tamanhoVet;
//         i++;
//         if(i == tamanhoVet - 1) // Se não encontrar o dado para a função
//             return;
//     }

//     // Se a quantidade a ser subtraida for maior que a já existente
//     if(quantidade * (-1) > tabela[indice].quantidade)
//     {
//         tabela[indice].quantidade = 0;
//         *soma -= tabela[indice].quantidade;
//     }
//     else
//     {
//         tabela[indice].quantidade += quantidade;
//         *soma += quantidade;
//     }
// }


// int main()
// {
//     int qtd, quantidade, dado;
//     scanf("%d",&qtd);
//     tabela tabela[qtd];
    
//     long soma = 0;
//     int i;

//     // Zera as posicoes
//     for(i = 0; i < qtd; i++)
//     {
//         tabela[i].quantidade = 0;
//     }

//     for (i = 0; i < qtd; i++)
//     {
//         scanf("%d %d",&dado,&quantidade);
//         dado += 536870912; // Faz o dado ser positivo para calcular corretamente a hash
//         if(quantidade > 0)
//         {
//             insere(tabela,dado, quantidade,&soma, qtd);
//         }
//         else
//         {
//             retira(tabela,dado,quantidade,&soma, qtd);
//         }
//     }

//     printf("%ld\n",soma);

//     return 0;
// }
