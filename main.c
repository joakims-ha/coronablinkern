#include <stdio.h>

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
	return m;
}

void logDevice(int id)
{
	// Add device to list of contacts
}

void uploadLog()
{
	// Send log of devices to server
}

int main()
{	
	init();
	int c = showMenu();
	printf("choice: %d\n",c);
	return 0;
}

