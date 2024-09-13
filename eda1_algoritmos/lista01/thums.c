#include <stdio.h>

int main()
{
    int linhas;
    scanf("%d",&linhas);

    for(int i = 1; i <= linhas; i++)
    {
        if(i % 2 != 0)
            printf("THUMS THUMS THUMS\n");
        else
            printf("THUMS THUMS THUMS THUMS THUMS THUMS\n");
    }
    
    return 0;
}