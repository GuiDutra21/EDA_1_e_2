#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define show(n) printf("%d\n", n);
#define entrou printf("ENTROU\n");
#define swap(c1, c2) {int c = c1; c1 = c2; c2 = c;}
#define MAIN main

void move(char * str, char * strF,int i,int x)
{
    if (*str == 'x' && i <= x) {
        strF[x] = *str;
        move(++str, strF, i, --x);
    }
    else
    if (i <= x) {
        strF[i] = *str;
        move(++str, strF, ++i, x);
    }
}

int MAIN(void)
{
    char str[1000];
    char resposta[1000];
    int len;

    scanf("%s", str);

    len = strlen(str);
    move(str, resposta, 0, len-1);
    resposta[len] = '\0';

    printf("%s\n", resposta);
    return 0;
}