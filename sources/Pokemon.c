#include "Pokemon.h"
#include <stdio.h>
#include <string.h>

void InicializaPokemon (Pokemon *Lucario, int pokedex, char nome[], char tipo[], int poder){
    // Inicializa o pokémon copiando os parâmetros recebidos para dentro da estrutura que o armazena.
    Lucario -> pokedex = pokedex;
    strcpy (Lucario -> nome, nome);
    strcpy (Lucario -> tipo, tipo);
    Lucario -> poder = poder;

}

void ImprimePokemon (Pokemon *Lucario, FILE *arq){
    // Imprime somente um pokémon dentro de um arquivo específico.
        fprintf (arq, "| Poder: %-3d | Pokémon: %-15s | Tipo: %-15s | Pokedex: %-4d | \n", Lucario -> poder, Lucario -> nome, Lucario -> tipo, Lucario -> pokedex);
}

int getPoder (Pokemon *Lucario){
    // Retorna o poder do pokémon.
    return Lucario -> poder;
}