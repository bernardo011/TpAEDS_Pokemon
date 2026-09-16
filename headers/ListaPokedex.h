#ifndef POKELISTA_H
#define POKELISTA_H
typedef struct pokemon Pokemon;
typedef struct pokelista PokeLista{

} PokeLista;

void InicializaPokeLista(PokeLista *lista);
void InserePokemon(PokeLista *lista, Pokemon *poke);
void RemovePokemon (PokeLista *lista, int id);
void BuscaPokemon (PokeLista *lista, int id);
void ImprimePokemon (PokeLista *lista);

#endif