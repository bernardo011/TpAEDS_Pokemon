#include "PokeLista.h"
#include <stdio.h>
typedef struct pokemon Pokemon;

int ListaEVazia (PokeLista *lista){
    if ((*lista).ultimo == (*lista).primeiro){
        return 1;
    } else {
        return 0;
    }
}

void InicializaPokeLista (PokeLista *lista){
    (*lista).primeiro = 0;
    (*lista).ultimo = 0;
}
void InserePokemon (PokeLista *lista, Pokemon *poke){
    (*lista).pokemons[(*lista).ultimo] = (*poke);
    (*lista).ultimo++;
}

void RemovePokemonFugitivo (PokeLista *listacentro){
    (*listacentro).primeiro++;
}
void RemovePokemonTreinador (PokeLista *listatreinador, PokeLista *listacentro){
    for (int i = (*listatreinador).primeiro; i<(*listatreinador).ultimo; i++){
        (*listacentro).pokemons[(*listacentro).ultimo] = (*listatreinador).pokemons[i];
        (*listacentro).ultimo++;
    }
    (*listatreinador).ultimo = (*listatreinador).primeiro;
}
void BuscaPokemon (PokeLista *lista, int id){
    for (int i = (*lista).primeiro; i<(*lista).ultimo; i++){
        if (((*lista).pokemons[i].id_pokemon) == id){
            printf("Id Pokemon: %d\n", (*lista).pokemons[i].id_pokemon);
        }
    }
}
void ImprimePokemons (PokeLista *lista){
    for (int i = (*lista).primeiro; i<(*lista).ultimo; i++){
        printf("Id: %d\n", (*lista).pokemons[i].id_pokemon);
    }
}
