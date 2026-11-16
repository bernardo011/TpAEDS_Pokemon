#include "PokeLista.h"
#include "Pokemon.h"
#include <stdio.h>

void InicializaPokeLista (PokeLista *NovaPokeLista){
    // Inicializa o vetor de pokémons.
    NovaPokeLista -> Primeiro = 0;
    NovaPokeLista -> Ultimo = 0;
}

int PokeListaEVazia (PokeLista *NovaPokeLista){
    // Verifica se a lista está vazia.
    return (NovaPokeLista -> Primeiro == NovaPokeLista -> Ultimo);
}

void InserePokemon (PokeLista *NovaPokeLista, Pokemon *Lucario){
    // Insere um novo pokémon se a lista não estiver cheia.
    if (NovaPokeLista -> Ultimo == MAX)
        return;
    else {
        NovaPokeLista -> MochilaPokemon[NovaPokeLista -> Ultimo] = (*Lucario);
        NovaPokeLista -> Ultimo++;
    }
}
void ImprimePokeLista (PokeLista *NovaPokeLista){
   // Imprime todos os pokémons da lista em um arquivo de saída. 
   if (PokeListaEVazia(NovaPokeLista))
        return ;
    else {
        FILE *arq = fopen("saida.txt", "w");
        for (int i = NovaPokeLista -> Primeiro; i < NovaPokeLista -> Ultimo; i++){
            ImprimePokemon (&NovaPokeLista -> MochilaPokemon[i], arq);
        }
    }
}