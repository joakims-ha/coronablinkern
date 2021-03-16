#include "actions.h"

int userInput(char *prompt)
{
    int c, m;
    printf("\n%s",prompt);
	scanf("%d", &m);
    while ((c = getchar()) != '\n' && c != EOF);
	return m;
}

int actionsCreateList(contact_list list)
{
	time_t now;
	time(&now);
	int range = MAX_AGE*2;
	for(int i = 1; i <= 10; i++)
    {
		listAdd(list, rand(), now-(rand()%range));
    }
	return 1;
}

int actionsSaveList(contact_list list)
{
	listSave(list, FILE_NAME);
	return 1;
}

int actionsLoadList(contact_list list)
{
	listLoad(list, FILE_NAME);
	return 1;
}

int actionsPruneList(contact_list list)
{
	time_t now;
	time(&now);
	listPrune(list, now-MAX_AGE);
	return 1;
}

int showList(contact_list list)
{
	printf("\n------------| Kontakter |--------------\n\n");
	for(int i=0;i<list->size;i++)
	{
		printf("[%12.12li] %s", list->items[i].id, ctime(&list->items[i].date));
	}
	printf("\n---------------------------------------\n");
	return 1;
}

int actionsAddContact(contact_list list)
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

void sendAlert()
{
	printf("\nSkickar öppnings kod(%i) och enhets id(%i) till server.\n",DEVICE_CODE,DEVICE_ID);

}

int actionsSendAlert(contact_list list)
{
	if(userInput("Ange öppningskod > ")==DEVICE_CODE)
	{
		sendAlert();
	}
	else
	{
		printf("\nFelaktig kod!\n");
	}
	return 1;
}

void reciveAlert(contact_list list, long int id)
{
	time_t now;
	time(&now);
	listPrune(list, now-MAX_AGE);
	if(listIdExist(list,id))
	{
		printf("\n!!! Du har varit i kontakt med smittad !!!\n");
	}
	else
	{
		printf("\nIngen kontakt funnen!\n");
	}
}

int actionsReciveAlert(contact_list list)
{
	reciveAlert(list,userInput("id > "));
	return 1;
}
