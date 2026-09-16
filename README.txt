Parte do Bernardo:
TAD's Treinador e PokeLista;

Funções do TAD Treinador:

InicializaTreinador(Treinador *trainer); (Vou utilizar as funções get e set dos campos Id e Nome
para preencher os campos correspondentes. A localização inicial é sempre 0,0. Para inicializar a Poke-
Lista, vou utilizar a função InicializaPokeLista. Para a definição da quantidade de Pokebolas, vou
precisar do retorno da função getPokebolas)

MovimentaTreinador(Treinador *trainer, int position[2]); (Essa função vai ser utilizada sempre que 
houver uma nova captura ou quando acabarem os pokébolas ou pokémons. A próxima posição de um treinador 
será sempre a posição do seu pokémon alvo ou (0,,0) caso ele esteja indo para o Centro de Pesquisa.)

CapturaPokemon(Treinador *trainer, Pokemon *poke, PokeLista *lista); (Essa função é ativada sempre que uma missão for
direcionada ao treinador. Ela copia os dados do pokémon alvo para a lista de pokémons do treinador e
remove o primeiro pokémon da lista de pokémons fugitivos do centro de pesquisa.)

RetiraListaTreinador(Treinador *trainer, PokeLista *listacentro);
ImprimeTrainador(Treinador *trainer);
getIdTreinador(Treinador *trainer);
getNomeTreinador(Treinador *trainer);

#endif