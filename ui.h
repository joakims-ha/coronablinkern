/*! \file */ 
#ifndef UI
#define UI

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "list.h"

#define M_SIM_CONTACT 1
#define M_SIM_ALERT 2
#define M_REPORT 3
#define M_QUIT 0

#define M_SUBMENU 5
#define M_ITEM 6
typedef struct menu_i {
    int type;
    char *text;
    void *link;
}menu_i;

typedef struct menu_t {
    char *title;
    int size;
    struct menu_t *parent;
    struct menu_i *items[10];

}menu_t;


menu_t *menuCreate(menu_t *parent, char *title);

void menuAdd(menu_t *menu, int type, char *text);

void menuShow(menu_t *menu);

int menuChoice(menu_t *menu);

void uiShowList(list_t list);

int uiUserInput(char *prompt);

int menuChoice();

#endif