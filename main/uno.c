#include "uno.h"

void shuffle(struct Carta array[], size_t n)
{
  size_t i;
  if (n > 1) 
  {
    for (i = 0; i <= n - 1; i++) 
    {
      size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
      struct Carta t = array[j];
      array[j] = array[i];
      array[i] = t;
    }
  }
}


void gera_deck(struct Carta baralho[], int size)
{
	int i, j, carta_atual = 0;
    char cores[4] = {'R', 'G', 'B', 'Y'},especiais[3] = {'I', 'P', '+'};
    //Gera as cartas numéricas
    for (i = 0; i < 10; i++)
        for (j = 0; j < 4; j++)
        {
            struct Carta nova = {i + '0', cores[j]};
            baralho[carta_atual] = nova;
            carta_atual++;

            if(i > 0)
            {
                baralho[carta_atual] = nova;
                carta_atual++;   
            }
        }
    //Gera as cartas de ação
    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++)
        {
            struct Carta nova = {especiais[i], cores[j]};
            baralho[carta_atual] = nova;
            carta_atual++;
            
            baralho[carta_atual] = nova;
            carta_atual++;
        }
    //Gera as cartas coringa e coringa +4
    for (i = 0; i < 4; i++)
    {
        struct Carta coringa4 = {'C', '4'}, joker = {'J', 'W'};

        baralho[carta_atual] = coringa4;
        carta_atual++;
   
        baralho[carta_atual] = joker;
        carta_atual++;
    }
}

void mostra_deck(struct Carta baralho[], int size)
{
    int i;
    printf("=====\n");
    for (i = 0; i < size; i++)
    {
        printf("%c - %c\n", baralho[i].cor, baralho[i].valor);
        printf("=====\n");
    }
}


int distribui_cartas(struct Carta baralho[], int topo, struct Jogador jogadores[], int n_jogadores)
{
	int i, j;
	do{
		if(n_jogadores < 2 || n_jogadores > 10)
		{
			printf("Erro redefina o numero de jogadores !!!\n");
			scanf("%d", &n_jogadores);
		}
	}while(n_jogadores < 2 || n_jogadores > 10);

	for(j = 0; j < n_jogadores; j++)
		{
			jogadores[j].n_cartas = 0;
			jogadores[j].ind_jogador = j+1;
		}

	for(i = 0; i < 7; i++)
	{
		for(j = 0; j < n_jogadores; j++)
		{
			jogadores[j].mao[jogadores[j].n_cartas++] = baralho[topo--];
		}
	}
	return topo;
}






























