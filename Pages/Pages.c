#include "Pages.h"

void printPage(struct Pages page) {

   printf( "Page Version : %s\n", page.version);
   printf( "Page owner : %s\n", page.owner);
   printf( "Page number : %d\n", page.pageNumber);
}
