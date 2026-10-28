#include <stdio.h>
#include "function_call.h"
#include "PokeLista.h"
#include "Pokemon.h"
#include "Treinador.h"
#include "CentroPesquisa.h"
#include <stdlib.h>
#include <time.h>

int main(){

    clock_t inicio, fim;
    double tempo_total;
    inicio = clock();
    // Cria os ponteiros que terão um endereço de memória dinâmicamente alocado pela função Inicializa
    CentroPesquisa *poke_center;
    Treinador *trainer1, *trainer2;
    // Atribui um endereço de memória as variáveis criadas e dá início a missão.
    Inicializa (&poke_center, &trainer1, &trainer2);
    // Atribui as missões sucessivamentes até que a lista de pokémons fugitivos esteja vazia
    printf("%d\n", (*poke_center).total_pokemons);
    int *v;
    v = (int*) malloc (((*poke_center).total_pokemons+1) * sizeof(int));
    int poder_atual = 0;
    int energia_atual = 0;
    int energia_total = (*poke_center).total_energia;
    for (int i = 0; i<=(*poke_center).total_pokemons; i++){
        GerarCombinacoes(v, 1, (*poke_center).total_pokemons+1, 1, i, &poke_center->EstoquePokemon, &poder_atual, &energia_atual, energia_total);
    }
    printf("\n");
    printf("%d, %d", poder_atual, energia_atual);
    free(trainer1);
    free(trainer2);
    free(poke_center);
    fim = clock();
    tempo_total = (double)(fim-inicio)/CLOCKS_PER_SEC;
    printf("\nTempo total de execução %f segundos\n", tempo_total);
    return 0;
}