#include "PokeCenter.h"
#include "Pokemon.h"
#include "PokeLista.h"
#include <stdio.h>
#include <time.h>

void InicializaPokeCenter (PokeCenter *NovoPokeCenter){
    FILE *arq;
    arq = fopen ("teste.txt", "r");
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo de entrada.\n");
    } else {
        // Insere os pokémons no vetor caso o número total de pokémons não exceda 10000.
        InicializaPokeLista (&NovoPokeCenter -> Pokemons);
        Pokemon Lucario;
        int poder, pokedex;
        char nome[50];
        char tipo[50];
        fscanf(arq, "%d", &NovoPokeCenter -> TotalPokemons);
        if (NovoPokeCenter -> TotalPokemons > 100000){
            printf("O número de pokémons no arquivo de entrada excede a capacidade máxima do algoritmo (10.000).\n");
        } else {
            while (fscanf(arq, "%d %s %s %d", &pokedex, nome, tipo, &poder) == 4){
                InicializaPokemon (&Lucario, pokedex, nome, tipo, poder);
                InserePokemon (&NovoPokeCenter -> Pokemons, &Lucario);
            }
        }
        fclose (arq);
    }
}

void OrdenaSelectionSort (PokeCenter *NovoPokeCenter){
    // Ordenação simples feita com Selection Sort
    if (PokeListaEVazia(&NovoPokeCenter -> Pokemons))
        return;
    else {
        clock_t inicio, fim;
        double tempo_total;
        inicio = clock();
        for (int i = 0; i < NovoPokeCenter -> Pokemons.Ultimo - 1       ; i++){
            int menor = i;
            for (int j = i+1; j<NovoPokeCenter -> Pokemons.Ultimo; j++){
                if (NovoPokeCenter -> Pokemons.MochilaPokemon[j].poder < NovoPokeCenter -> Pokemons.MochilaPokemon[menor].poder){
                    menor = j;
                }  
            }
            Pokemon aux = NovoPokeCenter -> Pokemons.MochilaPokemon[menor];
            NovoPokeCenter -> Pokemons.MochilaPokemon[menor] = NovoPokeCenter -> Pokemons.MochilaPokemon[i];
            NovoPokeCenter -> Pokemons.MochilaPokemon[i] = aux;  
        }
        fim = clock();
        tempo_total = (double)(fim-inicio)/CLOCKS_PER_SEC;
        printf("\nTempo de execução %f segundos\n", tempo_total);
    }
}