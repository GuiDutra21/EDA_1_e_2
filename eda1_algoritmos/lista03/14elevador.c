#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f, s, g, u, d;

    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    int quantidade = 0;

    // precisa subir 
    if(s < g)
    {
        if(u == 0)
        {
            printf("use the stairs\n");
        }
        else
        {   
            int i = 0;
            while()
            {
                if(g - s % u != 0)
                {
                    quantidade += (g - s) / u;
                    s = g - (g - s % u);
                    printf("%d\n",s);

                    if(d != 0)
                        s = s - d;
                    }
                }
                else if(g - s % u == 0)
                {
                    printf("%d\n",quantidade);
                }
                
            }
        }
    }
    else if (s > g) // precisa descer
    {
        
    }
    else
        printf("0\n");
    
    return 0;
}