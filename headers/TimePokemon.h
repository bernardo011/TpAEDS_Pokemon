#ifndef TIME_POKEMON_H
#define TIME_POKEMON_H

typedef struct pokelista PokeLista;

typedef struct timepokemon{
    PokeLista MelhorTime;
    int poder;
    int energia;
} TimePokemon;

void VerificaTime (int * subconjunto, int num_elementos, PokeLista *EstoquePokemon0s, int energia_total, TimePokemon *MelhorTime);

#endif