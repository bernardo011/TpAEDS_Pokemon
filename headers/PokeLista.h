#ifndef POKELISTA_H
#define POKELISTA_H
#include "Pokemon.h"

typedef struct lista{
    struct pokelista *Primeiro;
}Lista;

typedef struct pokelista{
    Pokemon pokemon;
    struct pokelista * pProx;
} PokeLista;

int ListaEVazia (Lista *lista);
void InicializaLista(Lista *lista);
void InserePokemon(Lista *lista, Pokemon *poke);
int RemovePokemonFugitivo (Lista *lista);
void RemovePokemonTreinador (Lista *lista_trainer, Lista *lista_pokecenter);
void BuscaPokemon (Lista *lista, int id);
void ImprimePokemons (Lista *lista);


#endif