/*! \file */ 
#ifndef LIST
#define LIST

/*! \struct entry
    \brief List Entry.
    Entry to be added to a list.
*/
struct entry
{
    int  id;
	time_t  date;
    struct entry* prev;
    struct entry* next;
};

/*! \struct list_head
    \brief List Header.
    List header used to access first and last entry of a list.
*/
struct list_head {
    struct entry* first;
    struct entry* last;
};

typedef struct list_head* list;

/*!
    Function for creating a new empty list.
    @returns a new empty list.
*/
list listCreate();

/*!
    Function for destroying a list.
    @param list the list to destroy.
    @returns nothing.
*/
void listDestroy(list l);

/*!
    Function for adding a new entry to a list
    @param list the list to add to.
    @param id id of new entry.
    @param date timestamp of new entry.
    @returns nothing.
*/
void listAdd(list l, int id, long int date);

/*!
    Function for removing old entries from a list
    @param list the list remove from.
    @param date timestamp of oldest entries to keep.
    @returns nothing.
*/
void listPrune(list l, long int date);

#endif