#ifndef TREINADOR_H
#define TREINADOR_H
#include "PokeLista.h"

typedef struct pokemon Pokemon;

typedef struct treinador {
    int id_trainer;
    char nome[50];
    int coordenada_treinador[2];
    Lista ListaCapturados;
    int QtdPokebolas;
} Treinador;

void InicializaTreinadores(Treinador *trainer1, Treinador *trainer2);
void MovimentaTreinador(Treinador *trainer, int position[]);
void CapturaPokemon(Treinador *trainer, Pokemon *poke);
void ImprimeTreinador(Treinador *trainer);
void RemovePokemonTreinador (Lista *lista_trainer, Lista *lista_pokecenter);
int getIdTreinador(Treinador *trainer);
void getCoordenadaTreinador (Treinador *trainer, int coordenada_treinador[]);
void getNomeTreinador (Treinador *trainer, char nome_treinador[]);
int getPokebolasTreinador (Treinador *trainer);
void setPokebolasTreinador (Treinador *trainer, int pokebolas);
#endif