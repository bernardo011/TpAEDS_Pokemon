#include <stdio.h>
#include "headers/function_call.h"
#include "headers/PokeLista.h"
#include "headers/Pokemon.h"
#include "headers/Treinador.h"
#include "headers/CentroPesquisa.h"
#include <windows.h>
#include "stdlib.h"

int main(){
    SetConsoleOutputCP(65001); 
    CentroPesquisa *poke_center;
    Treinador *trainer1, *trainer2;
    Inicializa (&poke_center, &trainer1, &trainer2);
    AtribuiMission (&poke_center, &trainer1, &trainer2);
    free(trainer1);
    free(trainer2);
    free(poke_center);
    return 0;
}
