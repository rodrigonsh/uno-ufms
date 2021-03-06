#include "uno.h"


void show_line(char msg[], int times)
{
    int i;
    printf("\n");
    for (i = 0; i < times; i++)
        printf("%s", msg);
    printf("\n");
}


void embaralha(struct Pilha *baralho)
{
    srand(time(NULL));
    size_t i;
    if (baralho->topo > 1) 
    {
        for (i = 0; i <= baralho->topo - 1; i++) 
        {
        size_t j = i + rand() / (RAND_MAX / (baralho->topo - i) + 1);
        struct Carta t = baralho->cartas[j];
        baralho->cartas[j] = baralho->cartas[i];
        baralho->cartas[i] = t;
        }
    }
}


void gera_cartas(struct Pilha *baralho)
{
	int i, j;
	baralho->topo = 0;
    char cores[4] = {'R', 'G', 'B', 'Y'},especiais[3] = {'I', 'P', '+'};
    //Gera as cartas numéricas
    for (i = 0; i < 10; i++)
        for (j = 0; j < 4; j++)
        {
            struct Carta nova = {i + '0', cores[j]};
            baralho->cartas[baralho->topo++] = nova;
            if(i > 0)
                baralho->cartas[baralho->topo++] = nova;
        }
    //Gera as cartas de ação
    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++)
        {
            struct Carta nova = {especiais[i], cores[j]};
            baralho->cartas[baralho->topo++] = nova;
            baralho->cartas[baralho->topo++] = nova;
        }
    //Gera as cartas coringa e coringa +4
    for (i = 0; i < 4; i++)
    {
        struct Carta coringa4 = {'4', 'C'}, coringa0 = {'0', 'C'};
        baralho->cartas[baralho->topo++] = coringa4;
        baralho->cartas[baralho->topo++] = coringa0;
    }
}


void mostra_cartas(struct Carta cartas[], int t)
{
    int i;
    for (i = 1; i <= t; i++)
    {
        printf("(%c - %c [%02d])\t", cartas[i-1].cor, cartas[i-1].valor, i-1);
        if(i % 4 == 0)
            printf("\n\n");
    }
}


void distribui_cartas(struct Pilha *baralho, struct Jogador jogadores[], int n_jogadores)
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
            jogadores[j].mao[(jogadores[j].n_cartas)++] = baralho->cartas[--(baralho->topo)];
        }
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


int verifica(struct Carta jogada, struct Carta pilha)
{
	if(pilha.cor == jogada.cor)
		return 1;
	else if(pilha.valor == jogada.valor)
		return 1;
	else
		return 0;
}


void compra(struct Jogador *jogador, struct Pilha *baralho, int quant)
{
	int i;
	for(i = 0; i < quant; i++)
	{
		jogador->mao[jogador->n_cartas++] = baralho->cartas[--baralho->topo];
	}
}


int set_players(struct Jogador jogadores[])
{
    char op = 's';
    int i = 0, n_jogadores = 0;
    show_line("=-", 40);
    printf("CADASTRAR JOGADORES");
    show_line("-=", 40);
    for (i = 0; i < 10; i++)
    {
        if(n_jogadores >= 2)
            while(1)
            {
                printf("\nDeseja continuar ?(s/n)\n");
                scanf("%c", &op);
                if(op == 's' || op == 'n')
                    break;
                else
                    printf("\nOpcao Invalida !!!!\n");
            }
        if(op == 's')
        {
            show_line("-=", 40);
            printf("Apelido jogador [%d]>> ", n_jogadores+1);
            scanf(" %[^\n]s", &jogadores[i].nick_name);
            fflush(stdin);
            n_jogadores++;
            show_line("-=", 40);
        }
        else
            break;
    }
    return n_jogadores;
}














