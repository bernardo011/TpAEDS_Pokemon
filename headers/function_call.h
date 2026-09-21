#ifndef FUNCTION_CALL_H
#define FUNCTION_CALL_H
typedef struct centropesquisa CentroPesquisa;
typedef struct treinador Treinador;
typedef struct pokemon Pokemon;

void Mission (Treinador *trainer, CentroPesquisa *poke_center, double dist1, double dist2);
double Distancia (Treinador **trainer1, Pokemon *poke);
void Inicializa (CentroPesquisa **poke_center, Treinador **trainer1, Treinador **trainer2);
void RegistraDados (Treinador **trainer1, Treinador **trainer2, CentroPesquisa **poke_center);
void AtribuiMission (CentroPesquisa **poke_center, Treinador **trainer1, Treinador **trainer2);
void RetornaCentroPesquisa (Treinador *trainer, CentroPesquisa *poke_center);
void RelatorioFinal (CentroPesquisa *poke_center);
#endif