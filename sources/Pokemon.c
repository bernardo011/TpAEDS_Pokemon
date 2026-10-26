#include <stdio.h>
#include <string.h>
#include "Pokemon.h"

void InicializaPokemon (Pokemon *poke, int id,int pokedex, char nome[], char tipo[], int poder, int energia){
    // Preenche os campos da struct com os valores recebidos pela função
    poke->id_pokemon=id;
    poke->pokedex=pokedex;
    strcpy(poke->nome, nome);
    strcpy(poke->tipo, tipo);
    poke->poder = poder;
    poke->energia = energia;
};


void getNomePoke (Pokemon *poke, char nomePoke[]){
    strcpy(nomePoke, poke->nome);
};
