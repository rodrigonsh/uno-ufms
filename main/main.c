#include "uno.h"
#define size 108
//Compilar usandoo caomando >>> gcc -o uno main.c uno.c
int n_jogadores;
struct Pilha baralho, jogo;
struct Jogador jogadores[10];

int main(int argc, char const *argv[])
{
	int i;
	n_jogadores = 2;
	gera_cartas(&baralho);
	embaralha(&baralho);
	distribui_cartas(&baralho ,jogadores, n_jogadores);
	for (i = 0; i < n_jogadores; i++)
	{
		printf("\njogador %d\n", i + 1);
		mostra_cartas(jogadores[i].mao, jogadores[i].n_cartas);
	}
	return 0;
}
