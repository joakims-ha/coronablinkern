#include "list.h"

list_t listCreate()
{
    list_t newList = malloc(sizeof(list_t));
    newList->start = NULL;
    return newList;
}

void listDestroy(list_t list) {
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
	if(!list->start)
	{
		newItem->next = NULL;
		list->start = newItem;
	}
	else 
	{
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
		while (item&&item->date>age)
		{
			tmpItem = item;
			list->start = item->next;
			free(tmpItem);
			item = item->next;
		}
		while (item)
		{
			if(item->date>age)
			{
				tmpItem = item;
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