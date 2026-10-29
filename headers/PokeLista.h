#ifndef POKELISTA_H
#define POKELISTA_H
// Inclusão do arquivo Pokemon.h pois o TAD PokeLista armazena uma variável do tipo Pokemon.
#include "Pokemon.h"

//TAD Lista que guarda um ponteiro para a primeira célula de uma lista de pokémons
typedef struct pokelista{
    struct pokecelula *Primeiro;
}PokeLista;

typedef struct centropesquisa CentroPesquisa;

// TAD PokeLista que é uma célula de uma lista que guarda pokémons. Possui um ponteiro que aponta para a célula imediatamente posterior a ela.
typedef struct pokecelula{
    Pokemon pokemon;
    struct pokecelula * pProx;
} PokeCelula;

int ListaEVazia (PokeLista *lista);
void InicializaLista(PokeLista *lista);
void InserePokemon(PokeLista *lista, Pokemon *poke);
int RemovePokemon (PokeLista *lista);
void ImprimePokemons (PokeLista *lista);
void EsvaziaPokeLista (PokeLista *lista);


#endif