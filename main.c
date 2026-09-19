#include <stdio.h>
#include "PokeLista.h"
#include "Pokemon.h"
#include "Treinador.h"

int main(){
    Treinador trainer1;
    Treinador trainer2;
    Lista lista_capturados;
    Lista poke_center;
    Lista fugitivos;
    InicializaLista(&poke_center);
    InicializaTreinadores(&trainer1, &trainer2);
    Pokemon lopunny;
    int id = 5;
    int pokedex = 169;
    char nome[50] = "Lopunny";
    char tipo[50] = "Safada";
    int coordenadas[2] = {1, 2};
    InicializaPokemon(&lopunny, id, pokedex, nome, tipo, coordenadas);
    InserePokemon(&trainer1.ListaCapturados, &lopunny);
    id = 10;
    pokedex = 167;
    char nome_2[50] = "Metagross";
    char tipo_2[50] = "Steel";
    int coordenadas_2[2] = {5, 6};
    InicializaPokemon(&lopunny, id, pokedex, nome_2, tipo_2, coordenadas_2);
    InserePokemon(&trainer1.ListaCapturados, &lopunny);
    ImprimeTreinador (&trainer1);
    printf("Centro de pesquisas:\n");
    ImprimePokemons (&poke_center);
    RemovePokemonTreinador (&trainer1.ListaCapturados, &poke_center);
    printf("Centro de pesquisas depois:\n\n");
    ImprimePokemons(&poke_center);
    printf("Centro de Pesquisas depois de remover 1 pokemon: \n\n");
    int res = RemovePokemonFugitivo(&poke_center);
    if (!res){
        printf("Deu não");
    } else {
            ImprimePokemons(&poke_center);
    }
    printf("Centro de Pesquisas depois de remover 2 pokemon: \n\n");
    res = RemovePokemonFugitivo(&poke_center);
        if (!res){
        printf("Deu não");
    } else {
            ImprimePokemons(&poke_center);
    }
    printf("Centro de Pesquisas depois de remover 3 pokemon: \n\n");
    res = RemovePokemonFugitivo(&poke_center);
        if (!res){
        printf("Deu não");
    } else {
        ImprimePokemons(&poke_center);
    }

    return 0;
}