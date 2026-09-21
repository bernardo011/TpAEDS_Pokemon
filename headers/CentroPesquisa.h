#ifndef CENTRO_PESQUISA_H
#define CENTRO_PESQUISA_H
#include "PokeLista.h"

typedef struct treinador Treinador;

typedef struct centropesquisa{
    int total;
    Lista PokemonsFugitivos;
    Lista PokemonsRecuperados;
}CentroPesquisa;

void InicializaCentroPesquisa (CentroPesquisa *cp);
void InsereFugitivos (CentroPesquisa *cp);
int RemovePokemonFugitivo (Lista *lista);
void ImprimeFugitivos (CentroPesquisa *cp);
void RecebePokemons (CentroPesquisa *cp, Treinador *trainer);
void RecargaPokebolas (int *x);

#endif