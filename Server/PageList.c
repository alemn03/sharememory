#include <stdio.h>
#include "Pages.h"
#include "PageList.h"

void add_PageList(struct Pages pages) {

       struct PageList *nuevo;

      /* reservamos memoria para el nuevo elemento */
      nuevo = (struct PageList *) malloc (sizeof(struct PageList));

      if (nuevo==NULL) printf( "No hay memoria disponible!\n");
       nuevo->pages=pages;
      /* el campo siguiente va a ser NULL por ser el último elemento
         de la lista */
      nuevo->siguiente = NULL;

      /* ahora metemos el nuevo elemento en la lista. lo situamos
         al final de la lista */
      /* comprobamos si la lista está vacía. si primero==NULL es que no
         hay ningún elemento en la lista. también vale ultimo==NULL */
      if (primero==NULL) {
         printf( "Primer elemento\n");
         primero = nuevo;
         ultimo = nuevo;
         }
      else {
           /* el que hasta ahora era el último tiene que apuntar al nuevo */
           ultimo->siguiente = nuevo;
           /* hacemos que el nuevo sea ahora el último */
           ultimo = nuevo;
      }

 }

 void show_pageList() {
      struct PageList *auxiliar; /* lo usamos para recorrer la lista */
      int i;

      i=0;
      auxiliar = primero;
      printf("\nMostrando la lista completa:\n");
      while (auxiliar!=NULL) {
            printf( "Nombre: %d, Page: %s\n",
                    auxiliar->pages.pageNumber,auxiliar->pages.owner);
            auxiliar = auxiliar->siguiente;
            i++;
      }
      if (i==0) printf( "\nLa lista está vacía!!\n" );
 }



