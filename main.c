#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "list.h"
#include "sim.h"
#include "menu.h"
#include "ui.h"
#include "io.h"
#include "actions.h"

int main()
{	
	list_t devices = listCreate();
	
	menu_t *main_menu = menuCreate(NULL,"Huvudmeny");
	menu_t *sim_menu = menuCreate(main_menu,"Simulering");
	menu_t *list_menu = menuCreate(sim_menu,"Lista");
	
	menuAddCall(main_menu, "Rapportera fall", main_menu_case, NULL);
	menuAddMenu(main_menu, sim_menu);
	menuAddMenu(sim_menu, list_menu);

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

