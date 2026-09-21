#include <stdio.h>
#include "function_call.h"
#include "PokeLista.h"
#include "Pokemon.h"
#include "Treinador.h"
#include "CentroPesquisa.h"

int main(){
    CentroPesquisa *poke_center;
    Treinador *trainer1, *trainer2;
    Inicializa (&poke_center, &trainer1, &trainer2);
    AtribuiMission (&poke_center, &trainer1, &trainer2);
    return 0;
}