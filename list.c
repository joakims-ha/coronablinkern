#include <time.h>
#include <stdlib.h>
#include <stdio.h>

struct entry
{
    int  id;
	time_t  timestamp;
    struct entry* prev;
    struct entry* next;
};
struct list_head {
    struct entry* first;
    struct entry* last;
};

typedef struct list_head* list;

list createList()
{
    list l = (list) malloc(sizeof(struct list_head));
    l->first = NULL;
    l->last = NULL;
    return l;
}

void addEntry(list l, int id)
{
	struct entry* newEntry = (struct entry*) malloc(sizeof(struct entry));
	newEntry->id = id;
	time(&newEntry->timestamp);
	newEntry->prev = NULL;
	if(!l->first)
	{
		newEntry->next = NULL;
		l->first = newEntry;
		l->last = newEntry;
	} else {
		newEntry->next = l->last;
		l->last->prev = newEntry;
		l->last = newEntry;
	}
}

void showList(list l)
{
	struct entry* tmp = l->first;
    while (tmp)
    {
        printf("%d %s",tmp->id,ctime(&tmp->timestamp));
        tmp = tmp->prev;
    }
}