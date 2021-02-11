#include "ui.h"

menu_t *menuCreate(menu_t *parent, char *title){    
    menu_t *newMenu = malloc(sizeof(menu_t));
    newMenu->parent = parent;
    newMenu->title = title;
    return newMenu;
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
    printf("\n-[ %s ]-\n\n",menu->title);
    if(menu->first)
    {
        int count = 1;
        menu_i *item = menu->first;
        while(item)
        {
            printf("%i} %s\n",count, item->text);
            item = item->next;
            count++;
        }
    }
	printf("\n0] Avsluta programmet\n");

}

// Old code
int getMenuChoice()
{
    
	menu_t *main_menu = menuCreate(NULL,"Huvudmeny");
	menuAdd(main_menu,1,"Simulera kontakt");
	menuAdd(main_menu,1,"Simulera larm");
    menuAdd(main_menu,1,"Rapportera fall");
    
	menuShow(main_menu);
	printf("\n=> ");
	int m;
	scanf("%d", &m);
	while ((getchar()) != '\n'); 
	return m;
}
