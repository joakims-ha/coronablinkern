/*! \file */ 
#ifndef LIST
#define LIST

#include <stdlib.h>
#include <stdbool.h>

/*! \typedef list_i
 *  \brief List item
 */
typedef struct list_i
{
    int  id;
    long int  date;
    struct list_i *next;
    struct list_i *prev;
}
list_i;

/*! \typedef list_t
 *  \brief List
 */
typedef struct list_t
{
    list_i *start;
}
*list_t;

/*!
 *  Function for creating a new empty list.
 *  @returns A new empty list.
 */
list_t listCreate();

/*!
 *  Function for destroying a list.
 *  @param list The list to destroy.
 */
void listDestroy(list_t list);

/*!
 *  Function for adding a new item to a list
 *  @param list The list to add new item to.
 *  @param id Id number of the new entry.
 *  @param date Timestamp of the new entry.
 */
void listAdd(list_t list, int id, long int date);

/*!
 *  Function for removing old items from a list
 *  @param list The list to remove old items from.
 *  @param age Max age of items to keep in seconds.
 */
void listPrune(list_t list, long int age);

/*!
 *  Function for checking if list is empty.
 *  @param list The list to check.
 */
bool listIsEmpty(list_t list);

/*!
 *  Function for getting length of list.
 *  @param list The list to get length of.
 *  @returns Number of items in list.
 */
int listLength(list_t list);

#endif