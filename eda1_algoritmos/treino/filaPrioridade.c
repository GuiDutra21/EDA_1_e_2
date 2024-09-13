# include <stdio.h>
# include <stdlib.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}

typedef int Item ;

void  fixUp(Item *pq, Item n)
{   
    // n é o índice no vetor
    while( n > 1 && pq[n/2] < pq[n])
    {
        swap(pq[n/2],pq[n])
        n = n/2;
    }
}

// k = índice do elemento em análise
void fixDown(Item k, Item n, Item *pq)
{   
    int j;

    //tem filho?
    while(2*k <= n)
    {
        j = 2 * k; // receb o índice do filho

        // pega o maior filho
        if(j < n && pq[j] < pq[j + 1])
            j++;
        
        // se o maior filho for menor que o pai ja pode parar
        if(pq[k] > pq[j])
            return;

        swap(pq[k], pq[j]);
        k = j; // atualiza o índice do elemento
    }
}

void insert(Item valor, Item *pq, Item *n)
{
    (*n)++; // Sempre insere na úlltima posição livre
    pq[*n] = valor;
    fixUp(pq,*n);
}

void delete(Item retirar, Item *pq, Item *n)
{
    if(retirar == pq[1])
    {
        swap(pq[1],pq[*n]);
        fixDown(1,*n -1, pq);
        (*n)--;
    }
}

void change(Item k, Item valor, Item *pq,Item n)
{
    // k =  índice que queremos alterar
    pq[k] = valor;

    // Altera a fila caso necessário
    if(pq[k/2] < valor)
        fixUp(pq,k);
    else
        fixDown(k,n,pq);
}

int main()
{   Item n = 0;
    Item pq[11];
    insert(8,pq,&n);
    insert(9,pq,&n);
    insert(7,pq,&n);
    insert(6,pq,&n);
    insert(3,pq,&n);
    insert(5,pq,&n);
    insert(3,pq,&n);
    insert(4,pq,&n);
    insert(1,pq,&n);
    insert(10,pq,&n);
    delete(10,pq,&n);
    change(6,11,pq,n);
    change(3,2,pq,n);

    for(int i = 1; i<= n;i++)
    {
        printf("%d ",pq[i]);
    }
    printf("\n");

    return 0;
}