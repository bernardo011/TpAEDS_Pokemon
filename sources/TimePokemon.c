#include <stdio.h>
#include <stdlib.h>
#include "TimePokemon.h"
#include "PokeLista.h"

void VerificaTime (int * subconjunto, int num_elementos, PokeLista *EstoquePokemons, int *poder_atual, int *energia_atual, int energia_total){
    if (num_elementos == 0){
        return ;
    }
    int poder_combinacao = 0;
    int energia_combinacao = 0;
    PokeCelula *aux = EstoquePokemons -> Primeiro;
    int index = 1;
    while (aux){
        for (int i = 1; i<=num_elementos; i++){
            if (index == subconjunto[i]){
                poder_combinacao+=aux->pokemon.poder;
                energia_combinacao+=aux->pokemon.energia;
                break;
            }
        }
        index++;
        aux = aux->pProx;
    }
    if ((energia_combinacao<=energia_total) && poder_combinacao>=*poder_atual){
        if (poder_combinacao>*poder_atual){
            *poder_atual = poder_combinacao;
            *energia_atual = energia_combinacao;
        }
    }
}
