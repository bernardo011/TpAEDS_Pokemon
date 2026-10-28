#ifndef FUNCTION_CALL_H
#define FUNCTION_CALL_H
// Declaração prévia das structs que precisarão de um ponteiro nas funções abaixo.
typedef struct centropesquisa CentroPesquisa;
typedef struct treinador Treinador;
typedef struct pokemon Pokemon;
typedef struct pokelista PokeLista;
typedef struct timepokemon TimePokemon;

void Inicializa (CentroPesquisa **poke_center, Treinador **trainer1, Treinador **trainer2, TimePokemon **MelhorTime);
void RegistraDados (Treinador **trainer1, Treinador **trainer2, CentroPesquisa **poke_center, TimePokemon **MelhorTime);
void GerarCombinacoes (int vetor[], int start, int n, int k, int maxk, PokeLista *EstoquePokemon, int energia_total, TimePokemon *MelhorTime, int *count);
void InicializaVetorPointerPokemon (Pokemon *vetor[], CentroPesquisa *PokeCenter);
#endif