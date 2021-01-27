typedef struct list_head* list;
list listCreate();
void listDestroy(list l);
void listAdd(list l, int id);
void listPrune(list l);
void listShow(list l);
