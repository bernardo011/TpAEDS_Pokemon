#include <stdio.h>
#include <stdlib.h>
#include "CentroPesquisa.h"
#include "Treinador.h"

void Inicializa (CentroPesquisa **cp, Treinador **trainer1, Treinador **trainer2){
    (*cp) = (CentroPesquisa*) malloc (sizeof(CentroPesquisa));
    (*trainer1) = (Treinador*) malloc (sizeof(Treinador));
    (*trainer2) = (Treinador*) malloc (sizeof(Treinador));
}

void RegistroInfo (CentroPesquisa *cp, Treinador *trainer1, Treinador *trainer2){
    InicializaTreinadores (trainer1, trainer2);
    InicializaCentroPesquisa (cp);
}

void Mission (CentroPesquisa *cp, Treinador *traine1, Treinador *trainer2){

}

RetornoCentroPesquisa (CentroPesquisa *cp, Treinador *trainer){

}

ImprimirPokemonsRecuperados (CentroPesquisa *cp){
    
}