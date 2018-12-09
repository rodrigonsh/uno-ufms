#include "uno.h"
#define size 108
//Compilar usandoo caomando >>> gcc -o uno main.c uno.c
int n_jogadores;
struct Pilha baralho, jogo;
struct Jogador jogadores[10];

int main(int argc, char const *argv[])
{
	int i;
	gera_cartas(&baralho);
	embaralha(&baralho);
	n_jogadores = set_players(jogadores);
	distribui_cartas(&baralho,jogadores, n_jogadores);
	for (i = 0; i < n_jogadores; i++)
	{
		show_line("::", 40);
		printf("(n %d)%s", jogadores[i].ind_jogador, jogadores[i].nick_name);
		show_line("::", 40);
		mostra_cartas(jogadores[i].mao, jogadores[i].n_cartas);
	}
	return 0;
}
