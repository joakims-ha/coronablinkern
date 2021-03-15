#include "actions.h"

int actionsCreateList(list_t devices)
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

int actionsSaveList(list_t devices)
{
	listSave(devices, "list.bin");
	return 1;
}

int actionsLoadList(list_t devices)
{
	listLoad(devices, "list.bin");
	return 1;
}

int actionsShowList(list_t devices)
{
	uiShowList(devices);
	return 1;
}

int actionsSimulateCase(list_t devices)
{
	if(uiUserInput("Ange öppningskod > ")==DEVICE_CODE)
	{
		if(!listIsEmpty(devices)) simCase(devices);
	}
	else
	{
		printf("\nFelaktig kod!\n");
	}
	return 1;
}
