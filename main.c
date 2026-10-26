#include <stdio.h>
#include "function_call.h"
#include "PokeLista.h"
#include "Pokemon.h"
#include "Treinador.h"
#include "CentroPesquisa.h"
#include "stdlib.h"

int main(){
    // Cria os ponteiros que terão um endereço de memória dinâmicamente alocado pela função Inicializa
    CentroPesquisa *poke_center;
    Treinador *trainer1, *trainer2;
    // Atribui um endereço de memória as variáveis criadas e dá início a missão.
    Inicializa (&poke_center, &trainer1, &trainer2);
    // Atribui as missões sucessivamentes até que a lista de pokémons fugitivos esteja vazia
    ImprimePokemons (&poke_center->PokemonsFugitivos);
    printf("\n%d\n", (*poke_center).total_pokemons);
    printf("\n%d\n", (*poke_center).total_energia);
    printf("%s\n%s", (*trainer1).nome, (*trainer2).nome);
    int vetor[100];
    for (int i = 0; i<=5; i++){
        GerarCombinacoes(vetor, 1, 5, 1, i);
    }
    Pokemon *vetor_pokemon[100];
    InicializaVetorPointerPokemon (vetor_pokemon, poke_center);
    for (int i = 1; i<=poke_center->total_pokemons; i++){
        printf("%d %s %s (%d, %d)\n", vetor_pokemon[i]->pokedex, vetor_pokemon[i]->nome, vetor_pokemon[i]->tipo, vetor_pokemon[i]->poder, vetor_pokemon[i]->energia);
    }
    free(trainer1);
    free(trainer2);
    free(poke_center);
    return 0;
}