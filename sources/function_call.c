#include "function_call.h"
#include "CentroPesquisa.h"
#include "PokeLista.h"
#include "Pokemon.h"
#include "Treinador.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
// Log da missão após a atribuição ter sido feita pela função "AtribuiMission"


void Inicializa (CentroPesquisa **poke_center, Treinador **trainer1, Treinador **trainer2){
    // Aloca memória para as variáveis recebidas da main 
    CentroPesquisa *aux = (CentroPesquisa*) malloc (sizeof(CentroPesquisa));
    (*poke_center) = aux;
    Treinador *t1 = (Treinador*) malloc (sizeof(Treinador));
    Treinador *t2 = (Treinador*) malloc (sizeof(Treinador));
    (*trainer1) = t1;
    (*trainer2) = t2;
    // Inicializa os TAD's Treinador e PokeCenter, juntamente de suas listas.
    RegistraDados (trainer1, trainer2, poke_center);
}


void RegistraDados (Treinador **trainer1, Treinador **trainer2, CentroPesquisa **poke_center){
    // Inicializa os treinadores (lendo o arquivo) e suas respectivas listas. Inicializa as listas do PokeCenter.
    InicializaTreinadores(*trainer1, *trainer2);
    InicializaCentroPesquisa (*poke_center);
    // Preenche a lista de fugitivos do PokeCenter de acordo com o arquivo de teste.
    InsereFugitivos (*poke_center);
}

void GerarCombinacoes (int vetor[], int start, int n, int k, int maxk){
    if (k>maxk){
        for (int i = 1; i<=maxk; i++){
            printf("%d ", vetor[i]);
        }
        printf("\n");
        return ;
    }
    for (int i = start; i<=n; i++){
        vetor[k] = i;
        GerarCombinacoes(vetor, i+1, n, k+1, maxk);
    }
}
void InicializaVetorPointerPokemon (Pokemon *vetor[], CentroPesquisa *PokeCenter){
    if (ListaEVazia(&PokeCenter->PokemonsFugitivos)){
        printf("Impossível inicializar o vetor de ponteiro para Pokémon pois a lista está vazia\n");
         return;
    }
    PokeLista *aux = PokeCenter->PokemonsFugitivos.Primeiro;
    for (int i = 1; i<=PokeCenter->total_pokemons; i++){
        vetor[i] = &aux->pokemon;
        aux = aux->pProx;
    }
}
