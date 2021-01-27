#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void simContact(list l)
{
	// Simulate device contact
	printf("\nAnge enhetens id > ");
	int i;
	scanf("%d", &i);
	if(i!=0)
	{
		listAdd(l, i);
	} else {
		listAdd(l, rand());
	}
}

void simAlert(list l)
{
	// Simulate receiving alert
	printf("Smittlarm mottaget. Sänder information till servern.\n\n");
	listShow(l);
}
