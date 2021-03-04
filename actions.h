/*! \file */ 
#ifndef ACTIONS
#define ACTIONS

#include <time.h>
#include "list.h"
#include "config.h"

int actionsCreateList(list_t devices);
int actionsSaveList(list_t devices);
int actionsLoadList(list_t devices);
int actionsShowList(list_t devices);
int actionsSimulateCase(list_t devices);

#endif