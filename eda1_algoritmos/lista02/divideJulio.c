    #include <stdio.h>
    #include <stdlib.h>
    typedef struct celula {
    int dado;
    struct celula *prox;
    } celula;

    void divide_lista(celula *l, celula *l1, celula *l2)
    {
        if(l -> prox != NULL)
        {
            celula temp = *(l -> prox);
            // printf("%p\n",l -> prox -> prox);
            // printf("%p\n",temp.prox);
            if(temp.dado % 2 == 0)
            {   
                celula aux = NULL; 
                printf("%p\n",temp.prox -> prox);
                printf("%p\n",&aux);
                temp.prox = &aux;
                temp.prox = NULL;
                l2 -> prox = &temp;
                divide_lista(l -> prox, l1, l2 -> prox); 
            }
            else
            {   
                celula aux = *(temp.prox); 
                temp.prox = &aux;
                temp.prox = NULL;
                l1 -> prox = &temp;
                divide_lista(l -> prox, l1 -> prox, l2);
            }
        }
        else
        {
            // l2 -> prox = NULL;
            // l1 -> prox = NULL;
        }
    }

    void print(celula *aux) {
        if (aux -> prox != NULL) 
        {
            printf("%d\t", aux-> prox -> dado);
            print(aux->prox);
        }
        else
            printf("\n");
    }

    int main()
    {

        celula *l = malloc(sizeof(celula));
        l -> dado = 0;
        l -> prox = malloc(sizeof(celula));
        l -> prox -> dado = 15;
        l -> prox -> prox = malloc(sizeof(celula));
        l -> prox -> prox ->  dado = 10;
        l -> prox -> prox -> prox = malloc(sizeof(celula));
        l -> prox -> prox -> prox ->  dado = 11;
        l -> prox -> prox-> prox -> prox = malloc(sizeof(celula));
        l -> prox -> prox -> prox -> prox ->  dado = 8;
        l -> prox -> prox -> prox -> prox -> prox = NULL;

        celula *aux = l;
        celula *l1 = malloc(sizeof(celula));
        l1 -> prox = NULL;
        celula *l2 = malloc(sizeof(celula)); 
        l2 -> prox = NULL;
        print(aux);
        divide_lista(l,l1,l2);
        // print(l1);
        // print(l2);

        printf("%d\n",l1 -> prox -> dado);
        printf("%d\n",l1 -> prox -> prox -> dado);
        printf("%d\n",l2 -> prox -> dado);
        printf("%d\n",l2 -> prox -> prox -> dado);
    
    return 0;
    }