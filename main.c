#include <stdio.h>
#include "function_call.h"
#include "PokeLista.h"
#include "Pokemon.h"
#include "Treinador.h"
#include "CentroPesquisa.h"
#include "TimePokemon.h"
#include <stdlib.h>
#include <time.h>

int main(){
    TimePokemon *MelhorTime;
    Treinador *trainer1, *trainer2;
    CentroPesquisa *poke_center;
    int codigo;
    Inicializa (&poke_center, &trainer1, &trainer2, &MelhorTime, &codigo);
    if (!codigo){
        printf("Não há pokémons no arquivo de entrada!\n");
        free(MelhorTime);
        free(trainer1);
        free(trainer2);
        free(poke_center);
    } else {
        EncontraMelhorEquipe(poke_center, trainer1, trainer2, MelhorTime);
    }
    return 0;
}