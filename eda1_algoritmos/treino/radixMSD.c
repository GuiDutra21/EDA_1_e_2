# include <string.h>
# include <stdio.h>
# include <stdlib.h>

typedef char Item;
# define maxstring 101
# define bitsbyte 8
# define R (1 << bitsbyte)

int charAt(char s[], int d)
{
    if(d < strlen(s))
        return s[d]; //d-é simo caractere
    else 
        return -1;  // count [-1 + 1] = count [0]
                    // count [0] = qtde . de palavras menores que d
}

// Strings : ordena para o d-é simo caractere
void radixMSD (char a [][maxstring], int l, int r, int d)
{
    if(r <= l) return;

    char aux[r - l +1][maxstring];

    int count[R+1];
    memset(count,   0, sizeof(int)*(R+1));

    // frequencia dos d-é simos caracteres
    for ( int i = l ; i <= r ; i ++)
        count[ charAt(a[i], d) + 1]++;
    
    // tabela de índices : calculando as posições
    for (int i = 1; i <= R; i++)
        count[i] += count[i - 1];
    
    // redistribui as chaves : ordena em aux
    for(int i = l; i <= r; i++)
        strcpy(aux[count[charAt(a[i],d)]++],a[i]);
    
    // copia para o original
    for( int i = l; i <= r; i++)
     strcpy(a[i],aux[i - 1]);

    // ordenar por subconjunto : count [0] = já ordenadas
    for(int i = 1; i <= R; i++)
    // count [i-1] posi ção da primeira chave com o caractere i
    // count [i]-1 posi ção da ú ltima chave com o caractere i
    radixMSD(a, l + count[i - 1], l + count[i] - 1, d + 1);

}

int main()
{
    int n,i;
    scanf("%d",&n);

    char palavras[n][101];
    for(i = 0; i < n; i++)
    {
        scanf("%s",palavras[i]);
    }

    radixMSD(palavras, 0 , n - 1, 1);

    printf("\n");

    for(int i = 0; i < n; i++)
    {
        printf("%s\n",palavras[i]);
    }
    return 0;
}
