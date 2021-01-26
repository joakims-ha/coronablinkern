/*  Joakim Salmén 
    Programmering 2
	Coronablinker
*/
#include <stdio.h>
#include "list.h"
#include "menu.h"

list device_log;

void init()
{
	// Create unique device id

	// Initialize device list 
	device_log = createList(device_log);
}


void logDevice()
{
	// Add device to list of contacts
	printf("\n");
	printf("Ange enhetens id > ");
	int id;
	scanf("%d", &id);
	addEntry(device_log, id);
	showList(device_log);
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
				return 0;
			default:
				printf("Felakting val\n");
		}
		printf("\n");
	}
}

