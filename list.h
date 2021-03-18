/*! \file */ 
#ifndef LIST
#define LIST

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*! \typedef contact
 *  \brief Contact list item
 */
typedef struct contact_i
{
    long int  id;
    long int  date;
}
contact;

/*! \typedef contact_list
 *  \brief List of contacts
 */
typedef struct contact_l
{
    int size;
    contact *items;
}
*contact_list;

/*!
 *  Function for creating a new empty list.
 *  @returns A new empty list.
 */
contact_list listCreate();

/*!
 *  Function for destroying a list.
 *  @param list The list to destroy.
 */
void listDestroy(contact_list list);

/*!
 *  Function for adding a new item to a list
 *  @param list The list to add new item to.
 *  @param id Id number of the new entry.
 *  @param date Timestamp of the new entry.
 */
void listAdd(contact_list list, long int id, long int date);

/*!
 *  Function for removing old items from a list
 *  @param list The list to remove old items from.
 *  @param age Max age of items to keep in seconds.
 */
void listPrune(contact_list list, long int age);

/*!
 *  Function for checking if id exist in list
 *  @param list The list to check.
 *  @param id Id to look for.
 */
bool listIdExist(contact_list list, long int id);

/*!
 *  Function for saving a list to file
 *  @param list The list to save.
 *  @param file Name of file to save to.
 */
void listSave(contact_list list, char *file);

/*!
 *  Function for loading a list from file
 *  @param list The list to load to.
 *  @param file Name of file to load from.
 */
void listLoad(contact_list list, char *file);

#endif