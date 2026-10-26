#ifndef FUNCTION_CALL_H
#define FUNCTION_CALL_H
// Declaração prévia das structs que precisarão de um ponteiro nas funções abaixo.
typedef struct centropesquisa CentroPesquisa;
typedef struct treinador Treinador;
typedef struct pokemon Pokemon;

void Inicializa (CentroPesquisa **poke_center, Treinador **trainer1, Treinador **trainer2);
void RegistraDados (Treinador **trainer1, Treinador **trainer2, CentroPesquisa **poke_center);
void GerarCombinacoes (int vetor[], int start, int n, int k, int maxk);
void InicializaVetorPointerPokemon (Pokemon *vetor[], CentroPesquisa *PokeCenter);
#endif