# include <stdio.h>
# include <stdlib.h>
# define swap(a,b) {int t; t = a; a = b; b = t;}

int main()
{
    int i = 100 / 101 ;// pega sempre a parte inteira
    printf("%d",i);
    return 0;
}