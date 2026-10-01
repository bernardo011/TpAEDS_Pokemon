#include "../headers/PokeLista.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct pokemon Pokemon;

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
    // Eu crio um ponteiro para um endereço no heap que aloca memória para minha struct
    //PokeLista, depois acesso esse ponteiro e guardo um pokemon, acesso o campo de apon-
    //tador da minha nova célula e faço ele ser igual ao antigo primeiro que estava sendo
    //apontado pela minha célula cabeça e faço a célula cabeça apontar para a nova célula
    PokeLista *nova_celula = (PokeLista*) malloc (sizeof(PokeLista));
    (*nova_celula).pokemon = (*poke);
    (*nova_celula).pProx = lista -> Primeiro;
    lista -> Primeiro = nova_celula;
}

void BuscaPokemon (Lista *lista, int id){
    int True = 1;
    PokeLista *atual = lista -> Primeiro;
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
        if (ListaEVazia(lista)){
            return 0;
        }
        PokeLista *aux = lista -> Primeiro;
        (*lista).Primeiro = (*lista).Primeiro -> pProx;
        free(aux);
}
