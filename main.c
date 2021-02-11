#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "list.h"
#include "sim.h"
#include "ui.h"

// Global variables
list_t devices;
time_t now;

void reportCase()
{
	// Report case
	printf("\nAnge öppningskod > ");
	int c;
	scanf("%d", &c);
	if(c==DEVICE_CODE)
	{
		printf("\nÖppningskod mottagen. Sänder information till servern.\n\n");
		time_t now;
		time(&now);
		long int max = (21*24*60*60);
		long int limit = now-max;
		listPrune(devices, limit);
		list_i *item = devices->start;
		printf("\tID\t\t\t\tTID\n");
		printf("--------------------------------------------------------\n");
		while (item)
		{
			printf("%d\t\t\t%s",item->id,ctime(&item->date));
			item = item->next;
		}
	} else {
		printf("Felaktig kod!\n");
	}
}

int main()
{	
	devices = listCreate();
	while(1)
	{
		switch(getMenuChoice())
		{
			case M_SIM_CONTACT:
				simContact(devices);
				break;
			case M_SIM_ALERT:
				simAlert(devices);
				break;
			case M_REPORT:
				reportCase();
				break;
			case M_QUIT:
				printf("Hejdå\n");
				listDestroy(devices);
				return 0;
			default:
				printf("Felakting val!\n");
		}
		printf("\n");
	}
}

