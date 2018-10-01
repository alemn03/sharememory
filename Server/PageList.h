#ifndef PAGEList_H
#define PAGEList_H


struct PageList {
   struct Pages pages;
   struct PageList *siguiente;
};

struct PageList *primero, *ultimo;

void show_pageList();

void add_PageList(struct Pages pages);
#endif // PAGES_H
