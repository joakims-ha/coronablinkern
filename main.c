#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "list.h"
#include "sim.h"
#include "ui.h"

int main()
{	
	menu_t *main_menu = menuCreate(NULL,"Huvudmeny");
	menuAdd(main_menu,1,"Simulera kontakt");
	menuAdd(main_menu,1,"Simulera larm");
	menuAdd(main_menu,1,"Rapportera fall");

	// menu_t *sim_menu = menuCreate(main_menu,"Simulering");
	// menuAdd(sim_menu,1,"Simulera kontakt");
	// menuAdd(sim_menu,1,"Simulera larm");

	printf("\n --== Välkommen till Coronablinkern ==--\n             ## v0.1 ##\n");
	list_t devices = listCreate();
	while(1)
	{
		switch(menuChoice(main_menu))
		{
			case M_SIM_CONTACT:
				simContact(devices);
				break;
			case M_SIM_ALERT:
				simAlert(devices);
				break;
			case M_REPORT:
				if(uiUserInput("Ange öppningskod > ")==DEVICE_CODE)
				{
					if(!listIsEmpty(devices)) simCase(devices);
				}
				else
				{
					printf("\nFelaktig kod!\n");
				}
				break;
			case M_QUIT:
				printf("Hejdå\n");
				listDestroy(devices);
				return 0;
			default:
				printf("Felakting val!\n");
		}
		printf("\n");
	}
}

