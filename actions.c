#include "actions.h"

int userInput(char *prompt)
{
    int c, m;
    printf("\n%s",prompt);
	scanf("%d", &m);
    while ((c = getchar()) != '\n' && c != EOF);
	return m;
}

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
	showList(devices);
	return 1;
}

int actionsSimulateCase(contact_list devices)
{
	if(userInput("Ange öppningskod > ")==DEVICE_CODE)
	{
		printf("\nÖppningskod mottagen:\n");
		printf("- Tar bort föråldrade kontakter\n");
		time_t now;
		time(&now);
		long int max = now-MAX_AGE;
		listPrune(devices, max);
		printf("- Sänder information till servern\n");
		showList(devices);
	}
	else
	{
		printf("\nFelaktig kod!\n");
	}
	return 1;
}

int actionsSimulateContact(contact_list list)
{
	int id = userInput("Ange enhetens id > ");
	printf("\nAnge datum i formatet 'YY-MM-DD HH:MM:SS' > ");
	char date_in[18];
	fgets(date_in, 18, stdin);
	time_t epoch;
	struct tm tm;
	int r = strptime(date_in, "%y-%m-%d %H:%M:%S", &tm);
	char *day1, *day2;
	if (r != 0)
	{
		epoch = mktime(&tm);
		day1 = strtok(strtok(date_in, " "), "-");
		day1 = strtok(NULL, "-");
		day1 = strtok(NULL, "-");
		day2 = strtok(ctime(&epoch), " ");
		day2 = strtok(NULL, " ");
		day2 = strtok(NULL, " ");
	}
	if (r != 0 && (atoi(day1) == atoi(day2)))
	{
		listAdd(list, id, epoch);
	}
	else
	{
		printf("\nOgiltigt datum!\n");
	}
	return 1;
}

int actionsSimulateAlert(contact_list list)
{
	printf("\nSmittlarm mottaget. Meddelar servern.\n\n");
	showList(list);
	return 1;
}

void showList(contact_list list)
{
	printf("\n-------------| Contacts |--------------\n\n");
	for(int i=0;i<list->size;i++)
	{
		printf("[%12.12li] %s", list->items[i].id, ctime(&list->items[i].date));
	}
	printf("\n---------------------------------------\n");
}
