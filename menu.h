/*! \file */ 
#ifndef MENU
#define MENU

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "actions.h"

#define M_QUIT 0
#define M_MENU 1
#define M_CALL 2

/*! \typedef menu_i
 *  \brief Menu item
 */
typedef struct menu_i {
    int type;
    char *text;
    void *ptr1;
    void *ptr2;
}menu_i;

/*! \typedef menu_t
 *  \brief Menu
 */
typedef struct menu_t {
    char *title;
    int size;
    struct menu_t *parent;
    struct menu_i *items;
}menu_t;

/*!
 *  Function for creating a new menu.
 *  @param parent Parent meny, NULL if root menu.
 *  @param title Title of the menu.
 *  @returns A new menu.
 */
menu_t *menuCreate(menu_t *parent, char *title);

/*!
 *  Function for adding item to menu
 *  @param menu Menu to addd item to.
 *  @param text Name of menu item.
 *  @param func Function to call.
 *  @param arg Argument for function.
 */
void menuAddCall(menu_t *menu, char *text, void *func, void *arg);

/*!
 *  Function for displaying menu
 *  @param menu Menu to display.
 */
void menuShow(menu_t *menu);

/*!
 *  Function for getting menu choice
 *  @param menu Menu to get choice from.
 */
int menuSelection(menu_t *menu);

#endif