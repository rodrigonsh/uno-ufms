#include <stdio.h>
#include<stdlib.h>

const int size = 108;

  struct Carta{
    char valor;
    char cor;
  };


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

int main(){
  int carta_atual = 0;
  
  /*
  "5B" // 5 Blue
  "+G" // +2 Green
  "JW" // Joker
  "IY" // Inversao Yellow
  "C4" // Joker 4 Cartas
  "PR" // Pulante (Bloqueio, perde a vez) Red
   "uno"// aviso de uma carta
   */


  char cores[4] = {'R', 'G', 'B', 'Y'};
  char especiais[3] = {'I', 'P', '+'};
  int uno=0;
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
  
  shuffle(baralho, 108);
  
  // vamos ver se até aqui ta tudo razoável
  for(i=0;i<cartaAtual;i++)
  {
    printf("%c %c\n",baralho[i].valor, baralho[i].cor);
  }
  printf("%d\n", cartaAtual);
  
} 
