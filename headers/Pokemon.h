#ifndef POKEMON_H
#define POKEMON_H
typedef struct pokemon {
    int id_pokemon;
    int pokedex;
    char nome[50];
    char tipo[50];
    int coordenadas_pokemon[2];
} Pokemon;

//
void InicializaPokemon(Pokemon *poke, int id, char nome[], char tipo[], int coordenadas_pokemon[]);



#endif