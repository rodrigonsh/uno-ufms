// Este é o código do sevidor

#include <stdio.h>

const int size = 108;

void shuffle(Struct Carta array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          Struct Carta t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

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
  
  struct Carta baralho[size];

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
  for(i=0; i<3; i++)
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
  // Criar coringa
 for(j=0;j<4; j++) 
 {
    struct Carta coringa4 = {'C', '4'};
    struct Carta joker = {'J', 'W'};
   
    baralho[cartaAtual] = coringa4;
    cartaAtual++;
   
    baralho[cartaAtual] = joker;
    cartaAtual++;
   
  }
  
  shuffle(baralho, 108;
  
  // vamos ver se até aqui ta tudo razoável
  for(i=0;i<cartaAtual;i++)
  {
    printf("%c %c\n",baralho[i].valor, baralho[i].cor);
  }
  printf("%d\n", cartaAtual);
  
} // FIM DO MAIN
 

  
  

// Aqui rola um shuffle https://stackoverflow.com/questions/6127503/shuffle-array-in-c

// Tem quer os player

// TODO: ter um sevidor aqui https://pt.wikibooks.org/wiki/Programar_em_C/Sockets
