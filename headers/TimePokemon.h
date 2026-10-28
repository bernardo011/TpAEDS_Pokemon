#ifndef TIME_POKEMON_H
#define TIME_POKEMON_H

typedef struct pokelista PokeLista;

typedef struct timepokemon{
    int tamanho;
    int *position;
} TimePokemon;

void VerificaTime (int * subconjunto, int num_elementos, PokeLista *EstoquePokemons, int *poder_atual, int *energia_atual, int energia_total);

#endif