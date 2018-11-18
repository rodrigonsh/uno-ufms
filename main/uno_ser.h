#ifndef UNO_SER_H_
#define UNO_SER_H_
#include <stdlib.h>
#include <stdio.h>

//Definição da estrutura que representa uma carta
struct Carta
{
  char valor;
  char cor;
};

//Embaralha o deck de cartas
void shuffle(struct Carta array[], size_t n);

// Aqui rola uma geração de deck com todas as cartas
void gera_deck(struct Carta baralho[], int size);

// Aqui mostra todo o deck
void mostra_deck(struct Carta baralho[], int size);

#endif