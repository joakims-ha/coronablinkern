#include "ui.h"

void uiShowList(contact_list list)
{
		printf("\n--| Contact list |--\n\n");
		for(int i=0;i<list->size;i++)
		{
			printf("[%12.12li] %s", list->items[i].id, ctime(&list->items[i].date));
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
