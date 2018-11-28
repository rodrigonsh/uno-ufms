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
    for (i = 1; i <= size; i++)
    {
        printf("(%c - %c [%02d])\t", baralho[i-1].cor, baralho[i-1].valor, i-1);
        if(i % 3 == 0)
            printf("\n\n");
    }
}


int distribui_cartas(struct Carta baralho[], int topo, struct Jogador jogadores[], int n_jogadores)
{
	int i, j;
	if(n_jogadores < 2 || n_jogadores > 10)
    {
        printf("Numero invalido de jogadores !!!!");
        exit(EXIT_FAILURE);
    }

    for(j = 0; j < n_jogadores; j++)
		{
			jogadores[j].n_cartas = 0;
			jogadores[j].ind_jogador = j+1;
		}

	for(i = 0; i < 7; i++)
		for(j = 0; j < n_jogadores; j++)
		{
			jogadores[j].mao[jogadores[j].n_cartas++] = baralho[topo--];
		}

	return topo;
}


int id_carta(struct Carta carta)
{   
    if(carta.cor == 'R'|| carta.cor == 'G'||carta.cor == 'Y'|| carta.cor == 'B')
        if(isdigit(carta.valor))
            return 0;
        else
            return 1;
    else
        return 2;
}


struct Carta joga_carta(struct Jogador *jogador, int index)
{
	struct Carta aux = jogador->mao[index];
	int i;
	jogador->n_cartas--;
	if(index == jogador->n_cartas)
	{
		return aux;
	}
	else
	{
		for(i = index; i < jogador->n_cartas; i++)
			jogador->mao[i] = jogador->mao[i+1];
		return aux;
	}
}



















