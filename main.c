#include <stdio.h>
#include "PokeLista.h"
#include "Pokemon.h"
#include "Treinador.h"

int main(){
    Treinador trainer1;
    Treinador trainer2;
    Lista lista_capturados;
    InicializaTreinadores(&trainer1, &trainer2);
    ImprimeTreinador (&trainer1);
    ImprimeTreinador (&trainer2);
    Pokemon lopunny;
    int id = 5;
    int pokedex = 169;
    char nome[50] = "Lopunny";
    char tipo[50] = "Safada";
    int coordenadas[2] = {1, 2};
    InicializaPokemon(&lopunny, id, pokedex, nome, tipo, coordenadas);
    InserePokemon(&trainer1.ListaCapturados, &lopunny);
    ImprimeTreinador(&trainer1);
    id = 10;
    pokedex = 167;
    char nome_2[50] = "Metagross";
    char tipo_2[50] = "Steel";
    int coordenadas_2[2] = {5, 6};
    InicializaPokemon(&lopunny, id, pokedex, nome_2, tipo_2, coordenadas_2);
    InserePokemon(&trainer1.ListaCapturados, &lopunny);
    ImprimeTreinador(&trainer1);
    return 0;
}