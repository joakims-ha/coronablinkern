#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "list.h"
#include "menu.h"
#include "sim.h"

// Global variables
list device_log;
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
		struct entry* tmp = device_log->first;
		printf("\tID\t\t\t\tTID\n");
		printf("--------------------------------------------------------\n");
		while (tmp)
		{
			printf("%d\t\t\t%s",tmp->id,ctime(&tmp->date));
			tmp = tmp->prev;
		}
	} else {
		printf("Felaktig kod!\n");
	}
}


int main()
{	
	device_log = listCreate();
	while(1)
	{
		switch(getMenuChoice())
		{
			case M_SIM_CONTACT:
				simContact(device_log);
				break;
			case M_SIM_ALERT:
				simAlert(device_log);
				break;
			case M_REPORT:
				reportCase();
				break;
			case 9:
				time(&now);
				listPrune(device_log, now);
				break;
			case M_QUIT:
				printf("Hejdå\n");
				listDestroy(device_log);
				return 0;
			default:
				printf("Felakting val!\n");
		}
		printf("\n");
	}
}

