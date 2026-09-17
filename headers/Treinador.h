#ifndef TREINADOR_H
#define TREINADOR_H

typedef struct pokelista PokeLista;
typedef struct pokemon Pokemon;

typedef struct treinador {
    int id_trainer;
    char nome[50];
    int coordenada[2];
    PokeLista ListaCapturados;
    int QtdPokebolas;

} Treinador;

void InicializaTreinadores(Treinador *trainer1, Treinador *trainer2, FILE *p);
void MovimentaTreinador(Treinador *trainer, int position[]);
void CapturaPokemon(Treinador *trainer, Pokemon *poke);
void RetiraListaTreinador(Treinador *trainer, PokeLista *listacentro);
void ImprimeTreinador(Treinador *trainer);
int getIdTreinador(Treinador *trainer);

#endif