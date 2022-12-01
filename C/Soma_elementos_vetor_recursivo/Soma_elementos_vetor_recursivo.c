#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Crie uma função recursiva que retorne a soma dos elementos de um vetor de inteiros.

int somaElementos (int qtdElementos, int *vetor) {
    int soma = 0;

    if (qtdElementos == 0) {
        return soma;
    }else {
        soma = vetor[qtdElementos - 1] + soma;
        return somaElementos(qtdElementos - 1, vetor) + soma;
    }
}

int main()
{
  int vetor[] = {0, 2, 3, 10, 32};
  int tam = sizeof(vetor)/sizeof(int);
  int soma = somaElementos(tam, vetor);
  printf("Soma: %d\n", soma);

}