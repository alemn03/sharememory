#ifndef PAGES_H
#define PAGES_H


struct Pages {
   char version[50];
   char owner[50];
   int  pageNumber;
};

void printPage( struct Pages page );

#endif // PAGES_H
