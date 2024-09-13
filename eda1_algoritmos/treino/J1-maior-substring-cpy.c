#include <stdio.h>
#include <string.h>
#define MaxString 102

int maior_subcadeia(char* string, char* substring, int tamanho_string, int tamanho_substring);

int main(){
    
    char string[MaxString], substring[MaxString];
    scanf("%s", string);
    scanf("%s", substring);
    int  tamanho_maior_subcadeia;

    tamanho_maior_subcadeia = maior_subcadeia(string, substring, strlen(string), strlen(substring));
    printf("%d\n", tamanho_maior_subcadeia);

    return 0;
}

int maior_subcadeia(char* string, char* substring, int tamanho_string, int tamanho_substring){
    
    if(tamanho_string < tamanho_substring){
        return 0;
    }else if (strncmp(string, substring, tamanho_substring) == 0){
        
        char* segunda_verificacao = strstr(string + tamanho_substring, substring);
        
        if (segunda_verificacao == NULL){
            return tamanho_substring;
        }else{
            int tamanho_atual, tamanho_proxima;
            tamanho_atual = segunda_verificacao + tamanho_substring - string + 
            maior_subcadeia(segunda_verificacao + tamanho_substring, substring, 
            tamanho_string - (segunda_verificacao + tamanho_substring - string), tamanho_substring);
            
            tamanho_proxima = maior_subcadeia(segunda_verificacao + tamanho_substring, substring, 
            tamanho_string - (segunda_verificacao + tamanho_substring - string), tamanho_substring);
            
            return (tamanho_atual > tamanho_proxima) ? tamanho_atual : tamanho_proxima;
        }
        
    }else{
        return maior_subcadeia(string + 1, substring, tamanho_string - 1, tamanho_substring);
    }
}
