#include "actions.h"

int actionsCreateList(contact_list devices)
{
	time_t now;
	time(&now);
	int range = MAX_AGE*2;
	for(int i = 1; i <= 10; i++)
    {
		listAdd(devices, rand(), now-(rand()%range));
    }
	return 1;
}

int actionsSaveList(contact_list devices)
{
	listSave(devices, FILE_NAME);
	return 1;
}

int actionsLoadList(contact_list devices)
{
	listLoad(devices, FILE_NAME);
	return 1;
}

int actionsPruneList(contact_list devices)
{
	time_t now;
	time(&now);
	listPrune(devices, now-MAX_AGE);
	return 1;
}

int actionsShowList(contact_list devices)
{
	uiShowList(devices);
	return 1;
}

int actionsSimulateCase(contact_list devices)
{
	if(uiUserInput("Ange öppningskod > ")==DEVICE_CODE)
	{
		simCase(devices);
	}
	else
	{
		printf("\nFelaktig kod!\n");
	}
	return 1;
}
