/*  Joakim Salmén 
    Programmering 2
	Coronablinker
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct entry
{
    int  id;
	time_t  timestamp;
    struct entry* prev;
    struct entry* next;
};
struct list_head {
    struct entry* first;
    struct entry* last;
};

typedef struct list_head* list;

list device_log;


list createList()
{
    list l = (list) malloc(sizeof(struct list_head));
    l->first = NULL;
    l->last = NULL;
    return l;
}

void addEntry(int id)
{
	struct entry* newEntry = (struct entry*) malloc(sizeof(struct entry));
	newEntry->id = id;
	time(&newEntry->timestamp);
	newEntry->prev = NULL;
	if(!device_log->first)
	{
		newEntry->next = NULL;
		device_log->first = newEntry;
		device_log->last = newEntry;
	} else {
		newEntry->next = device_log->last;
		device_log->last->prev = newEntry;
		device_log->last = newEntry;
	}
}

void showList()
{
	struct entry* tmp = device_log->first;
    int l = 1;
    while (tmp)
    {
        printf("%d %s\n",tmp->id,ctime(&tmp->timestamp));
        tmp = tmp->prev;
    }
}



void init()
{
	// Create unique device id
	device_log = createList();
}

int showMenu()
{
	// Display menu and get choice
	printf("\n");
	printf("  Välkommen till Coronablinkern\n");
	printf("=================================\n");
	printf("1) Lägg till enhet som varit nära\n");
	printf("2) Larm om smitta mottaget\n");
	printf("3) Meddela om smitta\n");
	printf("\n");
	printf("4) Avsluta programmet\n");
	printf("---------------------------------\n");
	printf("> ");
	int m;
	scanf("%d", &m);
	while ((getchar()) != '\n'); 
	return m;
}

void logDevice()
{
	// Add device to list of contacts
	printf("\n");
	printf("Ange enhetens id > ");
	int id;
	scanf("%d", &id);
	addEntry(id);
	showList();
}

void uploadLog()
{
	// Send log of devices to server
}

int main()
{	
	init();
	while(1)
	{
		switch(showMenu())
		{
			case 1:
				logDevice();
				break;
			case 2:
				printf("Larm\n");
				break;
			case 3:
				printf("Meddela\n");
				break;
			case 4:
				printf("Hejdå\n");
				return 0;
			default:
				printf("Felakting val\n");
		}
		printf("\n");
	}
}

