#ifndef UNO_H_
#define UNO_H_
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

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


//Embaralha o deck de cartas
void shuffle(struct Pilha *baralho);

// Aqui rola uma geração de deck com todas as cartas
void gera_deck(struct Pilha *baralho);

// Aqui mostra todo o deck
void mostra_deck(struct Pilha *baralho);

//distribui as cartas
void distribui_cartas(struct Pilha *baralho, struct Jogador jogadores[], int n_jogadores); 

//Identifica se acarta tem cor
int id_carta(struct Carta carta);

//joga carta
struct Carta joga_carta(struct Jogador *jogador, int index);

//verifc se a jogada é válida
int verifica(struct Carta jogada, struct Carta pilha);

//compra cartas
int compra(struct Jogador *jogador, struct Carta baralho[], int topo, int quant);


//verificar se a pilha da jogo esta cheia
int verificarseestacheia(struct Pilha*p);

// Se a carta do jogo estiver cheia,desempilha
void desempilhar(struct Pilha *p);

//Verifica se o jogador tem um carta x
int verifica(struct Jogador jogador, struct Carta x);
 
#endif
