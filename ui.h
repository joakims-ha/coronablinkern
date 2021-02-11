/*! \file */ 
#ifndef UI
#define UI

#include <stdlib.h>

typedef struct menu_t {
    struct menu_t *first;

}menu_t;


menu_t *menuCreate(menu_t *parent);

void menuAdd(menu_t *menu, int type, char *text);

void menuShow(menu_t *menu);


#endif