/*! \file */ 
#ifndef SIM
#define SIM

#include <stdio.h>
#include <stdlib.h>

#define __USE_XOPEN
#include <time.h>
#include "config.h"
#include "list.h"
#include "ui.h"

/*!
 *  Function for simulating contact
 *  @param list list of devices
*/
int simContact(list_t list);

/*!
 *  Function for simulating alert
 *  @param list list of devices
*/
int simAlert(list_t list);

/*!
 *  Function for simulating case
 *  @param list list of devices
*/
int simCase(list_t list);

#endif