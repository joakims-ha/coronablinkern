/*! \file */ 
#ifndef MENU
#define MENU

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ui.h"

#define M_QUIT 0
#define M_MENU 1
#define M_CALL 2

typedef struct menu_i {
    int type;
    char *text;
    void *ptr1;
    void *ptr2;
}menu_i;

typedef struct menu_t {
    char *title;
    int size;
    struct menu_t *parent;
    struct menu_i *items[10]; // Make dynamic !!!
}menu_t;


menu_t *menuCreate(menu_t *parent, char *title);

void menuAddMenu(menu_t *parent, char *text, void *menu);

void menuAddCall(menu_t *menu, char *text, void *func, void *arg);

void menuShow(menu_t *menu);

int menuSelection(menu_t *menu);

#endif