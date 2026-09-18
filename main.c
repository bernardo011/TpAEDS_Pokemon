#include <stdio.h>
#include "PokeLista.h"
#include "Pokemon.h"
#include "Treinador.h"

int main(){
    Treinador trainer1;
    Treinador trainer2;
    InicializaTreinadores(&trainer1, &trainer2);
    ImprimeTreinador (&trainer1);
    ImprimeTreinador(&trainer2);
    int cordenadas[2] = {6, 7};
    MovimentaTreinador (&trainer1, cordenadas);
    ImprimeTreinador(&trainer1);
    ImprimeTreinador(&trainer2);
    int id1 = getIdTreinador (&trainer1);
    int id2 = getIdTreinador(&trainer2);
    printf("Id 1: %d\n", id1);
    printf("Id 2: %d\n", id2);
    int c1[2];
    int c2[2];
    
    getCoordenadaTreinador (&trainer1, c1);
    getCoordenadaTreinador (&trainer2, c2);
    printf("(%d, %d)\n", c1[0], c1[1]);
    printf("(%d, %d)\n", c2[0], c2[1]);

    char nome_place[50];
    getNomeTreinador (&trainer1, nome_place);
    printf("%s", nome_place);
    int id;
    id = getIdTreinador (&trainer1);
    printf("Id: %d", id);

    return 0;
}