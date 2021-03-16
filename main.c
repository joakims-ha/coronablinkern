#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "config.h"
#include "list.h"
#include "menu.h"
#include "actions.h"


int main(int argc, char *argv[])
{	
	time_t now;
	contact_list contacts = listCreate();
	listLoad(contacts, FILE_NAME);
	time(&now);
	listPrune(contacts, now-MAX_AGE);
	menu_t *main_menu = menuCreate(NULL,"Huvudmeny");
	menuAddCall(main_menu, "Rapportera fall", actionsSendAlert, contacts);
	if(argc == 1)
	{
		printf("\n--== Välkommen till Coronablinkern ==--\n");
		while(menuSelection(main_menu));
	}
	else if(argc == 2)
	{
		if(!strcmp(argv[1], "testing"))
		{
			menu_t *test_menu = menuCreate(main_menu,"Testning");
			menu_t *sim_menu = menuCreate(test_menu,"Simulering");
			menu_t *list_menu = menuCreate(test_menu,"Lista");
			menuAddMenu(main_menu, test_menu);
			menuAddMenu(test_menu, sim_menu);
			menuAddMenu(test_menu, list_menu);
			menuAddCall(sim_menu, "Simulera kontakt", actionsAddContact, contacts);
			menuAddCall(sim_menu, "Simulera larm", actionsReciveAlert, contacts);
			menuAddCall(list_menu, "Spara lista", actionsSaveList, contacts);
			menuAddCall(list_menu, "Ladda lista", actionsLoadList, contacts);
			menuAddCall(list_menu, "Rensa lista", actionsPruneList, contacts);
			menuAddCall(list_menu, "Visa lista", showList, contacts);
			menuAddCall(test_menu, "Generera kontakter", actionsCreateList, contacts);
			printf("\nTestning av Coronablinkern\n");
			while(menuSelection(main_menu));
		}
		if(!strcmp(argv[1], "sick"))
		{
			sendAlert();
		}
		if(!strcmp(argv[1], "debug"))
		{
			actionsShowList(contacts);
		}
	}
	else if(argc == 3)
	{
		if(!strcmp(argv[1], "check"))
		{
			reciveAlert(contacts, atoi(argv[2]));
		}
	}
	time(&now);
	listPrune(contacts, now-MAX_AGE);
	listSave(contacts, FILE_NAME);
	listDestroy(contacts);
}