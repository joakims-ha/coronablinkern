#include "actions.h"

int userInput(char *prompt)
{
    int c, m;
    printf("\n%s",prompt);
	scanf("%d", &m);
    while ((c = getchar()) != '\n' && c != EOF);
	return m;
}

int createContacts(contact_list list)
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

int saveList(contact_list list)
{
	listSave(list, FILE_NAME);
	return 1;
}

int loadList(contact_list list)
{
	listLoad(list, FILE_NAME);
	return 1;
}

int pruneList(contact_list list)
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

int addContact(contact_list list, long int id, char *date)
{
	char date_in[18];
	if(!id || id==0)
	{
		id = userInput("Ange enhetens id > ");
		printf("\nAnge datum i formatet 'YY-MM-DD HH:MM:SS' > ");
		fgets(date_in, 18, stdin);
		printf("\n");
	}
	else 
	{
		strcpy(date_in, date);
	}
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
		printf("Ogiltigt datum!\n");
	}
	return 1;
}

int sendAlert(contact_list list, int code)
{
	if(!code || code==0)
	{
		code = userInput("Ange öppningskod > ");
	}
	if(code==DEVICE_CODE)
	{
		printf("Skickar enhets id(%i) till server.\n",DEVICE_ID);
	}
	else
	{
		printf("Felaktig kod!\n");
	}
	return 1;
}

int reciveAlert(contact_list list, long int id)
{
	if(!id || id==0)
	{
		id = userInput("id > ");
	}
	time_t now;
	time(&now);
	listPrune(list, now-MAX_AGE);
	if(listIdExist(list,id))
	{
		printf("!!! Du har varit i kontakt med smittad !!!\n");
	}
	else
	{
		printf("Ingen kontakt funnen!\n");
	}
	return 1;
}
