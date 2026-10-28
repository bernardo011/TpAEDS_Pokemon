#ifndef FUNCTION_CALL_H
#define FUNCTION_CALL_H
// Declaração prévia das structs que precisarão de um ponteiro nas funções abaixo.
typedef struct centropesquisa CentroPesquisa;
typedef struct treinador Treinador;
typedef struct pokemon Pokemon;
typedef struct pokelista PokeLista;

void Inicializa (CentroPesquisa **poke_center, Treinador **trainer1, Treinador **trainer2);
void RegistraDados (Treinador **trainer1, Treinador **trainer2, CentroPesquisa **poke_center);
void GerarCombinacoes (int vetor[], int start, int n, int k, int maxk, PokeLista *EstoquePokemon, int *poder_atual, int *energia_atual, int energia_total);
void InicializaVetorPointerPokemon (Pokemon *vetor[], CentroPesquisa *PokeCenter);
#endif