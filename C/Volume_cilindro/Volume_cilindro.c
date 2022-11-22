#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14



float volumeCilindro(float altura, float raio) {

    float volume=pi*pow(raio, 2)*altura ;
    return volume;
}

int main(){

float raio, altura;

printf("Digite o raio do cilindro em cm: ");
scanf("%f", &raio);
printf("Digite a altura do cilindro em cm: ");
scanf("%f", &altura);
float volume=volumeCilindro(altura, raio);
printf("O volume do cilindro é: %.1f cm³\n", volume);

}