#include "sim.h"

void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void simContact(list_t list)
{
	// Simulate device contact
	printf("\nAnge enhetens id > ");
	int i;
	scanf("%d", &i);
	flush();

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
}

void simAlert(list_t list)
{
	// Simulate receiving alert
	printf("\nSmittlarm mottaget. Sänder information till servern.\n\n");
	list_i *item = list->start;
	printf("\tID\t\t\t\tTID\n");
	printf("--------------------------------------------------------\n");
    while (item)
    {
        printf("%d\t\t\t%s",item->id,ctime(&item->date));
        item = item->next;
    }
}

