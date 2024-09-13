#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int somar(char num[1001], int resultado, int i)
{
    if(num[i] == '\0') return resultado;
    else
    {
        resultado += ((int) num[i]) - 48;
        return somar(num, resultado, ++i);
    }

}

int degree(int num, int d)
{   
    printf("degrau %d\n",d);
    printf("soma antes: %d\n",num);
    int temp = ((num/1000) + (num%1000)/100 + ((num%1000)%100)/10 + ((num%1000)%100)%10);

    printf("soma depois: %d\n",temp);
    if( temp % 9 == 0 && num >9)
    {
        return degree(temp, ++d);
    }
    else
    {
        return d;
    }
}

int main()
{
    char num[1001];
    while(scanf("%s", num))
    {
        if(num[0] == '0' && strlen(num) == 1) return 0;
        else 
        {
            int resultado = somar(num,0,0);
            if(resultado % 9 == 0)
            {
                printf("%s is a multiple of 9 and has 9-degree %d.\n",num,degree(resultado,1));
            }
            else
            {
                printf("%s is not a multiple of 9.\n",num);
            }
        }
    }

    return 0;
}