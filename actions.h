/*! \file */ 
#ifndef ACTIONS
#define ACTIONS

#include <time.h>
#include <string.h>
#include "list.h"
#include "ui.h"
#include "config.h"

int actionsCreateList(contact_list devices);
int actionsSaveList(contact_list devices);
int actionsLoadList(contact_list devices);
int actionsShowList(contact_list devices);
int actionsPruneList(contact_list devices);
int actionsSimulateCase(contact_list devices);
int actionsSimulateContact(contact_list list);
int actionsSimulateAlert(contact_list list);

#endif