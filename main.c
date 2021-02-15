#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "list.h"
#include "sim.h"
#include "menu.h"
#include "ui.h"

list_t devices;

int sim_menu_contact()
{
	simContact(devices);
	return 1;
	
}

int sim_menu_alert()
{
	simAlert(devices);
	return 1;
}

int main_menu_case()
{
	if(uiUserInput("Ange öppningskod > ")==DEVICE_CODE)
	{
		if(!listIsEmpty(devices)) simCase(devices);
	}
	else
	{
		printf("\nFelaktig kod!\n");
	}
	return 1;
}

int main()
{	

	devices = listCreate();
	menu_t *main_menu = menuCreate(NULL,"Huvudmeny");
	menu_t *sim_menu = menuCreate(main_menu,"Simulering");
	
	menuAddMenu(main_menu, "Simulering", sim_menu);
	menuAddItem(main_menu, "Rapportera fall", main_menu_case);
	menuAddItem(sim_menu, "Simulera kontakt", sim_menu_contact);
	menuAddItem(sim_menu, "Simulera larm", sim_menu_alert);

	printf("\n--== Välkommen till Coronablinkern ==--\n");
	printf("\n            ## v0.1 ##\n");
	printf("\n---------------------------------------\n");
	
	while(menuSelection(main_menu))
	{
		printf("\n---------------------------------------\n");
	}
}

