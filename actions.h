/*! \file */ 
#ifndef ACTIONS
#define ACTIONS

#include <time.h>
#include "list.h"

int sim_menu_list(list_t devices);
int list_menu_save(list_t devices);
int list_menu_load(list_t devices);
int list_menu_show(list_t devices);
int main_menu_case(list_t devices);

#endif