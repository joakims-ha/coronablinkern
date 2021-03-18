#include <stdio.h>
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
	menuAddCall(main_menu, "Rapportera fall", sendAlert, contacts);
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
			menuAddCall(sim_menu, "Simulera kontakt", addContact, contacts);
			menuAddCall(sim_menu, "Simulera larm", reciveAlert, contacts);
			menuAddCall(list_menu, "Spara lista", saveList, contacts);
			menuAddCall(list_menu, "Ladda lista", loadList, contacts);
			menuAddCall(list_menu, "Rensa lista", pruneList, contacts);
			menuAddCall(list_menu, "Visa lista", showList, contacts);
			menuAddCall(test_menu, "Generera kontakter", createContacts, contacts);
			printf("\nTestning av Coronablinkern\n");
			while(menuSelection(main_menu));
		}
		else if(!strcmp(argv[1], "help"))
		{
			printf("Help text\n");
		}
		else if(!strcmp(argv[1], "debug"))
		{
			showList(contacts);
		}
		else if(!strcmp(argv[1], "sick"))
		{
			printf("Id saknas!\n");
		}
		else if(!strcmp(argv[1], "add"))
		{
			printf("Id och datum saknas!\n");
		}
		else
		{
			printf("Ogiltigt kommando!\n");
		}
	}
	else if(argc == 3)
	{
		if(!strcmp(argv[1], "sick"))
		{
			sendAlert(contacts, atoi(argv[2]));
		}
		else if(!strcmp(argv[1], "check"))
		{
			reciveAlert(contacts, atoi(argv[2]));
		}
		else if(!strcmp(argv[1], "add"))
		{
			printf("Datum saknas!\n");
		}
		else
		{
			printf("Ogiltigt kommando!\n");
		}
	}
	else if(argc == 5)
	{
		if(!strcmp(argv[1], "add"))
		{
			printf("Ogiltigt datum!\n");
		}
		else
		{
			printf("Ogiltigt kommando!\n");
		}
	}
	else if(argc == 5)
	{
		if(!strcmp(argv[1], "add"))
		{
			char date[18];
			strcpy(date, argv[3]);
			strcat(date, " ");
			strcat(date, argv[4]);
			addContact(contacts, atoi(argv[2]), date);
		}
		else
		{
			printf("Ogiltigt kommando!\n");
		}
	}
	time(&now);
	listPrune(contacts, now-MAX_AGE);
	listSave(contacts, FILE_NAME);
	listDestroy(contacts);
}