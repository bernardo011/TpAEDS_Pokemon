#include "../headers/function_call.h"
#include "../headers/CentroPesquisa.h"
#include "../headers/PokeLista.h"
#include "../headers/Pokemon.h"
#include "../headers/Treinador.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void Mission (Treinador *trainer, CentroPesquisa *poke_center, double dist1, double dist2){
    printf("Pokémon alvo: %s \n", (*poke_center).PokemonsFugitivos.Primeiro->pokemon.nome);
    printf("Localização: (%d, %d) \n\n", (*poke_center).PokemonsFugitivos.Primeiro->pokemon.coordenadas[0], (*poke_center).PokemonsFugitivos.Primeiro->pokemon.coordenadas[1]);
    printf("Distância Treinador (a) Rosa: %.2lf \n", dist1);
    printf("Distância Treinador (a) Nate: %.2lf \n\n", dist2);
    printf("Missão atribuída ao Treinador (a) %s \n\n", (*trainer).nome);
    MovimentaTreinador (trainer, (*poke_center).PokemonsFugitivos.Primeiro->pokemon.coordenadas);
    printf("Treinador (a) se movimentou para (%d,%d)\n", (*trainer).coordenada_treinador[0], (*trainer).coordenada_treinador[1]);
    CapturaPokemon (trainer, &(*poke_center).PokemonsFugitivos.Primeiro->pokemon);
    printf("%s capturado com sucesso!\n\n", (*poke_center).PokemonsFugitivos.Primeiro->pokemon.nome);
    RemovePokemonFugitivo (&(*poke_center).PokemonsFugitivos);
    printf("Pokébolas restantes para o Treinador (a) %s: %d \n\n", (*trainer).nome, (*trainer).QtdPokebolas);
    if ((*trainer).QtdPokebolas == 0){
        printf("========================================\n");
        printf("    Treinador (a) %s SEM POKÉBOLAS      \n", (*trainer).nome);
        printf("========================================\n\n");
        RetornaCentroPesquisa (trainer, poke_center);
        printf("Treinador (a) %s retornou ao Centro de Pesquisa.\n\n", (*trainer).nome);
        printf("Entregando Pokémon ao Centro de Pesquisa.\n\n");
        printf("Treinador (a) %s recebeu %d Pokébolas.\n\n", (*trainer).nome, (*trainer).QtdPokebolas);
        printf("-----------------------------------------\n");
    } else {
        printf("-----------------------------------------\n");
    }
}

double Distancia (Treinador **trainer1, Pokemon *poke){
    int PosTreinador[2];
    int PosPokemon[2];
    getCoordenadaTreinador (*trainer1, PosTreinador);
    getCoordenadaPoke (poke, PosPokemon);
    double dist = ((PosTreinador[0]-PosPokemon[0])*(PosTreinador[0]-PosPokemon[0]))+((PosTreinador[1]-PosPokemon[1])*(PosTreinador[1]-PosPokemon[1]));
    return sqrt(dist);
}

void Inicializa (CentroPesquisa **poke_center, Treinador **trainer1, Treinador **trainer2){
    CentroPesquisa *aux = (CentroPesquisa*) malloc (sizeof(CentroPesquisa));
    (*poke_center) = aux;
    Treinador *t1 = (Treinador*) malloc (sizeof(Treinador));
    Treinador *t2 = (Treinador*) malloc (sizeof(Treinador));
    (*trainer1) = t1;
    (*trainer2) = t2;
    RegistraDados (trainer1, trainer2, poke_center);
    printf("========================================\n");
    printf("          INÍCIO DA MISSÃO              \n");
    printf("========================================\n\n");
    printf("Treinador(a): %s: posição (%d, %d) | Pokébolas: %d \n", (**trainer1).nome, (**trainer1).coordenada_treinador[0], ((**trainer1).coordenada_treinador[1]), (**trainer1).QtdPokebolas);
    printf("Treinador(a): %s: posição (%d, %d) | Pokébolas: %d \n\n", (**trainer2).nome, (**trainer2).coordenada_treinador[0], ((**trainer2).coordenada_treinador[1]), (**trainer2).QtdPokebolas);
    printf("Pokémons fugitivos a serem resgatados: %d\n\n", (**poke_center).total);
    printf("----------------------------------------\n");
}


void RegistraDados (Treinador **trainer1, Treinador **trainer2, CentroPesquisa **poke_center){
    InicializaTreinadores(*trainer1, *trainer2);
    InicializaCentroPesquisa (*poke_center);
    InsereFugitivos (*poke_center);
}

void AtribuiMission (CentroPesquisa **poke_center, Treinador **trainer1, Treinador **trainer2){
    while ((**poke_center).PokemonsFugitivos.Primeiro){
        double dist1 = Distancia(trainer1, &(**poke_center).PokemonsFugitivos.Primeiro->pokemon);
        double dist2 = Distancia(trainer2, &(**poke_center).PokemonsFugitivos.Primeiro->pokemon);
        if (dist1<dist2){
            Mission (*trainer1, *poke_center, dist1, dist2);
        }
           else if (dist2<dist1){
            Mission (*trainer2, *poke_center, dist1, dist2);
        } else if ((**trainer1).id_trainer<(**trainer2).id_trainer){
            Mission (*trainer1, *poke_center, dist1, dist2);
        } else {
            Mission (*trainer2, *poke_center, dist1, dist2);
        }
    }
    printf("========================================\n");
    printf("    Todos os Pokémons foram resgatados    \n");
    printf("========================================\n\n");
    RetornaCentroPesquisa ((*trainer1), (*poke_center));
    RetornaCentroPesquisa ((*trainer2), (*poke_center));
    printf("Ambos os treinadores retornam ao Centro de Pesquisa.\n\n");
    printf("Treinador (a) %s devolve os Pokémon.\n\n", (**trainer1).nome);
    printf("Treinador (a) %s devolve os Pokémon.\n\n", (**trainer2).nome);
    printf("========================================\n");
    printf("         MISSÃO CONCLUÍDA               \n");
    printf("========================================\n");
    RelatorioFinal ((*poke_center));
}

void RetornaCentroPesquisa (Treinador *trainer, CentroPesquisa *poke_center){
    int PositionPokeCenter[2] = {0, 0};
    MovimentaTreinador (trainer, PositionPokeCenter);
    int randompokebolas;
    RecargaPokebolas(&randompokebolas);
    setPokebolasTreinador (trainer, randompokebolas);
    RemovePokemonTreinador (&(*trainer).ListaCapturados, &(*poke_center).PokemonsRecuperados);
}

void RelatorioFinal (CentroPesquisa *poke_center){
    FILE *p;
    p = fopen("relatorio.txt", "w");
    if (p == NULL){
        printf ("Não foi possível gerar o relatório da missão.");
    } else {
        PokeLista *pointer = (*poke_center).PokemonsRecuperados.Primeiro;
        fprintf(p, "Pokemon recuperados: \n");
        while (pointer){
            fprintf(p, "%d %s\n", (*pointer).pokemon.pokedex, (*pointer).pokemon.nome);
            pointer = (*pointer).pProx;
        }
    }
    fclose(p);
}