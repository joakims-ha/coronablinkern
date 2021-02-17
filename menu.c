#include "menu.h"

menu_t *menuCreate(menu_t *parent, char *title){    
    menu_t *newMenu = malloc(sizeof(menu_t));
    newMenu->parent = parent;
    newMenu->title = title;
    newMenu->size = 0;

    menu_i *newItem = malloc(sizeof(menu_t));
    newItem->type = M_QUIT;
    if(parent)
    {
        newItem->ptr1 = parent;
        newItem->text = "Gå bakåt";
    }
    else
    {
        newItem->ptr1 = NULL;
        newItem->text = "Avsluta programmet";
    }
    newMenu->items[0] = newItem; 

    return newMenu;
}

void menuAdd(menu_t *menu, int type, char *text, void *ptr1, void *ptr2)
{
    menu_i *newItem = malloc(sizeof(menu_t));
    newItem->type = type;
    newItem->text = text;
    newItem->ptr1 = ptr1;
    newItem->ptr2 = ptr2;
    menu->size++;
    //menu->items = (menu_i *) realloc(menu->items, menu->size);
    menu->items[menu->size] = newItem; 
}

void menuAddMenu(menu_t *parent, char *text, void *menu)
{
    menuAdd(parent, M_MENU, text, menu, NULL);
}

void menuAddCall(menu_t *parent, char *text, void *func, void *arg)
{
    menuAdd(parent, M_CALL, text, func, arg);
}

void menuShow(menu_t *menu)
{
    printf("\n -[ %s ]-\n\n",menu->title);
    for(int i = 1; i <= menu->size; i++)
    {
        if(menu->items[i])
        {
            printf(" %i} %s\n", i, menu->items[i]->text);
        }
    }
    printf("\n 0} %s\n", menu->items[0]->text);
}

int menuSelection(menu_t *menu)
{
	menuShow(menu);
    int input = uiUserInput("-> ");
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