#include <stdio.h>

int getMenuChoice()
{
	// Display menu and get choice
	printf("\n");
	printf("  Välkommen till Coronablinkern\n");
	printf("=================================\n");
	printf("1) Simulera kontakt\n");
	printf("2) Simulera larm\n");
	printf("3) Rapportera fall\n");
	printf("\n");
	printf("0) Avsluta programmet\n");
	printf("---------------------------------\n");
	printf("> ");
	int m;
	scanf("%d", &m);
	while ((getchar()) != '\n'); 
	return m;
}
