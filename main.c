/*  Joakim Salmén 
    Programmering 2
	Coronablinker
*/
#include <stdio.h>
#include "list.h"

list device_log;

void init()
{
	// Create unique device id
	device_log = createList(device_log);
}

int showMenu()
{
	// Display menu and get choice
	printf("\n");
	printf("  Välkommen till Coronablinkern\n");
	printf("=================================\n");
	printf("1) Lägg till enhet som varit nära\n");
	printf("2) Larm om smitta mottaget\n");
	printf("3) Meddela om smitta\n");
	printf("\n");
	printf("4) Avsluta programmet\n");
	printf("---------------------------------\n");
	printf("> ");
	int m;
	scanf("%d", &m);
	while ((getchar()) != '\n'); 
	return m;
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
		switch(showMenu())
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

