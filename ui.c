#include "ui.h"

menu_t *menuCreate(menu_t *parent, char *title){    
    menu_t *newMenu = malloc(sizeof(menu_t));
    newMenu->parent = parent;
    newMenu->title = title;
    newMenu->size = 0;
    return newMenu;
}

void menuAdd(menu_t *menu, int type, char *text, void *link)
{
    menu_i *newItem = malloc(sizeof(menu_t));
    newItem->type = type;
    newItem->text = text;
    newItem->link = link;
    menu->size++;
    menu->items[menu->size] = newItem; 
}

void menuShow(menu_t *menu)
{
    printf("\n-[ %s ]-\n\n",menu->title);
    for(int i = 0; i <= menu->size; i++)
    {
        if(menu->items[i])
        {
            printf("%i} %s\n", i, menu->items[i]->text);
        }
    }
    if(menu->parent)
    {
        printf("\n0] Gå bakåt\n");
    }
    else
    {
        printf("\n0] Avsluta programmet\n");
    }
}

int menuChoice(menu_t *menu)
{
	menuShow(menu);
    int input = uiUserInput("-> ");
    if(input >= 0 && input <= menu->size)
    {
        if(input==0)
        {
            if(menu->parent)
            {
                return menuChoice(menu->parent);
            }
            else
            {
                return M_QUIT;
            }
        }
        else if(menu->items[input]->type == M_SUBMENU)
        {
            return menuChoice(menu->items[input]->link);
        }
        return input;
    }
    else
    {
        printf("Ogiltigt val!\n");
        return menuChoice(menu);
    }

}

void uiShowList(list_t list)
{
    	list_i *item = list->start;
		printf("\n--| Contact list |--\n\n");
		while (item)
		{
			printf("[%d] %s", item->id, ctime(&item->date));
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

