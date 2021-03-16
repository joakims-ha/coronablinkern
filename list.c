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

}

void listPrune(contact_list list, long int age)
{
	for(int i=0;i<list->size;i++)
	{
		if(list->items[i].date<age)
		{
			list->items[i].id = 0;
			list->items[i].date = 0;
		}
	}
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