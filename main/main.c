#include "uno_ser.h"
#define size 108
 /*
 Exemplos
  "5B" // 5 Blue
  "+G" // +2 Green
  "JW" // Joker
  "IY" // Inversao Yellow
  "C4" // Joker 4 Cartas
  "PR" // Pulante (Bloqueio, perde a vez) Red
   "uno"// aviso de uma carta
   */
/*Compilar usando
gcc -o uno main.c uno_ser.c*/

int main(int argc, char const *argv[])
{
  struct Carta baralho[size];
  //Gera as cartas
  gera_deck(baralho, size);
  //Embaralha as cartas
  shuffle(baralho, size);
  //Mostra todas as cartas
  mostra_deck(baralho, size);
  return 0;
}
