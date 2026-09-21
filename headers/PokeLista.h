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
int RemovePokemon (Lista *lista);
void BuscaPokemon (Lista *lista, int id);
void ImprimePokemons (Lista *lista);


#endif