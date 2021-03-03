#include "actions.h"

int sim_menu_list(list_t devices)
{
	time_t now;
	time(&now);
	int range = 21*24*60*60*2;
	for(int i = 1; i <= 10; i++)
    {
		listAdd(devices, rand(), now-(rand()%range));
    }
	return 1;
}

int list_menu_save(list_t devices)
{
	listSave(devices,"list.txt");
	return 1;
}

int list_menu_load(list_t devices)
{
	listLoad(devices,"list.txt");
	return 1;
}

int list_menu_show(list_t devices)
{
	uiShowList(devices);
	return 1;
}

int main_menu_case(list_t devices)
{
	if(uiUserInput("Ange öppningskod > ")==123)
	{
		if(!listIsEmpty(devices)) simCase(devices);
	}
	else
	{
		printf("\nFelaktig kod!\n");
	}
	return 1;
}
