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
		printf("\nÖppningskod mottagen:\n");
		printf("- Tar bort föråldrade kontakter\n");
		time_t now;
		time(&now);
		long int max = now-MAX_AGE;
		listPrune(devices, max);
		printf("- Sänder information till servern\n");
		uiShowList(devices);
	}
	else
	{
		printf("\nFelaktig kod!\n");
	}
	return 1;
}

int actionsSimulateContact(contact_list list)
{
	int i = uiUserInput("Ange enhetens id > ");

	printf("\nAnge datum i formatet 'YY-MM-DD HH:MM:SS' > ");
	char d[18];
	fgets(d, 18, stdin);
	
	struct tm tm;
	time_t epoch;
	// need check for leap year
	if (strptime(d, "%y-%m-%d %H:%M:%S", &tm) != 0)
	{
		epoch = mktime(&tm);
		if(i!=0)
		{
			listAdd(list, i, epoch);
		} 
		else 
		{
			listAdd(list, rand(), epoch);
		}
	}
	else
	{
		printf("\nOgiltigt datum!");
	}
	return 1;
}

int actionsSimulateAlert(contact_list list)
{
	printf("\nSmittlarm mottaget. Meddelar servern.\n\n");
	uiShowList(list);
	return 1;
}