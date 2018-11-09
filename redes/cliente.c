#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include <fcntl.h> 
#include <unistd.h>

int main()
{
  int meu_socket;
  struct sockaddr_in addr;

  meu_socket = socket(AF_INET, SOCK_STREAM, 0);
  if(meu_socket == -1)
  {
    printf("ERRO ao criar socket\n");
    return 1;
  }

  addr.sin_family       = AF_INET;
  addr.sin_port         = htons(1234);
  addr.sin_addr.s_addr  = inet_addr("127.0.0.1");/*endereco interno da maquina*/

  memset(&addr.sin_zero, 0, sizeof(addr.sin_zero));

  if(connect(meu_socket, (struct sockaddr*)&addr, sizeof(addr)) == -1)
  {
    printf("ERRO no connect()\n");
    return 1;
  }

  int recebidos, enviados;
  char mensagem[256], resposta[256];

  do {
    printf("Cliente: ");
    fgets(mensagem, 256, stdin);
    mensagem[strlen(mensagem) - 1] = '\0';
    enviados = send(meu_socket, mensagem, strlen(mensagem), 0);


    recebidos = recv(meu_socket, resposta, 256, 0);
    resposta[recebidos] = '\0';
    printf("Servidor: %s\n", resposta);
  } while(recebidos != -1 && enviados != -1);

  close(meu_socket);

  return 0;
}
