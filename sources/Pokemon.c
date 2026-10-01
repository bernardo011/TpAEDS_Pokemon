#include <stdio.h>
#include <string.h>
#include "Pokemon.h"

void InicializaPokemon (Pokemon *poke, int id,int pokedex, char nome[], char tipo[], int x, int y){
    // Preenche os campos da struct com os valores recebidos pela função
    poke->id_pokemon=id;
    poke->pokedex=pokedex;
    strcpy(poke->nome, nome);
    strcpy(poke->tipo, tipo);
    poke->coordenadas[0]=x;
    poke->coordenadas[1]=y;
};

void ImprimePokemon (Pokemon *poke){
    printf("Pokémon Alvo: %s\n",poke->nome);
    printf("Localização: (%d,%d)", poke->coordenadas[0], poke->coordenadas[1]);
};

void getNomePoke (Pokemon *poke, char nomePoke[]){
    strcpy(nomePoke, poke->nome);
};

void getCoordenadaPoke (Pokemon *poke, int coordenada_pokemon[]){
    coordenada_pokemon[0]=poke->coordenadas[0];
    coordenada_pokemon[1]=poke->coordenadas[1];
};