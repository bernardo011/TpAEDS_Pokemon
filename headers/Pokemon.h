#include <stdio.h>
#ifndef POKEMON_H
#define POKEMON_H

typedef struct pokemon {
    int pokedex;
    char nome[50];
    char tipo[50];
    int poder;
} Pokemon;

void InicializaPokemon (Pokemon *Lucario, int pokedex, char nome[], char tipo[], int poder);
void ImprimePokemon (Pokemon *Lucario, FILE *arq);
int getPoder (Pokemon *Lucario);

#endif