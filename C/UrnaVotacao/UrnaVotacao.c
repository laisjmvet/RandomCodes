#include <stdio.h>
#include <stdlib.h>


int main()
{
    int antonio=0, jose=0, maria=0, branco=0, nulo=0, candidato=1;
    int RetScanf;
    while (candidato!=0) {
        
        printf("Digite o número do candidato:\n[1]Antonio\n[2]José\n[3]Maria\n[4]Branco\n[*]Nulo\n\nDigite [0] para parar a votação\n\n");
        RetScanf = scanf("%d", &candidato);
        setbuf(stdin, NULL);
        
        if (RetScanf == 0) {candidato = -1;};
        

        switch (candidato) {
            case 1:
                printf("Voto 1 computado!\n\n");
                antonio++;
                break;
            case 2:
                printf("Voto 2 computado!\n\n");
                jose++;
                break;
            case 3:
                printf("Voto 3 computado!\n\n");
                maria++;
                break;
            case 4:
                printf("Voto 4 computado!\n\n");
                branco++;
                break;
            case 0:
                printf("Votação encerrada!\n\n");
                break;
                candidato = 0;
            default:
                printf("Voto NULO computado!\n\n");
                nulo++;
                break;    
        }
    }
    
    int total_votos=antonio+jose+maria+branco+nulo;
    char candidato_antonio[]="Antonio";
    char candidato_jose[]="José";
    char candidato_maria[]="Maria";
    int votos[3]={antonio, jose, maria};

    printf("Total de eleitores: %d\n", total_votos);

    if (votos[0]>votos[1]&&votos[0]>votos[2]){
        printf("Vencedor: %s\n\n", candidato_antonio);
    } else if (votos[1]>votos[0]&&votos[1]>votos[2]) {
        printf("Vencedor: %s\n\n", candidato_jose);
    }else if (votos[2]>votos[0]&&votos[2]>votos[1]) {
        printf("Vencedor: %s\n\n", candidato_maria);
    }else {
        printf("VOTAÇÃO EM SEGUNDO TURNO\n\n");
    }   
    
    printf("Total dos votos de cada candidato:\nAntonio: %d\nJosé: %d\nMaria: %d\nBranco: %d\nNulo: %d\n", antonio, jose, maria, branco, nulo);    
 
    

}
