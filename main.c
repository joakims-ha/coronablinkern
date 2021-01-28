/*  Joakim Salmén 
    Programmering 2
	Coronablinker
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "menu.h"
#include "sim.h"

// Global variables
list device_log;
int id, code;
time_t now;

void init()
{
	// Unlock code
	code = 123;
	// Create unique device id
	srand(time(NULL));
	id = rand();
	printf("Enhetens ID: %d\n",id);
	// Initialize device list 
	device_log = listCreate();
}

void reportCase()
{
	// Report case
	printf("\nAnge öppningskod > ");
	int c;
	scanf("%d", &c);
	if(c==code)
	{
		printf("\nÖppningskod mottagen. Sänder information till servern.\n\n");
		listShow(device_log);
	} else {
		printf("Felaktig kod!\n");
	}
}

int main()
{	
	init();
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

