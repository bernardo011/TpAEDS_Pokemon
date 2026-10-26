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

int RemovePokemon (Lista *lista){
        // Faz o primeiro da lista ser igual ao segundo e libera a memória do antigo primeiro.
        if (ListaEVazia(lista)){
            return 0;
        }
        PokeLista *aux = lista -> Primeiro;
        (*lista).Primeiro = (*lista).Primeiro -> pProx;
        free(aux);
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
            printf("Poder e Energia: (%d,%d)\n", aux -> pokemon.poder, aux -> pokemon.energia);
            aux = (*aux).pProx;
        }
    }    
}
