#ifndef POKELISTA_H
#define POKELISTA_H
#include "Pokemon.h"

typedef struct pokelista{
    Pokemon pokemons[10];
    int ultimo;
    int primeiro;
} PokeLista;

void InicializaPokeLista(PokeLista *lista);
void InserePokemon(PokeLista *lista, Pokemon *poke);
void RemovePokemonFugitivo (PokeLista *lista);
void RemovePokemonTreinador (PokeLista *listatreinador, PokeLista *listacentro);
void BuscaPokemon (PokeLista *lista, int id);
void ImprimePokemons (PokeLista *lista);
int ListaEVazia (PokeLista *lista);

#endif