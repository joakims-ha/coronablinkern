#include "menu.h"

void menuAdd(menu_t *menu, int type, char *text, void *ptr1, void *ptr2)
{
    menu_i *newItem = malloc(sizeof(menu_t));
    newItem->type = type;
    newItem->text = text;
    newItem->ptr1 = ptr1;
    newItem->ptr2 = ptr2;
    menu->size++;
    menu->items[menu->size-1] = newItem; 
}

void menuAddCall(menu_t *parent, char *text, void *func, void *arg)
{
    menuAdd(parent, M_CALL, text, func, arg);
}

menu_t *menuCreate(menu_t *parent, char *title){    
    menu_t *newMenu = malloc(sizeof(menu_t));
    newMenu->parent = parent;
    newMenu->title = title;
    newMenu->size = 0;
    if(parent)
    {
        menuAdd(newMenu, M_QUIT, "Bakåt", parent, NULL);
        menuAdd(parent, M_MENU, newMenu->title, newMenu, NULL);
    }
    else
    {
        menuAdd(newMenu, M_QUIT, "Avsluta", parent, NULL);
    }
    return newMenu;
}

void menuShow(menu_t *menu)
{
    printf("\n ---[ %s ]---\n\n",menu->title);
    for(int i = 1; i <= menu->size-1; i++)
    {
        if(menu->items[i])
        {
            printf(" %i %s\n", i, menu->items[i]->text);
        }
    }
    printf("\n 0 %s\n", menu->items[0]->text);
}

int menuSelection(menu_t *menu)
{
	menuShow(menu);
    int input = userInput("-> ");
    if(input >= 0 && input <= menu->size)
    {
        if(menu->items[input]->type == M_MENU)
        {
            return menuSelection(menu->items[input]->ptr1);
        }
        else if(menu->items[input]->type == M_CALL)
        {
            int(*func)() = menu->items[input]->ptr1 ;
            return (func)(menu->items[input]->ptr2);
        }
        else if(menu->items[input]->type == M_QUIT)
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