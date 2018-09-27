#include <sys/types.h>
#include <netinet/in.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>



/*Implementacion del hash map*/

#define SIZE 20

struct DataItem {
   int data;
   int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key) {
   return key % SIZE;
}

struct DataItem *search(int key) {
   //get the hash
   int hashIndex = hashCode(key);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {

      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex];

      //go to next cell
      ++hashIndex;

      //wrap around the table
      hashIndex %= SIZE;
   }

   return NULL;
}

void insert(int key,int data) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;
   item->key = key;

   //get the hash
   int hashIndex = hashCode(key);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      //go to next cell
      ++hashIndex;

      //wrap around the table
      hashIndex %= SIZE;
   }

   hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
   int key = item->key;

   //get the hash
   int hashIndex = hashCode(key);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {

      if(hashArray[hashIndex]->key == key) {
         struct DataItem* temp = hashArray[hashIndex];

         //assign a dummy item at deleted position
         hashArray[hashIndex] = dummyItem;
         return temp;
      }

      //go to next cell
      ++hashIndex;

      //wrap around the table
      hashIndex %= SIZE;
   }

   return NULL;
}

void display() {
   int i = 0;

   for(i = 0; i<SIZE; i++) {

      if(hashArray[i] != NULL)
         printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
      else
         printf(" ~~ ");
   }

   printf("\n");
}


/* fin del hash*/
struct Config /* creamos una estructura llamada Config */
{
	char ip[25];
	char numeroPaginas[25];
	char MediaExponecial[25];
	char probabilidadLectura[25];
};

//* creamos un metodo que imprima el config
void printConfig(struct Config config ) {

   printf( "IP : %s\n", config.ip);
   printf( "numero paginas : %s\n", config.numeroPaginas);
   printf( "media exponencial : %s\n", config.MediaExponecial);
   printf( "probalidad lectura : %s\n", config.probabilidadLectura);
}

//* creamos un metodo que haga el split de un string
char* str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* cuanta la cantidad de elementos que se van a extrear*/
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

// se crea un metodo que lea el config file
struct Config readConfigFiel()
{


    struct Config configuration;
    FILE *ptr_file;
    char buf[1000];

    ptr_file =fopen("config.txt","r");
        if (!ptr_file){
             printf( "No se encontro config.txt \n");
            return configuration;
        }

            int count=0;


            while (fgets(buf,1000, ptr_file)!=NULL)
                {
                    char** tokens;
                    tokens = str_split(buf, ':');

                        if (tokens)
                            {

                                        if(count==0)
                                            {



                                                  strcpy(configuration.ip, *(tokens + 1));
                                                 // printf("ip %s \n", configuration.ip);



                                            }else{

                                                    if(count==1)
                                                        {


                                                            strcpy(configuration.numeroPaginas, *(tokens + 1));
                                                            //printf("numeroPaginas %s \n", configuration.numeroPaginas);

                                                        }else{

                                                                    if(count==2)
                                                                        {


                                                                            strcpy(configuration.MediaExponecial, *(tokens + 1));
                                                                           // printf("MediaExponecial %s \n", configuration.MediaExponecial);


                                                                        }else{

                                                                                    if(count==3)
                                                                                        {

                                                                                            strcpy(configuration.probabilidadLectura, *(tokens + 1));
                                                                                            //printf("probabilidadLectura %s \n", configuration.probabilidadLectura);

                                                                                        }
                                                                            }

                                    }
                                }


                                    free(*(tokens + 1));
                                    free(tokens);
            }

            count++;
        }

		fclose(ptr_file);

return configuration;

}


int main(void)
{

/*Read config file*/

    struct Config config;

    config = readConfigFiel();

    printConfig(config);

/*end read config file*/

/* hash */

/**dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));

   dummyItem->data = -1;
   dummyItem->key = -1;

   insert(1, 20);
   insert(2, 70);
   insert(42, 80);
   insert(4, 25);
   insert(12, 44);
   insert(14, 32);
   insert(17, 11);
   insert(13, 78);
   insert(37, 97);
*/
printf("config.numeroPaginas %s \n", config.numeroPaginas);
int n= atoi (config.numeroPaginas);
printf("N  %d \n", n);

for(int i=0;i<n;i++){

   insert(i, "Server");
   printf("inserto  %d \n", i);
}

   display();
   item = search(5);

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }

   delete(item);
   item = search(5);

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }

/*end hash*/

 struct sockaddr_in direccionServidor;
    direccionServidor.sin_family = AF_INET;
    direccionServidor.sin_addr.s_addr = INADDR_ANY;
    direccionServidor.sin_port = htons(8081);

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
