#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct {
    int divNum;
    int * divisores;

} Divisores;

void incluirDivisor(int num, Divisores * divStruct) {
    // Função que inclui um novo número na estrutura de divisores

    // Passo 1: Criar uma nova lista com o tamanho aumentado
    int * newList = malloc( (divStruct->divNum+1)*sizeof(int) );

    // Passo 2: Copiar os elementos
    for (int i=0; i<divStruct->divNum; i++) { newList[i] = divStruct->divisores[i]; }

    // Passo 3: Incluir o novo elemento
    newList[divStruct->divNum] = num;
    divStruct->divNum++;

    // Passo 4: Fazer os reapontamentos e liberar a memória antiga
    int * delPtr = divStruct->divisores;
    divStruct->divisores = newList;
    free(delPtr);

    return;
}

int numPerfeito (int num, Divisores *divStruct) {

    // Passo 1: O número 1 é divisor de todos os números
    incluirDivisor(1, divStruct);

    // Passo 2: Incluir os divisores adicionais
    for (int i=2; i<num; i++) {
        if (num%i == 0) {
            incluirDivisor(i, divStruct);
        }
    }

    // Passo 3: verificar se o número é perfeito
    int soma=0;
    for(int i=0; i < divStruct->divNum; i++) {
        soma = soma + divStruct->divisores[i];
    }
    if (soma==num) {
        return 0;
    } else {
        return 1;
    }
}

int main()
{
    Divisores div;
    div.divNum = 0;
    div.divisores = NULL;
    int num;

    printf("Insira um número para saber se é perfeito: ");
    scanf("%d", &num);
    int answer = numPerfeito(num, &div);
    if(answer == 0) {
        printf("True\n");
    } else {
        printf("False\n");
    }

}