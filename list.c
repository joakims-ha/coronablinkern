#include "list.h"
#include <stdio.h>

list_t listCreate()
{
    list_t newList = malloc(sizeof(list_t));
    newList->start = NULL;
    return newList;
}

void listDestroy(list_t list)
{
	list_i *tmpItem;
    while (list->start)
    {
        tmpItem = list->start;
		list->start = list->start->next;
		free(tmpItem);
    }
	free(list);
}

void listAdd(list_t list, int id, long int date)
{
	list_i *newItem = malloc(sizeof(list_i));
	newItem->id = id;
	newItem->date = date;
	newItem->prev = NULL;
	if(listIsEmpty(list))
	{
		newItem->next = NULL;
		list->start = newItem;
	}
	else 
	{
		list->start->prev = newItem;
		newItem->next = list->start;
		list->start = newItem;
	}
}

void listPrune(list_t list, long int age)
{

	if(!listIsEmpty(list))
	{
		list_i *item = list->start;
		list_i *tmpItem;
		while (item)
		{
			if(item->prev)
			{
				if(item->date<age)
				{
					tmpItem = item;
					item->prev->next = item->next;
					item = item->next;
					free(tmpItem);
				}
				else
				{
					item = item->next;
				}
			}
			else
			{
				if(item->date<age)
				{
					tmpItem = item;
					list->start = item->next;
					if(list->start) list->start->prev = NULL;
					item = item->next;
					free(tmpItem);
				}
				else
				{
					item = item->next;
				}
			}
		}
	}
}

bool listIsEmpty(list_t list)
{
	if(list->start)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int listLength(list_t list)
{
	list_i *item = list->start;
	int counter = 0;
	while (item)
	{
		counter++;
		item = item->next;
	}
	return counter;
}

void listSave(list_t list)
{

}

void listLoad(list_t list)
{

}