#include "PokeCenter.h"
#include "PokeLista.h"
#include "Pokemon.h"
#include <stdio.h>

int main (){
    PokeCenter NovoPokeCenter;
    InicializaPokeCenter (&NovoPokeCenter);
    OrdenaSelectionSort (&NovoPokeCenter);
    ImprimePokeLista (&NovoPokeCenter.Pokemons);
    return 0;
}