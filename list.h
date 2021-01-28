#ifndef LIST
#define LIST

typedef struct list_head* list;

list listCreate();
void listDestroy(list l);
void listAdd(list l, int id, long int date);
void listPrune(list l, long int date);
void listShow(list l);

#endif