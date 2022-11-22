#include <stdio.h>
#include <stdlib.h>



float fahrenheitToCelsius(float a) {

    float celsius=(a-32.0)*(5.0/9.0);
    return celsius;
}

int main(){

float temp;

printf("Digite a temperatura em Fahrenheit: ");
scanf("%f", &temp);
float celsius = fahrenheitToCelsius(temp);
printf("A temperatura em Celsius é: %.1f\n", celsius);

}