#include "Pokemon.h"
#include <stdio.h>
#include <string.h>

void InicializaPokemon(Pokemon *poke, int id, int pokedex, char nome[], char tipo[], int coordenadas_pokemon[]){
    (*poke).id_pokemon = id;
    (*poke).pokedex = pokedex;
    (*poke).coordenadas[0] = coordenadas_pokemon[0];
    (*poke).coordenadas[1] = coordenadas_pokemon[1];
    strcpy((*poke).tipo, tipo);
    strcpy((*poke).nome, nome);
}