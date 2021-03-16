#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "list.h"
#include "menu.h"
#include "actions.h"


int main(int argc, char *argv[])
{	
	printf("\n--== Välkommen till Coronablinkern ==--\n");
	
	if( argc == 2 ) {
    	printf("The argument supplied is %s\n", argv[1]);
	}
	else if( argc > 2 ) {
		printf("Too many arguments supplied.\n");
	}

	time_t now;
	contact_list contacts = listCreate();
	
	menu_t *main_menu = menuCreate(NULL,"Huvudmeny");
	menu_t *test_menu = menuCreate(main_menu,"Testning");
	menu_t *sim_menu = menuCreate(test_menu,"Simulering");
	menu_t *list_menu = menuCreate(test_menu,"Lista");

	menuAddCall(main_menu, "Rapportera fall", actionsSimulateCase, contacts);
	menuAddMenu(main_menu, test_menu);

	menuAddCall(sim_menu, "Simulera kontakt", actionsSimulateContact, contacts);
	menuAddCall(sim_menu, "Simulera larm", actionsSimulateAlert, contacts);

	menuAddCall(list_menu, "Spara lista", actionsSaveList, contacts);
	menuAddCall(list_menu, "Ladda lista", actionsLoadList, contacts);
	menuAddCall(list_menu, "Rensa lista", actionsPruneList, contacts);
	menuAddCall(list_menu, "Visa lista", actionsShowList, contacts);

	menuAddCall(test_menu, "Generera kontakter", actionsCreateList, contacts);
	menuAddMenu(test_menu, sim_menu);
	menuAddMenu(test_menu, list_menu);
	
	listLoad(contacts, FILE_NAME);
	time(&now);
	listPrune(contacts, now-MAX_AGE);
	while(menuSelection(main_menu))
	time(&now);
	listPrune(contacts, now-MAX_AGE);
	listSave(contacts, FILE_NAME);
}