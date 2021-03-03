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
	time_t now;
	time(&now);
	int range = MAX_AGE*24*60*60*2;
	for(int i = 1; i <= 10; i++)
    {
		listAdd(devices, rand(), now-(rand()%range));
    }
	return 1;
}

int list_menu_save()
{
	listSave(devices,"list.txt");
	return 1;
}

int list_menu_load()
{
	listLoad(devices,"list.txt");
	return 1;
}

int list_menu_show()
{
	uiShowList(devices);
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
	menu_t *list_menu = menuCreate(sim_menu,"Lista");
	
	menuAddMenu(main_menu, "Simulering", sim_menu);
	menuAddMenu(sim_menu, "Lista", list_menu);
	menuAddCall(main_menu, "Rapportera fall", main_menu_case, NULL);

	menuAddCall(sim_menu, "Simulera kontakt", simContact, devices);
	menuAddCall(sim_menu, "Simulera larm", simAlert, devices);

	menuAddCall(list_menu, "Generera lista", sim_menu_list, NULL);
	menuAddCall(list_menu, "Spara lista", list_menu_save, NULL);
	menuAddCall(list_menu, "Ladda lista", list_menu_load, NULL);
	menuAddCall(list_menu, "Visa lista", list_menu_show, NULL);

	printf("\n--== Välkommen till Coronablinkern ==--\n");
	printf("\n            ## v0.1 ##\n");
	printf("\n---------------------------------------\n");
	
	while(menuSelection(main_menu))
	{
		printf("\n---------------------------------------\n");
	}
}

