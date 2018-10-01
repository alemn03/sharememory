#ifndef PAGES_H
#define PAGES_H


struct Pages {
   int version;
   char owner[50];
   int  pageNumber;
};

void printPage( struct Pages page );

#endif // PAGES_H
