#include "PokeLista.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct pokemon Pokemon;

// Retorna 1 se o primeiro é igual a nulo.
int ListaEVazia (Lista *lista){
    if (lista -> Primeiro){
        return 0;
    } else {
        return 1;
    }
}

void InicializaLista (Lista *lista){
    lista -> Primeiro = NULL;
}

void InserePokemon (Lista *lista, Pokemon *poke){
    // Aloca memória para um novo nó e faz ele ser o novo primeiro ao atribuir ao campo pProx o antigo primeiro.
    PokeLista *nova_celula = (PokeLista*) malloc (sizeof(PokeLista));
    (*nova_celula).pokemon = (*poke);
    (*nova_celula).pProx = lista -> Primeiro;
    lista -> Primeiro = nova_celula;
}

void BuscaPokemon (Lista *lista, int id){
    int True = 1;
    PokeLista *atual = lista -> Primeiro;
    // Percorre a lista até achar um pokémon que tem o mesmo id que o recebido ou o ponteiro ser nulo.
    while (True){
        if ((*atual).pokemon.id_pokemon == id){
            printf("Id do Pokémon: %d\n", (*lista).Primeiro -> pokemon.id_pokemon);
            printf("Número da Pokédex: %d\n", (*lista).Primeiro -> pokemon.pokedex);
            printf("Nome do Pokémon: %s\n", (*lista).Primeiro -> pokemon.nome);
            printf("Tipo do Pokémon: %s\n", (*lista).Primeiro -> pokemon.tipo);
            printf("Coordenadas do Pokémon: (%d,%d)\n", (*lista).Primeiro -> pokemon.coordenadas[0], (*lista).Primeiro -> pokemon.coordenadas[1]);
            True = 0;
            break;
        } else {
            atual = (*atual).pProx;
            if (atual == NULL){
                printf("Pokémon não encontrado.\n");
                True = 0;
                break;
            }
        }
    }
}
void ImprimePokemons (Lista *lista){
    // Percorre a lista imprimindo cada campo até o ponteiro ser nulo.
    if (ListaEVazia(lista)){
        printf("A lista está vazia!\n");
    } else {
        PokeLista *aux = lista -> Primeiro;
        while (aux){
            printf("Id do Pokémon: %d\n", aux -> pokemon.id_pokemon);
            printf("Número da Pokédex: %d\n", aux -> pokemon.pokedex);
            printf("Nome do Pokémon: %s\n", aux -> pokemon.nome);
            printf("Tipo do Pokémon: %s\n", aux -> pokemon.tipo);
            printf("Coordenadas do Pokémon: (%d,%d)\n", aux -> pokemon.coordenadas[0], aux -> pokemon.coordenadas[1]);
            aux = (*aux).pProx;
        }
    }    
}

int RemovePokemon (Lista *lista){
        // Faz o primeiro da lista ser igual ao segundo e libera a memória do antigo primeiro.
        if (ListaEVazia(lista)){
            return 0;
        }
        PokeLista *aux = lista -> Primeiro;
        (*lista).Primeiro = (*lista).Primeiro -> pProx;
        free(aux);
}
