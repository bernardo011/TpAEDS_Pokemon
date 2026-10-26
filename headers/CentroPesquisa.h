#ifndef CENTRO_PESQUISA_H
#define CENTRO_PESQUISA_H
// Inclusão do arquivo PokeLista.h necessária pois uma variável do tipo Lista é declarada no TAD CentroPesquisa.
#include "PokeLista.h"

// Declaração prévia da struct Treinador pois um ponteiro desse tipo será usado em uma das funções.
typedef struct treinador Treinador;

// Struct que armazena duas listas encadeadas e o total de pokémons fugitivos.
typedef struct centropesquisa{
    int total_pokemons;
    int total_energia;
    Lista PokemonsFugitivos;
}CentroPesquisa;

void InicializaCentroPesquisa (CentroPesquisa *cp);
void InsereFugitivos (CentroPesquisa *cp);
int RemovePokemonFugitivo (Lista *lista);

#endif