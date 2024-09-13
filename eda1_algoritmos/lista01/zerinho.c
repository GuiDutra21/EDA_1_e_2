#include <stdio.h>

int main()
{
    int pessoaA, pessoaB, pessoaC;

    scanf("%d %d %d", &pessoaA, &pessoaB, &pessoaC);
    
    if(pessoaA == pessoaB &&  pessoaA == pessoaC && pessoaB == pessoaA)
    {
        printf("empate\n");
    }
    else if (pessoaA != pessoaB && pessoaA != pessoaC)
    {
        printf("A\n");
    }
    else if (pessoaB != pessoaA && pessoaB != pessoaC)
    {
        printf("B\n");
    }
    else if (pessoaC != pessoaB && pessoaC != pessoaB)
    {
        printf("C\n");
    }
    
    return 0;
}