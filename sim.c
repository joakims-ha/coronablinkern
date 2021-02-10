#include "sim.h"

void simContact(list_t list)
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
		listAdd(list, i, now);
	} else {
		listAdd(list, rand(), now-(a*3600));
	}
}

void simAlert(list_t list)
{
	// Simulate receiving alert
	printf("\nSmittlarm mottaget. Sänder information till servern.\n\n");
	list_i *item = list->start;
	printf("\tID\t\t\t\tTID\n");
	printf("--------------------------------------------------------\n");
    while (item)
    {
        printf("%d\t\t\t%s",item->id,ctime(&item->date));
        item = item->next;
    }
}