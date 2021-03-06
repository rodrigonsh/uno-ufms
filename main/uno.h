#ifndef UNO_H_
#define UNO_H_
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

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
 	struct Carta mao[102];
};

struct Pilha
{
	int topo;
	struct Carta cartas[108];
};

//imprime linhas
void show_line(char msg[], int times);

//Embaralha o deck de cartas
void embaralha(struct Pilha *baralho);

// Aqui rola uma geração de deck com todas as cartas
void gera_cartas(struct Pilha *baralho);

// Aqui mostra todo o deck
void mostra_cartas(struct Carta cartas[], int t);

//distribui as cartas
void distribui_cartas(struct Pilha *baralho, struct Jogador jogadores[], int n_jogadores); 

//Identifica se acarta tem cor
int id_carta(struct Carta carta);

//joga carta
struct Carta joga_carta(struct Jogador *jogador, int index);

//verifc se a jogada é válida
int verifica(struct Carta jogada, struct Carta pilha);

//compra cartas
void compra(struct Jogador *jogador, struct Pilha *baralho, int quant);

//recebe o jogadores para comecar o jogo
int set_players(struct Jogador jogadores[]);

#endif
