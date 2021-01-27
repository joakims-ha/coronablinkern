/*  Joakim Salmén 
    Programmering 2
	Coronablinker
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "menu.h"

// Global list of all devices in proximity
list device_log;

void init()
{
	// Create unique device id
	srand(time(NULL));
	printf("Device ID: %d\n",rand() );
	// Initialize device list 
	device_log = listCreate(device_log);
}


void simContact()
{
	// Add device to list of contacts
	printf("\nAnge enhetens id > ");
	int id;
	scanf("%d", &id);
	listAdd(device_log, id);
}

void simAlert()
{

}

void reportCase()
{

}

void uploadLog()
{
	// Send log of devices to server
}

int main()
{	
	init();
	while(1)
	{
		switch(getMenuChoice())
		{
			case 1:
				simContact();
				break;
			case 2:
				simAlert();
				break;
			case 3:
				reportCase();
				break;
			case 5:
				listShow(device_log);
				break;
			case 0:
				printf("Hejdå\n");
				listDestroy(device_log);
				return 0;
			default:
				printf("Felakting val\n");
		}
		printf("\n");
	}
}

