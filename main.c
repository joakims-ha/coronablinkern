#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "list.h"
#include "sim.h"
#include "menu.h"
#include "ui.h"
#include "io.h"

list_t devices;

int sim_menu_list()
{
	for(int i = 1; i <= 10; i++)
    {
		printf("Add random contact to list\n");
    }
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
	menuAddCall(main_menu, "Rapportera fall", main_menu_case, NULL);
	menuAddCall(sim_menu, "Simulera kontakt", simContact, devices);
	menuAddCall(sim_menu, "Simulera larm", simAlert, devices);
	menuAddCall(sim_menu, "Skapa lista", sim_menu_list, NULL);

	printf("\n--== Välkommen till Coronablinkern ==--\n");
	printf("\n            ## v0.1 ##\n");
	printf("\n---------------------------------------\n");
	
	while(menuSelection(main_menu))
	{
		printf("\n---------------------------------------\n");
	}
}

