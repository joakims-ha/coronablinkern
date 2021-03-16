/*! \file */ 
#ifndef ACTIONS
#define ACTIONS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"
#include "config.h"

int userInput(char *prompt);
int actionsCreateList(contact_list list);
int actionsSaveList(contact_list list);
int actionsLoadList(contact_list list);
int showList(contact_list list);
int actionsPruneList(contact_list list);

int actionsAddContact(contact_list list);

void sendAlert();
int actionsSendAlert(contact_list list);

void reciveAlert(contact_list list, long int id);
int actionsReciveAlert(contact_list list);

#endif