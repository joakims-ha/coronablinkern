#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "list.h"
#include "sim.h"
#include "menu.h"
#include "ui.h"

list_t devices;

void sim_menu_contact()
{
	simContact(devices);
	
}

void sim_menu_alert()
{
	simAlert(devices);
}

void main_menu_case()
{
	if(uiUserInput("Ange öppningskod > ")==DEVICE_CODE)
	{
		if(!listIsEmpty(devices)) simCase(devices);
	}
	else
	{
		printf("\nFelaktig kod!\n");
	}
}

int main()
{	
	devices = listCreate();

	menu_t *main_menu = menuCreate(NULL,"Huvudmeny");
	menu_t *sim_menu = menuCreate(main_menu,"Simulering");

	menuAdd(main_menu, M_MENU, "Simulering", sim_menu);
	menuAdd(main_menu, M_ITEM, "Rapportera fall", main_menu_case);

	menuAdd(sim_menu, M_ITEM, "Simulera kontakt", sim_menu_contact);
	menuAdd(sim_menu, M_ITEM, "Simulera larm", sim_menu_alert);

	printf("\n--== Välkommen till Coronablinkern ==--\n");
	printf("\n            ## v0.1 ##\n");
	printf("\n---------------------------------------\n");
	while(menuSelection(main_menu))
	{
		printf("\n---------------------------------------\n");
	}
}

