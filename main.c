#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "list.h"
#include "menu.h"
#include "ui.h"
#include "actions.h"

int main()
{	
	time_t now;
	contact_list contacts = listCreate();
	
	menu_t *main_menu = menuCreate(NULL,"Huvudmeny");
	menu_t *sim_menu = menuCreate(main_menu,"Simulering");
	menu_t *list_menu = menuCreate(sim_menu,"Lista");
	
	menuAddCall(main_menu, "Rapportera fall", actionsSimulateCase, contacts);
	menuAddMenu(main_menu, sim_menu);
	menuAddMenu(sim_menu, list_menu);

	menuAddCall(sim_menu, "Simulera kontakt", actionsSimulateContact, contacts);
	menuAddCall(sim_menu, "Simulera larm", actionsSimulateAlert, contacts);

	menuAddCall(list_menu, "Generera lista", actionsCreateList, contacts);
	menuAddCall(list_menu, "Spara lista", actionsSaveList, contacts);
	menuAddCall(list_menu, "Ladda lista", actionsLoadList, contacts);
	menuAddCall(list_menu, "Rensa lista", actionsPruneList, contacts);
	menuAddCall(list_menu, "Visa lista", actionsShowList, contacts);

	printf("\n--== Välkommen till Coronablinkern ==--\n");
	printf("\n            ## v0.1 ##\n");
	printf("\n---------------------------------------\n");
	
	listLoad(contacts, FILE_NAME);
	//time(&now);
	//listPrune(contacts, now-MAX_AGE);

	while(menuSelection(main_menu))
	{
		printf("\n---------------------------------------\n");
	}
	//time(&now);
	//listPrune(contacts, now-MAX_AGE);
	listSave(contacts, FILE_NAME);
}

