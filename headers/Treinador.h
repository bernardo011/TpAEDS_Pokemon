#ifndef TREINADOR_H
#define TREINADOR_H
// Inclusão do arquivo PokeLista.h foi necessária pois a struct Treinador armazena uma variável do tipo Lista.
#include "PokeLista.h"

// Declaração prévia da struct Pokémon pois um ponteiro para esse tipo é criado em uma das funções abaixo.
typedef struct pokemon Pokemon;

// TAD Treinador que armazena as informações de um treinador pokémon e uma lista de pokémons capturados.
typedef struct treinador {
    int id_trainer;
    char nome[50];
    PokeLista TimeTreinador;
} Treinador;

void InicializaTreinadores(Treinador *trainer1, Treinador *trainer2);
int getIdTreinador(Treinador *trainer);
void getNomeTreinador (Treinador *trainer, char nome_treinador[]);
#endif