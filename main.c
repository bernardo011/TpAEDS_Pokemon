#include <stdio.h>
#include "function_call.h"
#include "PokeLista.h"
#include "Pokemon.h"
#include "Treinador.h"
#include "CentroPesquisa.h"
#include "TimePokemon.h"
#include <stdlib.h>
#include <time.h>

int main(){
    
    clock_t inicio, fim;
    double tempo_total;
    inicio = clock();
    TimePokemon *MelhorTime;
    Treinador *trainer1, *trainer2;
    CentroPesquisa *poke_center;
    Inicializa (&poke_center, &trainer1, &trainer2, &MelhorTime);    
    int *v;
    v = (int*) malloc (((*poke_center).total_pokemons+1) * sizeof(int));
    int energia_total = (*poke_center).total_energia;
    int count = 0;
    for (int i = 0; i<=(*poke_center).total_pokemons; i++){
        GerarCombinacoes(v, 1, (*poke_center).total_pokemons+1, 1, i, &poke_center->EstoquePokemon, energia_total, MelhorTime, &count);
    }
    fim = clock();
    tempo_total = (double)(fim-inicio)/CLOCKS_PER_SEC;
    printf("... Pokémon Carregados ...\n");
    ImprimePokemons(&poke_center->EstoquePokemon);
    printf("\n");
    printf("=== Executando seleção de Pokémon (Força bruta) ===\n");
    printf("\n");
    printf("=== Melhor equipe encontrada ===\n");
    printf("Poder total: %d\n", MelhorTime->poder);
    printf("Energia total consumida: %d/%d\n", MelhorTime->energia, energia_total);
    printf("\nTempo de execução %f segundos\n", tempo_total);
    printf("\n");
    printf("Pokémon Selecionados para a equipe:\n");
    ImprimePokemons(&(*MelhorTime).MelhorTime);
    printf("\n");
    DivideLista(&MelhorTime->MelhorTime, &trainer1->TimeTreinador, &trainer2->TimeTreinador);
    printf("=== Equipes dos treinadores ===\n");
    printf("Treinador 1: %s\n", trainer1->nome);
    printf("Mochila do treinador:\n");
    ImprimePokemons(&trainer1->TimeTreinador);
    printf("Treinador 2: %s\n", trainer2->nome);
    printf("Mochila do treinador:\n");
    ImprimePokemons(&trainer2->TimeTreinador);
    EsvaziaPokeLista(&poke_center->EstoquePokemon);
    EsvaziaPokeLista(&(*MelhorTime).MelhorTime);
    EsvaziaPokeLista(&trainer1->TimeTreinador);
    EsvaziaPokeLista(&trainer2->TimeTreinador);
    free(v);
    free(MelhorTime);
    free(poke_center);
    free(trainer1);
    free(trainer2);
    return 0;
}