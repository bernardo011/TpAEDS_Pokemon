#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CentroPesquisa.h"

void InicializaCentroPesquisa (CentroPesquisa *cp){
    InicializaLista(&cp->PokemonsFugitivos);
    InicializaLista(&cp->PokemonsRecuperados);
};

void InsereFugitivos (CentroPesquisa *cp){
    FILE *arq = fopen("teste2.txt", "r");
    if (arq==NULL){
        printf("Arquivo nulo");
    }else{
        char linha[256];
        int linha_n_nula=0;
        while(fgets(linha, sizeof linha, arq)!=NULL){
            if(linha[0]=='\n'||linha[0]=='\r'||linha[0]=='\0'){
                continue;
            }else{
                linha_n_nula++;
                if(linha_n_nula==2){
                    int total;
                    fscanf(arq, "%d", &total);
                    (*cp).total = total;
                    int id=0;
                    int dex;
                    char nome[50];
                    char tipo[50];
                    int x;
                    int y;
                    Pokemon Greninja;
                    for(int i=0; i<total; i++){
                        fscanf(arq, "%d %s %s %d %d", &dex, &nome, &tipo, &x, &y);
                        InicializaPokemon(&Greninja, id, dex, nome, tipo, x, y);
                        InserePokemon(&cp->PokemonsFugitivos, &Greninja);
                        id++;
                    };
                };
            };
        };
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