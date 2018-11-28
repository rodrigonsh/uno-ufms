#include "uno.h"
#define size 108

int topo;
/*
Exemplos
"5B" // 5 Blue
"+G" // +2 Green
"JW" // Joker
"IY" // Inversao Yellow
"C4" // Joker 4 Cartas
"PR" // Pulante (Bloqueio, perde a vez) Red
"uno"// aviso de uma carta

Compilar usando > > > gcc -o uno main.c uno.c
*/

int main(int argc, char const *argv[])
{
	int n_jogadores, i;
	struct Carta baralho[size];
	struct Jogador jogadores[10];
	//Gera as cartas
	gera_deck(baralho, size);
	//Embaralha as cartas
	shuffle(baralho, size);
	//distribuir cartas
	printf("Quantos jogadores ?");
	scanf("%d", &n_jogadores);
  	topo = size - 1;
	topo = distribui_cartas(baralho, topo, jogadores, n_jogadores);
	for(i = 0; i < n_jogadores; i++)
	{
		printf("\n\nJogador n %d\n", jogadores[i].ind_jogador);
		printf("============================================\n");
		mostra_deck(jogadores[i].mao, jogadores[i].n_cartas);
	}
	printf("\n==================BARALHO==================\n");
	mostra_deck(baralho, topo);
	return 0;
}
