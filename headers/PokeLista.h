#include <stdio.h>
#ifndef POKELISTA_H
#define POKELISTA_H
#define MAX 50000
#include "Pokemon.h"

typedef struct pokelista {
    Pokemon MochilaPokemon[MAX];
    int Primeiro, Ultimo;
} PokeLista;

void InicializaPokeLista (PokeLista *NovaPokeLista);
int PokeListaEVazia (PokeLista *NovaPokeLista);
void InserePokemon (PokeLista *NovaPokeLista, Pokemon *Lucario);
void ImprimePokeLista (PokeLista *NovaPokeLista);

#endif