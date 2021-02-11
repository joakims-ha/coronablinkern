/*! \file */ 
#ifndef SIM
#define SIM

#include <stdio.h>
#include <stdlib.h>

#define __USE_XOPEN
#include <time.h>
#include "list.h"
#include "ui.h"

/*!
 *  Function for simulating contact
 *  @param list list of devices
*/
void simContact(list_t list);

/*!
 *  Function for simulating alert
 *  @param list list of devices
*/
void simAlert(list_t list);

#endif