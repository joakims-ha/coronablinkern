#include <stdlib.h>
#include "list.h"

list_t listCreate()
{
    list_t newList = malloc(sizeof(list_t));
    newList->first = NULL;
    newList->last = NULL;
    return newList;
}

void listDestroy(list_t list) {
	list_item *tmpItem;
    while (list->first)
    {
        tmpItem = list->first;
		list->first = list->first->prev;
		free(tmpItem);
    }
	free(list);
}

void listAdd(list_t list, int id, long int date)
{
	list_item *newItem = malloc(sizeof(list_item));
	newItem->id = id;
	newItem->date = date;
	newItem->prev = NULL;
	if(!list->first)
	{
		newItem->next = NULL;
		list->first = newItem;
		list->last = newItem;
	}
	else 
	{
		newItem->next = list->last;
		list->last->prev = newItem;
		list->last = newItem;
	}
}

void listPrune(list_t list, long int age)
{
	list_item *nextItem = list->first;
	list_item *tmpItem;
    while (nextItem)
    {
		if(nextItem->date>age)
		{
			tmpItem = nextItem;
			list->first = nextItem->prev;
			list->first->next = NULL;
			free(tmpItem);
		}
        nextItem = nextItem->prev;
    }
}