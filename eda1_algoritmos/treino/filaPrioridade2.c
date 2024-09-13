# include <stdio.h>
# include <stdlib.h>
# include <string.h>
//# define swap(a,b) {int t; t = a; a = b; b = t;}

typedef int Item ;
typedef struct elemento Data;

struct elemento
{   
    char nome[20];
    int valor;
};

void swap(Item a, Item b, Item *pq, Item *qp)
{
    qp[pq[a]] = b;
    qp[pq[b]] = a;

    int k = pq[a];
    pq[a] = pq[b];
    pq[b] = k;
}

void  fixUp(Data *data, Item *pq, Item *qp, Item n)
{
    // n = índice na fila de prioridades
    while( n > 1 && data[pq[n/2]].valor < data[pq[n]].valor)
    {
        swap(n/2, n, pq, qp);
        n = n/2;
    }
}

// k = índice do elemento em análise na fila de prioridade
void fixDown(Item k, Item n, Item *pq, Item *qp, Data *data)
{   
    int j;

    //tem filho?
    while(2*k <= n)
    {
        j = 2 * k;

        // pega o maior filho
        if(j < n && data[pq[j]].valor < data[pq[j + 1]].valor)
            j++;
        
        // se o filho for menor que o elemento em análise já pode parar
        if(data[pq[k]].valor > data[pq[j]].valor)
            return;

        swap(k, j, pq, qp);
        k = j; // atualiza o índice do elemento na fila de prioridade
    }
}

void insert(Item novoValor, char *nome, Item *pq,Item *qp, Data *data, Item *n)
{   
    data[*n].valor = novoValor;
    strcpy(data[*n].nome, nome);
    pq[(*n)+1] = *n;
    qp[(*n)] = (*n) + 1;
    (*n)++;
    fixUp(data, pq, qp, *n);

}

// void delete(Item retirar, Item *pq, Item *n)
// {
//     if(retirar == pq[1])
//     {
//        swap(pq[1],pq[*n]);
//         fixDown(1,*n -1, pq);
//         (*n)--;
//     }
// }

void change(Item k, Item novoValor, Data *data, Item *pq, Item *qp, Item n)
{
    // k =  índice que queremos alterar em data
    data[k].valor = novoValor;

    // Verifica se o pai tem valor maior ou menor
    if(data[k].valor  > data[pq[qp[k]/2]].valor)
        fixUp(data,pq,qp,qp[k]); // qp[k] = índice do elemento em data na fila de prioridade
    else
        fixDown(qp[k],n,pq,qp,data);
}

int main()
{   
    Data data[6];
    Item pq[7]; // fila de prioridade
    Item qp[6]; // lista de índices
    Item n = 0; // índice da última posição ocupada da fila de prioridade

    insert(10,"Jose",pq,qp,data,&n);
    insert(9,"Maria",pq,qp,data,&n);
    insert(4,"Julio",pq,qp,data,&n);
    insert(23,"Paulo",pq,qp,data,&n);
    insert(30,"Ana",pq,qp,data,&n);
    insert(17,"Carla",pq,qp,data,&n);
    change(0,50,data,pq,qp,n);
    change(0,0,data,pq,qp,n);

    for(int i = 0; i < 6;i++)
    {   
        printf("%s ", data[i].nome);
        printf("%d ",data[i].valor);
        printf("\n");
    }
    
    for(int i = 1; i<= n;i++)
    {
        printf("%d ",pq[i]);
    }
    printf("\n");
    
    for(int i = 0; i< n;i++)
    {
        printf("%d ",qp[i]);
    }
    printf("\n");

    return 0;
}