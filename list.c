#include "list.h"

contact_list listCreate()
{
    contact_list newList = malloc(sizeof(contact_list));
	newList->items = NULL;
	newList->size = 0;
    return newList;
}

void listDestroy(contact_list list)
{
	for(int i=0;i<list->size;i++)
	{
		free(&list->items[i]);
	}
	free(list);
}

void listAdd(contact_list list, long int id, long int date)
{
	list->size++;
	list->items = realloc(list->items, list->size*sizeof(contact));
	contact *newItem = malloc(sizeof(contact));
	newItem->id = id;
	newItem->date = date;
	list->items[list->size-1] = *newItem;
	contact tmpItem;
	for(int i=list->size-1;i>0;i--)
	{
		if(list->items[i-1].date < list->items[i].date)
		{
			tmpItem = list->items[i];
			list->items[i] = list->items[i-1];
			list->items[i-1] = tmpItem;
		}
	}
}

void listPrune(contact_list list, long int age)
{
	int f,c = 0;
	for(int i=0;i<list->size;i++)
	{
		if(list->items[i].date<age)
		{
			list->items[i].id = 0;
			c++;
		}
	}
	for(int i=0;i<list->size;i++)
	{
		if(list->items[i].id == 0)
		{			
			f = i;
			while(list->items[f].id == 0 && f < list->size)
			{
				f++;
			}
			list->items[i] = list->items[f];
			list->items[f].id = 0;
		}
	}
	list->size = list->size - c;
	list->items = realloc(list->items, list->size*sizeof(contact));
}

bool listIdExist(contact_list list, long int id)
{
	for(int i=0;i<list->size;i++)
	{
		if(list->items[i].id == id )
		{
			return true;
		}
	}
	return false;
}

void listSave(contact_list list, char *file)
{
    FILE *pfile = fopen(file, "w");
    if (pfile != NULL)
	{
		fwrite(&list->size, sizeof(int), 1, pfile);
		fwrite(list->items, sizeof(contact), list->size, pfile);
		fclose(pfile);
    }
    else
	{
        printf("Error opening file!");
    }
}

void listLoad(contact_list list, char *file)
{
	FILE *pfile = fopen(file, "r");
    if (pfile != NULL)
	{
		fread(&list->size, sizeof(int), 1, pfile);
		list->items = malloc(list->size*sizeof(contact));
		fread(list->items, sizeof(contact), list->size, pfile);
        fclose(pfile);
    }
    else
	{
        printf("Error opening file!");
    }
}