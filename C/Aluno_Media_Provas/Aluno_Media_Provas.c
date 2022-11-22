#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define qtdAlunos 2


typedef struct {

    char nome[40];
    float p1, p2, p3, pMedia;

} Aluno;

void mediaAluno(Aluno *aluno, int n);


int main(){
    Aluno aluno[qtdAlunos];
    for(int i=0; i<qtdAlunos; i++) {
        setbuf(stdin, NULL);
        printf("Nome[%d]: ", i+1);
        gets(aluno[i].nome);
        printf("Nota prova 1: ");
        scanf("%f", &aluno[i].p1);
        printf("Nota prova 2: ");
        scanf("%f", &aluno[i].p2);
        printf("Nota prova 3: ");
        scanf("%f", &aluno[i].p3);
    }

    mediaAluno(aluno, qtdAlunos);
    printf("Nome Aluno 1: %s\nMédia Aluno 1: %.1f\nNome Aluno 2: %s\nMédia Aluno 2: %.1f\n", aluno[0].pMedia, aluno[0].nome, aluno[1].nome, aluno[1].pMedia);

}

void mediaAluno(Aluno *aluno, int n) {

    for(int i=0; i<qtdAlunos; i++) {
        float media=(aluno[i].p1+aluno[i].p2+aluno[i].p3)/3;
        aluno[i].pMedia=media;
    }

}