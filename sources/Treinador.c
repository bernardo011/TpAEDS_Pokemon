#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Treinador.h"

void InicializaTreinadores(Treinador *trainer1, Treinador *trainer2){
    FILE *p;
    p = fopen("teste1.txt", "r");
    if (p == NULL){
        printf("Ponteiro vazio\n");
    } else {
        int index = 0;
        char nomeTreinador[50];
        // Percorre o arquivo de teste enquanto o fscanf retornar 2.
        while (fscanf(p, "%49s", nomeTreinador) == 1){
            if (index == 0){
                strcpy ((*trainer1).nome, nomeTreinador);
                trainer1 -> id_trainer = 1;
                InicializaLista (&((*trainer1).ListaCapturados));
            } else if (index == 1){
                strcpy ((*trainer2).nome, nomeTreinador);
                trainer2 -> id_trainer = 2;
                InicializaLista (&((*trainer2).ListaCapturados));
            }
            index++;
    }
    fclose(p);
}
}
int getIdTreinador (Treinador *trainer){
    return trainer -> id_trainer;
}


void getNomeTreinador (Treinador *trainer, char nome_treinador[]){
    strcpy(nome_treinador, (*trainer).nome);
}