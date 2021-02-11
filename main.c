#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "list.h"
#include "sim.h"
#include "ui.h"

int main()
{	
	printf("\n --== Välkommen till Coronablinkern ==--\n             ## v0.1 ##\n");
	list_t devices = listCreate();
	while(1)
	{
		switch(getMenuChoice())
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
					simCase(devices);
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

