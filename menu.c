#include "menu.h"

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
    menu->items[menu->size-1] = newItem; 
}

void menuShow(menu_t *menu)
{
    printf("\n -[ %s ]-\n\n",menu->title);
    for(int i = 0; i <= menu->size; i++)
    {
        if(menu->items[i])
        {
            printf(" %i} %s\n", i+1, menu->items[i]->text);
        }
    }
    if(menu->parent)
    {
        printf("\n 0] Gå bakåt\n");
    }
    else
    {
        printf("\n 0] Avsluta programmet\n");
    }
}

int menuSelection(menu_t *menu)
{
	menuShow(menu);
    int input = uiUserInput("-> ");
    if(input >= 0 && input <= menu->size)
    {
        if(input!=0)
        {
            switch(menu->items[input-1]->type)
            {
                case M_MENU:
                    return menuSelection(menu->items[input-1]->link);
                case M_ITEM:
                    printf(" ");
                    void(*func)() = menu->items[input-1]->link;
				    (func)();
                    return 1;
                default:
                    printf("menuChoice() ERROR!\n");
            }
        }
        else
        {
            if(menu->parent)
            {
                return menuSelection(menu->parent);
            }
            else
            {
                return 0;
            }
        }
    }
    else
    {
        printf("\nOgiltigt val!\n");
        return menuSelection(menu);
    }
}