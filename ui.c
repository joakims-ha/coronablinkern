#include "ui.h"

menu_t *menuCreate(menu_t *parent, char *title){    
    menu_t *menu = malloc(sizeof(menu_t));
    menu->title = title;
    return menu;
}

void menuAdd(menu_t *menu, int type, char *text)
{
    menu_i *newItem = malloc(sizeof(menu_t));
    newItem->type = type;
    newItem->text = text;
    if(!menu->first)
	{
		newItem->next = NULL;
		menu->first = newItem;
	}
	else 
	{
        menu_i *item = menu->first;
		while(item->next)
        {
            item = item->next;
        }
        item->next = newItem;
	}
 
}

void menuShow(menu_t *menu)
{
    printf("## %s ##\n",menu->title);
    if(menu->first)
    {
        menu_i *item = menu->first;
        while(item)
        {
            printf("-- %s\n",item->text);
            item = item->next;
        }
    }
}

// Old code
int getMenuChoice()
{
    
	menu_t *main_menu = menuCreate(NULL,"Main menu");
	menuAdd(main_menu,1,"choice 1");
	menuAdd(main_menu,1,"choice 2");
	menuShow(main_menu);
	printf("\n");
	printf("  Välkommen till Coronablinkern\n");
	printf("=================================\n");
	printf("1) Simulera kontakt\n");
	printf("2) Simulera larm\n");
	printf("3) Rapportera fall\n");
	printf("\n");
	printf("0) Avsluta programmet\n");
	printf("---------------------------------\n");
	printf("> ");
	int m;
	scanf("%d", &m);
	while ((getchar()) != '\n'); 
	return m;
}
