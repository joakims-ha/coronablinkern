#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

void simContact(list l)
{
	// Simulate device contact
	printf("\nAnge enhetens id > ");
	int i;
	scanf("%d", &i);
	
	printf("\nAnge ålder i timmar > ");
	int a;
	scanf("%d", &a);

	time_t now;
	time(&now);

	if(i!=0)
	{
		listAdd(l, i, now);
	} else {
		listAdd(l, rand(), now-(a*3600));
	}
}

void simAlert(list l)
{
	// Simulate receiving alert
	printf("\nSmittlarm mottaget. Sänder information till servern.\n\n");
	struct entry* tmp = l->first;
	printf("\tID\t\t\t\tTID\n");
	printf("--------------------------------------------------------\n");
    while (tmp)
    {
        printf("%d\t\t\t%s",tmp->id,ctime(&tmp->date));
        tmp = tmp->prev;
    }
}