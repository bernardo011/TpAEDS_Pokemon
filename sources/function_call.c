#include "function_call.h"
#include "CentroPesquisa.h"
#include "PokeLista.h"
#include "Pokemon.h"
#include "Treinador.h"
#include "TimePokemon.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// Log da missão após a atribuição ter sido feita pela função "AtribuiMission"


void Inicializa (CentroPesquisa **poke_center, Treinador **trainer1, Treinador **trainer2, TimePokemon **MelhorTime, int *codigo){
    // Aloca memória para as variáveis recebidas da main 
    CentroPesquisa *aux = (CentroPesquisa*) malloc (sizeof(CentroPesquisa));
    (*poke_center) = aux;
    Treinador *t1 = (Treinador*) malloc (sizeof(Treinador));
    Treinador *t2 = (Treinador*) malloc (sizeof(Treinador));
    TimePokemon *Maux = (TimePokemon*) malloc (sizeof(TimePokemon));
    (*MelhorTime) = Maux;
    (*trainer1) = t1;
    (*trainer2) = t2;
    // Inicializa os TAD's Treinador e PokeCenter, juntamente de suas listas.
    RegistraDados (trainer1, trainer2, poke_center, MelhorTime, codigo);
}


void RegistraDados (Treinador **trainer1, Treinador **trainer2, CentroPesquisa **poke_center, TimePokemon **MelhorTime, int *codigo){
    // Inicializa os treinadores (lendo o arquivo) e suas respectivas listas. Inicializa as listas do PokeCenter.
    InicializaTreinadores(*trainer1, *trainer2);
    InicializaCentroPesquisa (*poke_center);
    InicializaLista(&(*MelhorTime)->MelhorTime);
    (*MelhorTime)->poder = 0;
    (*MelhorTime)->energia = 0;
    (*codigo) = InserePokemonEntrada (*poke_center);
}

void GerarCombinacoes (int vetor[], int start, int n, int k, int maxk, PokeLista *EstoquePokemon, int energia_total, TimePokemon *MelhorTime, int *count){
    if (k>maxk){
        VerificaTime(vetor, maxk, EstoquePokemon, energia_total, MelhorTime);
        (*count)++;
        return ;
    }
    for (int i = start; i<=n; i++){
        vetor[k] = i;
        GerarCombinacoes(vetor, i+1, n, k+1, maxk, EstoquePokemon, energia_total, MelhorTime, count);
    }
}

int DivideLista (CentroPesquisa *poke_center, Treinador *trainer1, Treinador *trainer2, TimePokemon *MelhorTime){
    if (poke_center->total_pokemons == 0){
        return 0;

    } else if (poke_center->total_pokemons == 1){
        InserePokemon(&trainer2->TimeTreinador, &MelhorTime->MelhorTime.Primeiro->pokemon);
        return 1;
    }
    PokeCelula *aux = MelhorTime->MelhorTime.Primeiro;
    int index = 1;
    while(aux){
        if (index%2 == 0){
            InserePokemon(&trainer1->TimeTreinador, &aux->pokemon);
        } else {
            InserePokemon(&trainer2->TimeTreinador, &aux->pokemon);
        }
        aux = aux->pProx;
        index++;
    }
    if (index == 2){
        return 1;
    } else {
        return 2;
    }
}

void EncontraMelhorEquipe (CentroPesquisa *poke_center, Treinador *trainer1, Treinador *trainer2, TimePokemon *BestTeam){
    printf("... Pokémon Carregados ...\n");
    ImprimePokemons(&poke_center->EstoquePokemon);
    printf("\n");
    int *v;
    v = (int*) malloc (((*poke_center).total_pokemons+1) * sizeof(int));
    int count = 0;
    clock_t inicio, fim;
    double tempo_total;
    inicio = clock();
    printf("=== Executando seleção de Pokémon (Força bruta) ===\n");
    printf("\n");
    for (int i = 0; i<=(*poke_center).total_pokemons; i++){
        GerarCombinacoes(v, 1, (*poke_center).total_pokemons+1, 1, i, &poke_center->EstoquePokemon, (*poke_center).total_energia, BestTeam, &count);
    }
    fim = clock();
    tempo_total = (double)(fim-inicio)/CLOCKS_PER_SEC;
    if (ExibeMelhorEquipe(trainer1, trainer2, BestTeam, tempo_total, poke_center)){
        int codigo = DivideLista(poke_center, trainer1, trainer2, BestTeam);
        switch (codigo){
        case 0:
            ExibeEquipeTreinadores(trainer1, trainer2, 0);
            break;
        case 1:
            ExibeEquipeTreinadores(trainer1, trainer2, 1);
            break;
        case 2:
            ExibeEquipeTreinadores(trainer1, trainer2, 2);
            break;
        default:
            ExibeEquipeTreinadores(trainer1, trainer2, 3);
    }
        EsvaziaPokeLista(&poke_center->EstoquePokemon);
        EsvaziaPokeLista(&(*BestTeam).MelhorTime);
        EsvaziaPokeLista(&trainer2->TimeTreinador);
        EsvaziaPokeLista(&trainer1->TimeTreinador);
    } else {
        EsvaziaPokeLista(&poke_center->EstoquePokemon);
    }
    free(v);
    free(BestTeam);
    free(poke_center);
    free(trainer1);
    free(trainer2);
}

int ExibeMelhorEquipe (Treinador *trainer1, Treinador *trainer2, TimePokemon *MelhorTime, double tempo_total, CentroPesquisa *poke_center){
    if (ListaEVazia(&MelhorTime->MelhorTime)){
        printf("Não foi possível formar nenhuma equipe com %d de energia.\n", poke_center->total_energia);
        return 0;
    } else {
        printf("=== Melhor equipe encontrada ===\n");
        printf("Poder total: %d\n", MelhorTime->poder);
        printf("Energia total consumida: %d/%d\n", MelhorTime->energia, poke_center->total_energia);
        printf("\nTempo de execução %f segundos\n", tempo_total);
        printf("\n");
        printf("Pokémon Selecionados para a equipe:\n");
        ImprimePokemons(&MelhorTime->MelhorTime);
        printf("\n");
        return 1;
    }
}

void ExibeEquipeTreinadores (Treinador *trainer1, Treinador *trainer2, int codigo){
    switch (codigo){
        case 0:
        printf("\nNÃO HÁ POKÉMONS NO ARQUIVO DE TESTE PARA FORMAR EQUIPES!\n");
        break;
        case 1:
        printf("=== Equipes dos treinadores ===\n");
        printf("Treinador 1: %s\n", trainer1->nome);
        printf("Mochila do treinador:\n");
        ImprimePokemons(&trainer2->TimeTreinador);
        break;
        case 2:    
        printf("=== Equipes dos treinadores ===\n");
        printf("Treinador 1: %s\n", trainer1->nome);
        printf("Mochila do treinador:\n");
        ImprimePokemons(&trainer1->TimeTreinador);
        printf("\n"); 
        printf("Treinador 2: %s\n", trainer2->nome);
        printf("Mochila do treinador:\n");
        ImprimePokemons(&trainer2->TimeTreinador);
        break;
        default:
            printf("NÃO FOI POSSÍVEL FORMAR EQUIPES.\n");
    }
}


