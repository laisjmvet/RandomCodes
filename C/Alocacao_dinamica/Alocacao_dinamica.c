#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct {
    int qtdElementos;
    int *numeros;

} Elementos;

void incluirElementoPrimeiraPosicao(int num, Elementos *vetorNum) {
    //Função que inclui um novo número na estrutura de posição 0 da struct Elementos.


    //Passo 1: Verificar se tem algum elemento na lista, se não tiver, adicionar o primeiro.
    if (vetorNum->numeros == NULL) {
        vetorNum->numeros = malloc(1 * sizeof(int));
        vetorNum->numeros[0] = num;

    // Se a lista não estiver vazia, alocar mais 1 espaço na memória
    }else if (vetorNum->numeros != NULL) {
        vetorNum->numeros = realloc(vetorNum->numeros, (vetorNum->qtdElementos + 1) * sizeof(int));

        //Passo 2: Adicionar os elementos na posição seguinte
        for (int i = vetorNum->qtdElementos; i > 0; i--) {
            vetorNum->numeros[i] = vetorNum->numeros[i-1];
        }
        //Passo 3: Adicionar o novo elemento na posição 0
        vetorNum->numeros[0] = num;
    }

    //Passo 4: Adicionar um elemento na quantidade de elementos e liberar memória
    vetorNum->qtdElementos++;
    return;
}

void incluirElementoUltimaPosicao(int num, Elementos *vetorNum) {
    //Função que inclui um novo elemento na última posição da struct Elementos.


    //Passo 1: Verificar se tem algum elemento na lista, se não tiver, adicionar o primeiro.
    if (vetorNum->numeros == NULL) {
        vetorNum->numeros = malloc(1 * sizeof(int));
        vetorNum->numeros[0] = num;

    // Se a lista não estiver vazia, criar uma nova lista com +1 de tamanho
    }else if (vetorNum->numeros != NULL) {
        int *newList = malloc((vetorNum->qtdElementos + 1) * sizeof(int));

        //Passo 2: Copiar os elementos
        for (int i = 0; i < vetorNum->qtdElementos; i++) {
            newList[i] = vetorNum->numeros[i];

        }
        //Passo 3: Adicionar o novo elemento na ultima posição e liberar memória antiga

        int *delPtr = vetorNum->numeros;
        newList[vetorNum->qtdElementos] = num;
        vetorNum->numeros = newList;
        free(delPtr);
    }

    //Adicionar um elemento na quantidade de elementos
    vetorNum->qtdElementos++;
}

void excluirElementoUltimaPosicao(Elementos *vetorNum) {
    //Função que exclui o último elemento da struct Elementos.


    //Passo 1: Verificar se tem algum elemento na lista, se não tiver, imprimir que não existe elemento.
    if (vetorNum->numeros == NULL) {
        printf("Não existem elementos na lista.\n");

    // Se a lista não estiver vazia, criar uma nova lista com -1 de tamanho
    }else if (vetorNum->numeros != NULL) {
        int *newList = malloc((vetorNum->qtdElementos - 1) * sizeof(int));

        //Passo 2: Copiar os elementos, com exceção do último
        for (int i = 0; i < vetorNum->qtdElementos - 1; i++) {
            newList[i] = vetorNum->numeros[i];

        }

        //Passo 3: Liberar memória antiga e retirar um elemento da quantidade de elementos
        int *delPtr = vetorNum->numeros;
        vetorNum->numeros = newList;
        free(delPtr);
        vetorNum->qtdElementos--;
    }

}

void excluirElementoPrimeiraPosicao(Elementos *vetorNum) {
    //Função que exclui o primeiro elemento da struct Elementos.


    //Passo 1: Verificar se tem algum elemento na lista, se não tiver, imprimir que não existe elemento.
    if (vetorNum->numeros == NULL) {
        printf("Não existem elementos na lista.\n");

    // Se a lista não estiver vazia, criar uma nova lista com -1 de tamanho
    }else if (vetorNum->numeros != NULL) {
        int *newList = malloc((vetorNum->qtdElementos - 1) * sizeof(int));

        //Passo 2: Copiar os elementos, com exceção do primeiro
        for (int i = 0; i < vetorNum->qtdElementos - 1; i++) {
            newList[i] = vetorNum->numeros[i + 1];

        }

        //Passo 3: Liberar memória antiga e retirar um elemento da quantidade de elementos
        int *delPtr = vetorNum->numeros;
        vetorNum->numeros = newList;
        free(delPtr);
        vetorNum->qtdElementos--;
    }

}

int main()
{
    Elementos div;
    div.qtdElementos = 0;
    div.numeros = NULL;
    int num;
    int comando;

    printf("\n(1) Para adicionar um número no início da lista\n(2) Para adicionar um número no final da lista\n(3) Para excluir o último número da lista\n(4) Para excluir o primeiro número da lista\n(0) Para encerrar\n\nDigite a opção: ");
    scanf("%d", &comando);
    setbuf(stdin, NULL);

    while(comando != 0) {

        setbuf(stdin, NULL);

            switch(comando) {

                case 1:
                    printf("Digite o número a ser adicionado no início da lista: ");
                    scanf("%d", &num);
                    incluirElementoPrimeiraPosicao(num, &div);
                    for (int i = 0; i < (div.qtdElementos * sizeof(int)) / sizeof(int); i++) {
                        printf("%d ", div.numeros[i]);
                    }
                    printf("\nDigite o pŕoximo comando: ");
                    scanf("%d", &comando);
                    break;
                case 2:
                    printf("Digite o número a ser adicionado no final da lista: ");
                    scanf("%d", &num);
                    incluirElementoUltimaPosicao(num, &div);
                    for (int i = 0; i < (div.qtdElementos * sizeof(int)) / sizeof(int); i++) {
                        printf("%d ", div.numeros[i]);
                    }
                    printf("\nDigite o pŕoximo comando: ");
                    scanf("%d", &comando);
                    break;
                case 3:
                    printf("Último número da lista excluido. \n");
                    excluirElementoUltimaPosicao(&div);
                    for (int i = 0; i < (div.qtdElementos * sizeof(int)) / sizeof(int); i++) {
                        printf("%d ", div.numeros[i]);
                    }
                    printf("\nDigite o pŕoximo comando: ");
                    scanf("%d", &comando);
                    break;
                case 4:
                    printf("Primeiro número da lista excluido. \n");
                    excluirElementoPrimeiraPosicao(&div);
                    for (int i = 0; i < (div.qtdElementos * sizeof(int)) / sizeof(int); i++) {
                        printf("%d ", div.numeros[i]);
                    }
                    printf("\nDigite o pŕoximo comando: ");
                    scanf("%d", &comando);
                    break;
                case 0:
                    comando = 0;
                    break;
                default:
                    printf("OPÇÃO INVÁLIDA\nDigite uma opção válida: ");
                    scanf("%d", &comando);
                    break;

            }
    }

    printf("\nPrograma encerrado.\n");
    for (int i = 0; i < (div.qtdElementos * sizeof(int)) / sizeof(int); i++) {
                        printf("%d ", div.numeros[i]);
    }
    printf("\n\n");

}
