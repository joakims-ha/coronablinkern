#include <stdio.h>
#include <time.h>

struct Entry
{
   int  id;
   time_t  timestamp;
} logg[10];


void init()
{
	// Create unique device id
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
	logg[0].id = id;
	time(&logg[0].timestamp);
	printf("\nid: %d tid: %s",logg[0].id, ctime(&logg[0].timestamp));
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

