// Este é o código do sevidor

#include <stdio.h>

int main(){
  int carta_atual = 0;
  
  /*
  "5B" // 5 Blue
  "+G" // +2 Green
  "JW" // Joker
  "IY" // Inversao Yellow
  "C4" // Joker 4 Cartas
  "PR" // Pulante (Bloqueio, perde a vez) Red
  */

  struct Carta{
    char valor;
    char cor;
  };

  char cores[4] = {'R', 'G', 'B', 'Y'};
  char especiais[3] = {'I', 'P', '+'};

  struct Carta baralho[108];




// Aqui rola uma geração de deck com todas as cartas
  int cartaAtual = 0;
  int i,j;
  for(i=0; i<= 9; i++)
  {

    for(j=0;j<4; j++)
    {
      struct Carta nova = {i+'0', cores[j]};
      baralho[cartaAtual] = nova;
      cartaAtual++;

      if (i > 0)
      {
        baralho[cartaAtual] = nova;
        cartaAtual++;
      }
    }
  }

  // Criar cartas especiais
  for(i=0; i<=3; i++)
  {
    for(j=0;j<4; j++)
      {
        struct Carta nova = {especiais[i], cores[j]};

        baralho[cartaAtual] = nova;
        cartaAtual++;

        baralho[cartaAtual] = nova;
        cartaAtual++; 

      }
  }
  
  // vamos ver se até aqui ta tudo razoável
  for(i=0;i<cartaAtual;i++)
  {
    printf("%c %c\n",baralho[i].valor, baralho[i].cor);
  }
  
} // FIM DO MAIN
 

  
  

// Aqui rola um shuffle https://stackoverflow.com/questions/6127503/shuffle-array-in-c

// Tem quer os player

// TODO: ter um sevidor aqui https://pt.wikibooks.org/wiki/Programar_em_C/Sockets
