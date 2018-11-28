#ifndef UNO_H_
#define UNO_H_
#include <stdlib.h>
#include <stdio.h>

//Definição da estrutura que representa uma carta
struct Carta
{
	char valor;
	char cor;
};

struct Jogador
{
	char nick_name[16];
	int ind_jogador;
	int n_cartas;
 	struct Carta mao[30];
};

//Embaralha o deck de cartas
void shuffle(struct Carta array[], size_t n);

// Aqui rola uma geração de deck com todas as cartas
void gera_deck(struct Carta baralho[], int size);

// Aqui mostra todo o deck
void mostra_deck(struct Carta baralho[], int size);

//distribui as cartas
int distribui_cartas(struct Carta baralho[], int topo, struct Jogador jogadores[], int n_jogadores); 

//Identifica se acarta tem cor
int id_carta(struct Carta carta);

#endif
