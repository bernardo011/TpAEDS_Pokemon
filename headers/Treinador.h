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

InicializaTreinador(Treinador *trainer);
MovimentaTreinador(Treinador *trainer, int position[2]);
CapturaPokemon(Treinador *trainer, Pokemon *poke);
RetiraListaTreinador(Treinador *trainer, PokeLista *listacentro);
ImprimeTrainador(Treinador *trainer);
getIdTreinador(Treinador *trainer);
getNomeTreinador(Treinador *trainer);

#endif