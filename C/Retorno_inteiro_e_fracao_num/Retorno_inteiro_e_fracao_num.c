#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Escreva uma função que, dado um número real passado como parâmetro, retorne a parte inteira e a parte fracionária desse número por referência.

typedef struct {
    int inteiro;
    double fracao;
}InteiroEFracao;

void inteiroEFracao(double a, InteiroEFracao *b) {

    int inteiro=a;
    double fracao=a-inteiro;
    b->inteiro=inteiro;
    b->fracao=fracao;
}

int main(){

    InteiroEFracao numeroReal;

    inteiroEFracao(sqrt(2), &numeroReal);
    printf("A parte inteira é: %d\n A parte de fração é: %f\n", numeroReal.inteiro, numeroReal.fracao);

}