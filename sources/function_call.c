#include "function_call.h"
#include "CentroPesquisa.h"
#include "PokeLista.h"
#include "Pokemon.h"
#include "Treinador.h"
#include "TimePokemon.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
// Log da missão após a atribuição ter sido feita pela função "AtribuiMission"


void Inicializa (CentroPesquisa **poke_center, Treinador **trainer1, Treinador **trainer2, TimePokemon **MelhorTime){
    // Aloca memória para as variáveis recebidas da main 
    CentroPesquisa *aux = (CentroPesquisa*) malloc (sizeof(CentroPesquisa));
    (*poke_center) = aux;
    Treinador *t1 = (Treinador*) malloc (sizeof(Treinador));
    Treinador *t2 = (Treinador*) malloc (sizeof(Treinador));
    TimePokemon *Maux = (TimePokemon*) malloc (sizeof(TimePokemon));
    (*MelhorTime) = Maux;
    (*trainer1) = t1;
    (*trainer2) = t2;
    // Inicializa os TAD's Treinador e PokeCenter, juntamente de suas listas.
    RegistraDados (trainer1, trainer2, poke_center, MelhorTime);
}


void RegistraDados (Treinador **trainer1, Treinador **trainer2, CentroPesquisa **poke_center, TimePokemon **MelhorTime){
    // Inicializa os treinadores (lendo o arquivo) e suas respectivas listas. Inicializa as listas do PokeCenter.
    InicializaTreinadores(*trainer1, *trainer2);
    InicializaCentroPesquisa (*poke_center);
    InicializaLista(&(*MelhorTime)->MelhorTime);
    (*MelhorTime)->poder = 0;
    (*MelhorTime)->energia = 0;
    InserePokemonEntrada (*poke_center);
}

void GerarCombinacoes (int vetor[], int start, int n, int k, int maxk, PokeLista *EstoquePokemon, int energia_total, TimePokemon *MelhorTime, int *count){
    if (k>maxk){
        VerificaTime(vetor, maxk, EstoquePokemon, energia_total, MelhorTime);
        (*count)++;
        return ;
    }
    for (int i = start; i<=n; i++){
        vetor[k] = i;
        GerarCombinacoes(vetor, i+1, n, k+1, maxk, EstoquePokemon, energia_total, MelhorTime, count);
    }
}
