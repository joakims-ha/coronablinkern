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
	time_t now;
	list_t contacts = listCreate();
	
	menu_t *main_menu = menuCreate(NULL,"Huvudmeny");
	menu_t *sim_menu = menuCreate(main_menu,"Simulering");
	menu_t *list_menu = menuCreate(sim_menu,"Lista");
	
	menuAddCall(main_menu, "Rapportera fall", actionsSimulateCase, contacts);
	menuAddMenu(main_menu, sim_menu);
	menuAddMenu(sim_menu, list_menu);

	menuAddCall(sim_menu, "Simulera kontakt", simContact, contacts);
	menuAddCall(sim_menu, "Simulera larm", simAlert, contacts);

	menuAddCall(list_menu, "Generera lista", actionsCreateList, contacts);
	menuAddCall(list_menu, "Spara lista", actionsSaveList, contacts);
	menuAddCall(list_menu, "Ladda lista", actionsLoadList, contacts);
	menuAddCall(list_menu, "Visa lista", actionsShowList, contacts);

	printf("\n--== Välkommen till Coronablinkern ==--\n");
	printf("\n            ## v0.1 ##\n");
	printf("\n---------------------------------------\n");
	
	listLoad(contacts, FILE_NAME);
	time(&now);
	listPrune(contacts, now-MAX_AGE);
	while(menuSelection(main_menu))
	{
		time(&now);
		listPrune(contacts, now-MAX_AGE);
		listSave(contacts, FILE_NAME);
		printf("\n---------------------------------------\n");
	}
}

