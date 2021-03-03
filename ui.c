#include "ui.h"

void uiShowList(list_t list)
{
    	list_i *item = list->start;
		printf("\n--| Contact list |--\n\n");
		while (item)
		{
			printf("[%12.12d] %s", item->id, ctime(&item->date));
			item = item->next;
		}
}

void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int uiUserInput(char *prompt)
{
    int m;
    printf("\n%s",prompt);
	scanf("%d", &m);
    flush();
	return m;
}
