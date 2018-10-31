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




/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno, clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");
     bzero(buffer,256);
     n = read(newsockfd,buffer,255);
     if (n < 0) error("ERROR reading from socket");
     printf("Here is the message: %s\n",buffer);
     n = write(newsockfd,"I got your message",18);
     if (n < 0) error("ERROR writing to socket");
     return 0; 
}


// =================================================================


#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;

    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);
    return 0;
}

