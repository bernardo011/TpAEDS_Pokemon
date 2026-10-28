#ifndef CENTRO_PESQUISA_H
#define CENTRO_PESQUISA_H
// Inclusão do arquivo PokePokeLista.h necessária pois uma variável do tipo PokeLista é declarada no TAD CentroPesquisa.
#include "PokeLista.h"

// Declaração prévia da struct Treinador pois um ponteiro desse tipo será usado em uma das funções.
typedef struct treinador Treinador;

// Struct que armazena duas PokeListas encadeadas e o total de pokémons fugitivos.
typedef struct centropesquisa{
    int total_pokemons;
    int total_energia;
    PokeLista EstoquePokemon;
} CentroPesquisa;

void InicializaCentroPesquisa (CentroPesquisa *cp);
void InsereFugitivos (CentroPesquisa *cp);
int RemovePokemonFugitivo (PokeLista *PokeLista);

#endif