#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/CentroPesquisa.h"

// A inicialização do Centro de Pesquisas consiste em inicializar as duas listas dentro dele usando a função InicializaLista.
void InicializaCentroPesquisa (CentroPesquisa *cp){
    InicializaLista(&cp->PokemonsFugitivos);
    InicializaLista(&cp->PokemonsRecuperados);
};

/* A inserção dos pokémons fugitivos é feita através de um loop while que ignora as duas primeiras linhas não nulas
do arquivo de teste e depois lê um inteiro referente a quantidade de pokémons fugitivos 
*/
void InsereFugitivos (CentroPesquisa *cp){
    FILE *arq = fopen("teste1.txt", "r");
    if (arq==NULL){
        printf("Arquivo nulo");
    }else{
        int id = 0;
        char nome[50];
        char tipo[50];
        int pokeball;
        int total;
        int dex;
        int x;
        int y;
        Pokemon Greninja;
        for (int i = 0; i<2; i++){
            (fscanf (arq, "%49s %d", nome, &pokeball) == 2);
        } 
        fscanf (arq, "%d", &total);
        while (fscanf (arq, "%d %s %s %d %d", &dex, nome, tipo, &x, &y) == 5){
            InicializaPokemon(&Greninja, id, dex, nome, tipo, x, y);
            InserePokemon(&cp->PokemonsFugitivos, &Greninja);
            id++;
        }
    };
    fclose(arq);
};

int RemovePokemonFugitivo (Lista *lista){
        if (ListaEVazia(lista)){
            return 0;
        }
        PokeLista *aux = lista -> Primeiro;
        (*lista).Primeiro = (*lista).Primeiro -> pProx;
        free(aux);
}

void RecargaPokebolas (int *x){
    *x = (rand()%20)+1;
};