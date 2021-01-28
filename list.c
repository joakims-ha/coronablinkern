#include <time.h>
#include <stdlib.h>
#include <stdio.h>

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

list listCreate()
{
    list l = (list) malloc(sizeof(struct list_head));
    l->first = NULL;
    l->last = NULL;
    return l;
}

void listDestroy(list l) {
	struct entry* tmp;
    while (l->first)
    {
        tmp = l->first;
		l->first = l->first->prev;
		free(tmp);
    }
	free(l);
}

void listAdd(list l, int id, long int date)
{
	struct entry* newEntry = (struct entry*) malloc(sizeof(struct entry));
	newEntry->id = id;
	newEntry->date = date;
	newEntry->prev = NULL;
	if(!l->first)
	{
		newEntry->next = NULL;
		l->first = newEntry;
		l->last = newEntry;
	}
	else 
	{
		newEntry->next = l->last;
		l->last->prev = newEntry;
		l->last = newEntry;
	}
}

void listPrune(list l, long int date)
{
	long int max_age = 3600;
	struct entry* next = l->first;
	struct entry* tmp;
    while (next)
    {
		if((date-next->date)>max_age)
		{
			tmp = next;
			l->first = next->prev;
			l->first->next = NULL;
			free(tmp);
		}
        next = next->prev;
    }
}

void listShow(list l)
{
	struct entry* tmp = l->first;
	printf("\tID\t\t\t\tTID\n");
	printf("--------------------------------------------------------\n");
    while (tmp)
    {
        printf("%d\t\t\t%s",tmp->id,ctime(&tmp->date));
        tmp = tmp->prev;
    }
}