/*! \file */ 
#ifndef ACTIONS
#define ACTIONS

#define __USE_XOPEN

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"
#include "config.h"

int userInput(char *prompt);
int createContacts(contact_list list);
int saveList(contact_list list);
int loadList(contact_list list);
int pruneList(contact_list list);
int showList(contact_list list);
int addContact(contact_list list, long int id, char *date);
int sendAlert(contact_list list, int code);
int reciveAlert(contact_list list, long int id);

#endif