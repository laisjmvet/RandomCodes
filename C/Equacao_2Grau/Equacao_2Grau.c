#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int qtde;
    float r1, r2;
}RaizesEquacao2Grau;

void equacao2grau (float a, float b, float c, RaizesEquacao2Grau *raizes) {
    float delta=pow(b,2)-4*a*c, raiz1=(-b+sqrt(delta))/(2*a), raiz2=(-b-sqrt(delta))/(2*a);

    if (delta<0) {
        raizes->qtde=0;
        raizes->r1=0;
        raizes->r2=0;
    }else if (delta==0) {
        if (raiz1==0) {
            raizes->qtde=1;
            raizes->r1=raiz2;
            raizes->r2=0;
        }else {
            raizes->qtde=1;
            raizes->r1=raiz1;
            raizes->r2=0;
        }
    }else if (delta>0) {
        raizes->qtde=2;
        raizes->r1=raiz1;
        raizes->r2=raiz2;
    }
}

int main()
{
    float a, b, c;
    RaizesEquacao2Grau raizes;

    printf("Insira o \"a\" da equação: \n");
    scanf("%f", &a);
    printf("Insira o \"b\" da equação: \n");
    scanf("%f", &b);
    printf("Insira o \"c\" da equação: \n");
    scanf("%f", &c);

    equacao2grau(a, b, c, &raizes);

    printf("A quantidade de raizes é: %d\nO valor da raiz[1] é: %.1f\nO valor da raiz[2] é: %.1f\n", raizes.qtde, raizes.r1, raizes.r2);

}
