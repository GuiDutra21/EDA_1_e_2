#include <stdio.h>

int main()
{
    int tamanhoEstrada, distanciaPedagios, custoPorKm, precoPedagio, qtdPedagios, resultado;

    // leitura dos dados
    scanf("%d %d",&tamanhoEstrada, &distanciaPedagios);
    scanf("%d %d",&custoPorKm, &precoPedagio);
    
    // Calcula a quantidade de pedágios
    qtdPedagios = tamanhoEstrada/distanciaPedagios;

    // Calcula o resultado somando o valor total pago pelos pedágios com o valor total pelos quilômetros rodados
    resultado = (qtdPedagios * precoPedagio) + (tamanhoEstrada * custoPorKm);

    printf("%d\n",resultado);
}