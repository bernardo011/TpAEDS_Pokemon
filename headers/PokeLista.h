#ifndef POKELISTA_H
#define POKELISTA_H
// Inclusão do arquivo Pokemon.h pois o TAD PokeLista armazena uma variável do tipo Pokemon.
#include "Pokemon.h"

//TAD Lista que guarda um ponteiro para a primeira célula de uma lista de pokémons
typedef struct lista{
    struct pokelista *Primeiro;
}Lista;

// TAD PokeLista que é uma célula de uma lista que guarda pokémons. Possui um ponteiro que aponta para a célula imediatamente posterior a ela.
typedef struct pokelista{
    Pokemon pokemon;
    struct pokelista * pProx;
} PokeLista;

int ListaEVazia (Lista *lista);
void InicializaLista(Lista *lista);
void InserePokemon(Lista *lista, Pokemon *poke);
void RemovePokemon (Lista *lista);
void BuscaPokemon (Lista *lista, int id);
void ImprimePokemons (Lista *lista);


#endif
