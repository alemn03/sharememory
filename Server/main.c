#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>

int main(void)
{
    struct sockaddr_in direccionServidor;
    direccionServidor.sin_family = AF_INET;
    direccionServidor.sin_addr.s_addr = INADDR_ANY;
    direccionServidor.sin_port = htons(8080);

    int servidor = socket(AF_INET,SOCK_STREAM,0);
    int clienteActivo = 1;

    setsockopt(servidor,SOL_SOCKET,SO_REUSEADDR,&clienteActivo, sizeof(clienteActivo));

    if(bind(servidor, (void*) &direccionServidor, sizeof(servidor) != 0)){
        perror("Fallo conector bind");
        return 1;
    }
     printf("Servidor escuchando peticiones!");
     listen(servidor,SOMAXCONN);

     struct sockaddr_in direccionCliente;
     unsigned int tamDireccion;
     int cliente = accept(servidor, (void*) &direccionCliente, &tamDireccion);

     printf("Servidor recibio una conexion en %d!!\n",cliente);
     send(cliente,"Bienvenido al servidor",23,0);
    /*

    uint32_t tam;
	recv(cliente, &tam, 4, 0);

	char* buffer = malloc(tam);
	recv(cliente, buffer, tam, MSG_WAITALL);

     */
    char* buffer = malloc(1000);
    while(1){
        int byteRecibidos = recv(cliente,buffer,1000,0);
        if(byteRecibidos <= 0){
            perror("Cliente desconectado!");
            return 1;
        }
         buffer[byteRecibidos] = '\0';
         printf("Me llegaron %d bytes con %s", byteRecibidos, buffer);
    }
     free(buffer);
     return 0;
}
