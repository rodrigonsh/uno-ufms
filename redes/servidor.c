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
  int meu_socket, sock_cliente;
  struct sockaddr_in addr;

  meu_socket = socket(AF_INET, SOCK_STREAM, 0);
  if(meu_socket == -1)
  {
    printf("ERRO ao criar socket\n");
    return 1;
  }
  addr.sin_family = AF_INET;
  addr.sin_port = htons(1234);
  addr.sin_addr.s_addr = INADDR_ANY;

  memset(&addr.sin_zero, 0, sizeof(addr.sin_zero));
  if(bind(meu_socket, (struct sockaddr*)&addr, sizeof(addr)) == -1)
  {
    printf("ERRO na função Bind\n");
    return 1;
  }

  if(listen(meu_socket, 1) == -1)
  {
    printf("ERRO na função Listen\n");
    return 1;
  }
  printf("Aguardando conexoes...\n");
  sock_cliente = accept(meu_socket, 0, 0);

  if(meu_socket == -1)
  {
    printf("ERRo na funcao aceppt()\n");
    return 1;
  }

  printf("Pedido de conexao feito\n");

  int recebidos, enviados;
  char mensagem[256], resposta[256];

  do {
    recebidos = recv(sock_cliente, resposta, 256, 0);
    resposta[recebidos] = '\0';
    printf("Cliente: %s\n", resposta);

    printf("Servidor: ");
    fgets(mensagem, 256, stdin);
    mensagem[strlen(mensagem) - 1] = '\0';
    enviados = send(sock_cliente, mensagem, strlen(mensagem), 0);
  } while(recebidos != -1 && enviados != -1);

  close(sock_cliente);
  close(meu_socket);
  return 0;
}
