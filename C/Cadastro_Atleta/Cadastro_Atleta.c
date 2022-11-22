#include <stdio.h>
#include <stdlib.h>
#define pessoas 5

typedef struct {
    char nome[40];
    char esporte[20];
    int idade;
    float altura;
} Atleta;

int maiorAltura(Atleta *atl) {
    int maior=0;
    for(int i=1; i<pessoas; i++){

        if (atl[i].altura>atl[maior].altura) {
           maior=i;
        }else {
            maior=maior;
        }
    }
    return maior;
}

int menorIdade (Atleta *atl) {
    int menor=0;
    for(int i=1; i<pessoas; i++){

        if (atl[i].idade<atl[menor].idade) {
           menor=i;
        }else {
            menor=menor;
        }
    }
    return menor;
}

int main(){

    Atleta atl[pessoas];

    for(int i=0; i<pessoas; i++) {
        setbuf(stdin, NULL);
        printf("Nome[%d]: \n", i);
        gets(atl[i].nome);
        printf("Esporte[%d]: \n", i);
        gets(atl[i].esporte);
        printf("Idade[%d]: \n", i);
        scanf("%d", &atl[i].idade);
        printf("Altura[%d](m): \n", i);
        scanf("%f", &atl[i].altura);

    }
    int m=menorIdade(atl), n=maiorAltura(atl);
    printf("Dados do atleta com menor idade:\n\nNome: %s\nEsporte: %s\nIdade: %d\nAltura(m): %.2f\n\n", atl[m].nome, atl[m].esporte, atl[m].idade, atl[m].altura);
    printf("Dados do atleta com maior altura:\n\nNome: %s\nEsporte: %s\nIdade: %d\nAltura(m): %.2f\n\n", atl[n].nome, atl[n].esporte, atl[n].idade, atl[n].altura);
}