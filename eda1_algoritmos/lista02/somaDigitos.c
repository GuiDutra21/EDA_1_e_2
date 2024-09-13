#include <stdio.h>
// função recursiva que soma os digitos de um numero
// 1234 = 1+2+3+4 = 10
int soma (long int numero, int acumulador)
{
    if (numero == 0)
    {
        return acumulador;
    }
    else
    {   
        acumulador += numero % 10;
        numero /= 10;
        return soma(numero,acumulador);
    }
}

int main()
{
    long int numero,resultado;
    scanf("%ld",&numero);
    resultado = soma(numero,0);
    printf("%ld\n",resultado);

    return 0;
}