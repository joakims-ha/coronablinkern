/*! \file */ 
#ifndef LIST
#define LIST

/*! \typedef list_item
    \brief List item
*/
typedef struct list_item
{
    int  id;
	time_t  date;
    struct list_item* prev;
    struct list_item* next;
}
list_item;

/*! \typedef list_t
    \brief List type
*/
typedef struct list_t
{
    list_item* first;
    list_item* last;
}
*list_t;

/*!
    Function for creating a new empty list.
    @returns A new empty list.
*/
list_t listCreate();

/*!
    Function for destroying a list.
    @param list The list to destroy.
*/
void listDestroy(list_t list);

/*!
    Function for adding a new item to a list
    @param list The list to add new item to.
    @param id Id number of the new entry.
    @param date Timestamp of the new entry.
*/
void listAdd(list_t list, int id, long int date);

/*!
    Function for removing old items from a list
    @param list The list to remove old items from.
    @param age Max age of items to keep in seconds.
*/
void listPrune(list_t list, long int age);

#endif