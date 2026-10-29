#include <stdio.h>
#include <stdlib.h>
#include "TimePokemon.h"
#include "PokeLista.h"

void VerificaTime (int * subconjunto, int num_elementos, PokeLista *EstoquePokemons, int energia_total, TimePokemon *MelhorTime){
    if (num_elementos == 0){
        return ;
    }
    PokeCelula *aux = EstoquePokemons -> Primeiro;
    int index = 1;
    TimePokemon TimeCombinacao;
    InicializaLista (&TimeCombinacao.MelhorTime);
    TimeCombinacao.poder = 0;
    TimeCombinacao.energia = 0;
    while (aux){
        for (int i = 1; i<=num_elementos; i++){
            if (index == subconjunto[i]){
                InserePokemon(&TimeCombinacao.MelhorTime, &aux->pokemon);
                TimeCombinacao.poder+=aux->pokemon.poder;
                TimeCombinacao.energia+=aux->pokemon.energia;
                break;
            }
        }
        index++;
        aux = aux->pProx;
    }
    if ((TimeCombinacao.energia<=energia_total) && TimeCombinacao.poder>=(*MelhorTime).poder){
        if (TimeCombinacao.poder>(*MelhorTime).poder){
            EsvaziaPokeLista(&(*MelhorTime).MelhorTime);
            (*MelhorTime) = TimeCombinacao;
            return ;
        }
    }
    EsvaziaPokeLista(&TimeCombinacao.MelhorTime);
    return ;
}
