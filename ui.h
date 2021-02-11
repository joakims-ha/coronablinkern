/*! \file */ 
#ifndef UI
#define UI

#include <stdio.h>
#include <stdlib.h>

#define M_SIM_CONTACT 1
#define M_SIM_ALERT 2
#define M_REPORT 3
#define M_QUIT 0

typedef struct menu_i {
    int type;
    char *text;
    struct menu_i *next;
}menu_i;

typedef struct menu_t {
    char *title;
    struct menu_i *first;

}menu_t;


menu_t *menuCreate(menu_t *parent, char *title);

void menuAdd(menu_t *menu, int type, char *text);

void menuShow(menu_t *menu);


#endif