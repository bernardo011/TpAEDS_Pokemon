#include <stdio.h>
#include <string.h>
#include "Treinador.h"

void InicializaTreinadores(Treinador *trainer1, Treinador *trainer2){
    FILE *p;
    p = fopen("teste2.txt", "r");
    if (p == NULL){
        printf("Ponteiro vazio\n");
    } else {
        int index = 0;
        char nomeTreinador[50];
        int pokebolas;
        while (fscanf(p, "%49s %d", nomeTreinador, &pokebolas) == 2){
            if (index == 0){
                trainer1 -> QtdPokebolas = pokebolas;
                strcpy ((*trainer1).nome, nomeTreinador);
                trainer1 -> id_trainer = 1;
                InicializaPokeLista (&((*trainer1).ListaCapturados));
                trainer1 -> coordenada_treinador[0] = 0;
                trainer1 -> coordenada_treinador[1] = 0;
            } else if (index == 1){
                trainer2 -> QtdPokebolas = pokebolas;
                strcpy ((*trainer2).nome, nomeTreinador);
                trainer2 -> id_trainer = 2;
                trainer2 -> coordenada_treinador[0] = 0;
                trainer2 -> coordenada_treinador[1] = 0;
                InicializaPokeLista (&((*trainer2).ListaCapturados));
            }
            index++;
    }
}
}

 void MovimentaTreinador (Treinador *trainer , int position[]){
    trainer -> coordenada_treinador[0] = position[0];
    trainer -> coordenada_treinador[1] = position[1];
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
    printf("Coordenadas do treinador: (%d,%d)\n", (*trainer).coordenada_treinador[0], (*trainer).coordenada_treinador[1]);
    printf("Quantidade de Pokebolas do treinador: %d\n", (*trainer).QtdPokebolas);
    printf("Lista de Pokemons capturados: \n");
    if (ListaEVazia(&((*trainer).ListaCapturados))){
        printf("O treinador não possui pokemons no momento\n");
    } else {
        ImprimePokemons(&((*trainer).ListaCapturados));
    }
}

int getIdTreinador (Treinador *trainer){
    return trainer -> id_trainer;
}

void getCoordenadaTreinador (Treinador *trainer, int coordenada_treinador[]){
    coordenada_treinador[0] = trainer-> coordenada_treinador[0];
    coordenada_treinador[1] = trainer-> coordenada_treinador[1];
}

void getNomeTreinador (Treinador *trainer, char nome_treinador[]){
    strcpy(nome_treinador, (*trainer).nome);
}

int getPokebolasTreinador (Treinador *trainer){
    return trainer -> QtdPokebolas;
}

void setPokebolasTreinador (Treinador *trainer, int pokebolas){
    trainer -> QtdPokebolas = pokebolas;
}