#include "sim.h"

int simContact(list_t list)
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

int simAlert(list_t list)
{
	printf("\nSmittlarm mottaget. Meddelar servern.\n\n");
	uiShowList(list);
	return 1;
}

int simCase(list_t list)
{
	printf("\nÖppningskod mottagen:\n");
	printf("- Tar bort föråldrade kontakter\n");
	time_t now;
	time(&now);
	long int max = now-MAX_AGE;
	listPrune(list, max);
	printf("- Sänder information till servern\n");
	uiShowList(list);
	return 1;
}