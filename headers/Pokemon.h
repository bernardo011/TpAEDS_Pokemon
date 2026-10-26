#ifndef POKEMON_H
#define POKEMON_H

// TAD Pokémon que armazena as informações de um pokémon.
typedef struct pokemon{
    int id_pokemon;
    int pokedex;
    char nome[50];
    char tipo[50];
    int poder;
    int energia;
}Pokemon;

void InicializaPokemon (Pokemon *poke, int id, int pokedex, char nome[], char tipo[], int poder, int energia);
void getNomePoke (Pokemon *poke, char nomePoke[]);

#endif