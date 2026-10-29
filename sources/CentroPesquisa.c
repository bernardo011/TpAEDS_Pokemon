#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CentroPesquisa.h"

// A inicialização do Centro de Pesquisas consiste em inicializar as duas listas dentro dele usando a função InicializaLista.
void InicializaCentroPesquisa (CentroPesquisa *cp){
    InicializaLista(&cp->EstoquePokemon);
};

/* A função InsereFugitivos "pula" as duas primeiras linhas não nulas do arquivo usando um loop for e um fscanf
que guarda uma string e um inteiro duas vezes. Isso é feito para ignorar as linhas dos treinadores.
*/
int InserePokemonEntrada (CentroPesquisa *cp){
    FILE *arq = fopen("teste1.txt", "r");
    if (arq==NULL){
        printf("Arquivo nulo");
    }else{
        int id = 0;
        char nome[50];
        char tipo[50];
        int pokeball;
        int total_pokemons;
        int total_energia;
        int dex;
        int poder;
        int energia;
        Pokemon Greninja;

        for (int i = 0; i<2; i++){
            (fscanf (arq, "%49s", nome) == 2);   
        }
        /* Após as duas primeiras linhas não nulas, lê o próximo número inteiro que informa o total de pokémons fugitivos.
        */
        fscanf (arq, "%d", &total_pokemons);
        fscanf (arq, "%d", &total_energia);
        cp -> total_pokemons = total_pokemons;
        cp -> total_energia = total_energia;
        /* Enquanto a função fscanf retornar 5 valores lidos, o loop while inicializa o Pokémon lido e insere na lista de
        fugitivos.
        */
        while (fscanf (arq, "%d %s %s %d %d", &dex, nome, tipo, &poder, &energia) == 5){
            InicializaPokemon(&Greninja, id, dex, nome, tipo, poder, energia);
            InserePokemon(&cp->EstoquePokemon, &Greninja);
            id++;
        }
        fclose(arq);
        if (total_pokemons == 0){
            return 0;
        } else {
            return 1;
        }
    };

};

