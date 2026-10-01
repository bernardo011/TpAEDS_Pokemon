#include <stdio.h>
#include "function_call.h"
#include "PokeLista.h"
#include "Pokemon.h"
#include "Treinador.h"
#include "CentroPesquisa.h"
#include "stdlib.h"

int main(){
    // Cria os ponteiros que terão um endereço de memória dinâmicamente alocado pela função Inicializa
    CentroPesquisa *poke_center;
    Treinador *trainer1, *trainer2;
    // Atribui um endereço de memória as variáveis criadas e dá início a missão.
    Inicializa (&poke_center, &trainer1, &trainer2);
    // Atribui as missões sucessivamentes até que a lista de pokémons fugitivos esteja vazia
    AtribuiMission (&poke_center, &trainer1, &trainer2);
    free(trainer1);
    free(trainer2);
    free(poke_center);
    return 0;
}