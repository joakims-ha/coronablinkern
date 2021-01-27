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


void logDevice()
{
	// Add device to list of contacts
	printf("\n");
	printf("Ange enhetens id > ");
	int id;
	scanf("%d", &id);
	listAdd(device_log, id);
	listShow(device_log);
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
				logDevice();
				break;
			case 2:
				printf("Larm\n");
				break;
			case 3:
				printf("Meddela\n");
				break;
			case 4:
				printf("Hejdå\n");
				listDestroy(device_log);
				return 0;
			case 5:
				printf("Testing\n");
				listAdd(device_log, 1);
				listAdd(device_log, 2);
				listShow(device_log);
				break;
			default:
				printf("Felakting val\n");
		}
		printf("\n");
	}
}

