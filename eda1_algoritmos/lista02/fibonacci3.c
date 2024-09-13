// #include <stdio.h>

long int vetor[81] = {0,1,1};
int i = 0; // variável de controle

    long int fibonacci(int n)
    {   
        if((n == 1 || n == 2))
        {   
            if(i < 2)
                i++;
            
            return 1;
        }
        else
        {   
            if(i >= 2 ) //  Quando a função alcança o n = 3, vai retornando as posições do vetor e não a função
            {   
                vetor[n] = vetor[n -1] + vetor[n - 2];
                return vetor[n];
            }
            else
                return fibonacci(n-1) + fibonacci(n - 2); // Chama a funçaõ até chegar em 1 
        }
           
    }

// int main()
// {
//     printf("%ld\n",fibonacci(11));
// }