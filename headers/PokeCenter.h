#ifndef POKECENTER_H
#define POKECENTER_H
#include "PokeLista.h"

typedef struct pokecenter {
    int TotalPokemons;
    PokeLista Pokemons;
} PokeCenter;   

void InicializaPokeCenter (PokeCenter *NovoPokeCenter);
void OrdenaSelectionSort (PokeCenter *NovoPokeCenter);

#endif