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
    if(menu->parent)
    {
        printf("\n0] Gå bakåt\n");
    }
    else
    {
        printf("\n0] Avsluta programmet\n");
    }

}

int getUserInput()
{
    int m;
    printf("\n=> ");
	scanf("%d", &m);
	while ((getchar()) != '\n'); 
	return m;
}

// Old code
int getMenuChoice()
{
    
	menu_t *main_menu = menuCreate(NULL,"Huvudmeny");
	menuAdd(main_menu,1,"Simulera kontakt");
	menuAdd(main_menu,1,"Simulera larm");
    menuAdd(main_menu,1,"Rapportera fall");
    
    menu_t *sim_menu = menuCreate(main_menu,"Simulering");
	menuAdd(sim_menu,1,"Simulera kontakt");
	menuAdd(sim_menu,1,"Simulera larm");

	menuShow(main_menu);

	return getUserInput();
}
