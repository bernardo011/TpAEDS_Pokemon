#include <stdio.h>
#include <string.h>
#include "Treinador.h"

void InicializaTreinadores(Treinador *trainer1, Treinador *trainer2, FILE *p){
    p = fopen("teste.txt", "r");
    int index = 0;
    char nomeTreinador;
    int pokebolas;
    while (fscanf("%s %d", nomeTreinador, &pokebolas) == 2){
        if (!index){
            trainer1 -> QtdPokebolas = pokebolas;
            strcpy ((*trainer1).nome, nomeTreinador);
            trainer1 -> id_trainer = 0;
            InicializaPokeLista (&(*trainer1).ListaCapturados);
        } else {
            trainer2 -> QtdPokebolas = pokebolas;
            strcpy ((*trainer2).nome, nomeTreinador);
            trainer2 -> id_trainer = 1;
            InicializaPokeLista (&(*trainer2).ListaCapturados);
        }
        index++;
    }
}

 void MovimentaTreinador (Treinador *trainer , int position[]){
    trainer -> coordenada[0] = position[0];
    trainer -> coordenada[1] = position[1];
}

void CapturaPokemon (Treinador *trainer, Pokemon *poke){
    trainer -> QtdPokebolas--;
    InserePokemon (&(*trainer).ListaCapturados, poke);
}

void RetiraListaTreinador (Treinador *trainer, PokeLista *listacentro){

}

void ImprimeTreinador (Treinador *trainer){
    printf("Id do Treinador: %d\n", (*trainer).id_trainer);
    printf("Nome do treinador: %s\n", (*trainer).nome);
    printf("Coordenadas do treinador: (%d,%d)\n", (*trainer).coordenada[0], (*trainer).coordenada[1]);
    printf("Quantidade de Pokebolas do treinador: %d\n", (*trainer).QtdPokebolas);
    printf("Lista de Pokemons capturados: \n");
    ImprimePokemon(&(*trainer).ListaCapturados);
}

int getIdTreinador (Treinador *trainer){
    return trainer -> id_trainer;
}

