#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "list.h"
#include "sim.h"
#include "ui.h"

int main()
{	
	// menu_t *main_menu = menuCreate(NULL,"Huvudmeny");
	// menu_t *sim_menu = menuCreate(main_menu,"Simulering");

	// menuAdd(main_menu, M_SUBMENU, "Simulering", sim_menu);
	// menuAdd(main_menu, M_ITEM, "Rapportera fall", NULL);

	// menuAdd(sim_menu, M_ITEM, "Simulera kontakt", NULL);
	// menuAdd(sim_menu, M_ITEM, "Simulera larm", NULL);

	menu_t *main_menu = menuCreate(NULL,"Huvudmeny");

	menu_t *sub_menu1 = menuCreate(main_menu,"Undermeny | 1");
	menu_t *sub_menu2 = menuCreate(main_menu,"Undermeny | 2");
	menu_t *sub_menu3 = menuCreate(main_menu,"Undermeny | 3");

	menuAdd(main_menu, M_SUBMENU, "Undermeny 1", sub_menu1);
	menuAdd(main_menu, M_SUBMENU, "Undermeny 2", sub_menu2);
	menuAdd(main_menu, M_SUBMENU, "Undermeny 3", sub_menu3);

	menuAdd(sub_menu1, M_ITEM, "Meny 1.1", NULL);
	menuAdd(sub_menu1, M_ITEM, "Meny 1.2", NULL);

	menuAdd(sub_menu2, M_ITEM, "Meny 2.1", NULL);
	menuAdd(sub_menu2, M_ITEM, "Meny 2.2", NULL);

	menuAdd(sub_menu3, M_ITEM, "Meny 3.1", NULL);
	menuAdd(sub_menu3, M_ITEM, "Meny 3.2", NULL);

	printf("\n --== Välkommen till Coronablinkern ==--\n             ## v0.1 ##\n");
	list_t devices = listCreate();
	while(1)
	{
		switch(menuChoice(main_menu))
		{
			// case M_SIM_CONTACT:
			// 	simContact(devices);
			// 	break;
			// case M_SIM_ALERT:
			// 	simAlert(devices);
			// 	break;
			// case M_REPORT:
			// 	if(uiUserInput("Ange öppningskod > ")==DEVICE_CODE)
			// 	{
			// 		if(!listIsEmpty(devices)) simCase(devices);
			// 	}
			// 	else
			// 	{
			// 		printf("\nFelaktig kod!\n");
			// 	}
			// 	break;
			case M_QUIT:
				printf("Hejdå\n");
				listDestroy(devices);
				return 0;
			default:
				printf("ERROR!\n");
		}
	}
}

