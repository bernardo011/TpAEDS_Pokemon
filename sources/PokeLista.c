#include "PokeLista.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct pokemon Pokemon;

// Retorna 1 se o primeiro é igual a nulo.
int ListaEVazia (PokeLista *lista){
    if (lista -> Primeiro){
        return 0;
    } else {
        return 1;
    }
}

void InicializaLista (PokeLista *lista){
    lista -> Primeiro = NULL;
}

void InserePokemon (PokeLista *lista, Pokemon *poke){
    // Aloca memória para um novo nó e faz ele ser o novo primeiro ao atribuir ao campo pProx o antigo primeiro.
    PokeCelula *nova_celula = (PokeCelula*) malloc (sizeof(PokeCelula));
    (*nova_celula).pokemon = (*poke);
    (*nova_celula).pProx = lista -> Primeiro;
    lista -> Primeiro = nova_celula;
}

int RemovePokemon (PokeLista *lista){
        // Faz o primeiro da lista ser igual ao segundo e libera a memória do antigo primeiro.
        if (ListaEVazia(lista)){
            return 0;
        }
        PokeCelula *aux = lista -> Primeiro;
        (*lista).Primeiro = (*lista).Primeiro -> pProx;
        free(aux);
}

void ImprimePokemons (PokeLista *lista){
    // Percorre a lista imprimindo cada campo até o ponteiro ser nulo.
    if (ListaEVazia(lista)){
        printf("A lista está vazia!\n");
    } else {
        PokeCelula *aux = lista -> Primeiro;
        while (aux){
            printf("ID: %-4d| Nome: %-15s| Tipo: %-15s| Poder: %-3d| Energia: %-3d\n", aux -> pokemon.pokedex, aux->pokemon.nome, aux->pokemon.tipo, aux->pokemon.poder, aux->pokemon.energia);
            aux = (*aux).pProx;
        }
    }    
}

void EsvaziaPokeLista (PokeLista *lista){
    if (ListaEVazia(lista)){
        return ;
    }
    PokeCelula *aux = lista -> Primeiro;
    while (aux){
        PokeCelula *aux2 = aux;
        aux = aux->pProx;
        if (aux2){
            free(aux2);
        }
    }
}