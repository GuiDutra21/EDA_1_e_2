#include <stdio.h>

int main()
{
    float alcool, gasolina, kmAlcool, kmGasolina;

    scanf("%f %f %f %f", &alcool, &gasolina, &kmAlcool, &kmGasolina);

    // Queremos achar o preço por Km, logo basta dividir o preço por km e ver qual é o menor
    
    if(alcool/kmAlcool < gasolina/kmGasolina)
    {
        printf("A\n");
    }
    else
    {
        printf("G\n");
    }
    return 0;
}