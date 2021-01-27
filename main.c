/*  Joakim Salmén 
    Programmering 2
	Coronablinker
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "menu.h"

// Global variables
list device_log;
int id, code;

void init()
{
	// Unlock code
	code = 123;
	// Create unique device id
	srand(time(NULL));
	id = rand();
	printf("Enhetens ID: %d\n",id);
	// Initialize device list 
	device_log = listCreate(device_log);
}


void simContact()
{
	// Simulate device contact
	printf("\nAnge enhetens id > ");
	int i;
	scanf("%d", &i);
	if(i!=0)
	{
		listAdd(device_log, i);
	} else {
		listAdd(device_log, rand());
	}
}

void simAlert()
{
	// Simulate alert recival
	printf("Smittlarm mottaget. Sänder information till servern.\n\n");
	listShow(device_log);
}

void reportCase()
{
	// Report case
	printf("\nAnge öppningskod > ");
	int c;
	scanf("%d", &c);
	if(c==code)
	{
		printf("Öppningskod mottagen. Sänder information till servern.\n\n");
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
				simContact();
				break;
			case M_SIM_ALERT:
				simAlert();
				break;
			case M_REPORT:
				reportCase();
				break;
			case M_QUIT:
				printf("Hejdå\n");
				listDestroy(device_log);
				return 0;
			default:
				printf("Felakting val\n");
		}
		printf("\n");
	}
}

