#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pages.h"


int main()
{
   struct Pages page1;        /* Declare page1 of type Page */
   struct Pages page2;        /* Declare page2 of type Page */

   /* page 1 specification */
   strcpy(page1.version,"V1.0");
   strcpy(page1.owner, "1.1.1.1");
   page1.pageNumber = 1;

   /* page 2 specification */
   strcpy( page2.version, "V1.0");
   strcpy( page2.owner, "10.10.10.10");
   page2.pageNumber = 2;

    /* print page1 info */
   printPage(page1);
   printf("\n");

   /* Print page2 info */
   printPage( page2 );


   return 0;
}
