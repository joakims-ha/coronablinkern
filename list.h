#ifndef LIST
#define LIST

struct entry
{
    int  id;
	time_t  date;
    struct entry* prev;
    struct entry* next;
};

struct list_head {
    struct entry* first;
    struct entry* last;
};

typedef struct list_head* list;

list listCreate();
void listDestroy(list l);
void listAdd(list l, int id, long int date);
void listPrune(list l, long int date);

#endif