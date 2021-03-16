#include "CUnit/Basic.h"
#include "list.h"

static contact_list list = NULL;

int init_suite_success(void) { return 0; }
int clean_suite_success(void) { return 0; }

void list_create(void)
{   
    list = listCreate();    
    CU_ASSERT_TRUE(list->size==0);
}

void list_add(void)
{   
    listAdd(list,1,3);
    CU_ASSERT(list->size==1);
    listAdd(list,2,1);
    listAdd(list,4,4);
    listAdd(list,3,2);
    CU_ASSERT_TRUE(list->size==4);
}

void list_sort(void)
{   
    CU_ASSERT(list->items[0].id==4);
    CU_ASSERT(list->items[1].id==1);
    CU_ASSERT(list->items[2].id==3);
    CU_ASSERT(list->items[3].id==2);
}

void list_prune(void)
{   
    listPrune(list,3);
    CU_ASSERT(list->size==2);
    CU_ASSERT(list->items[0].id==4);
    CU_ASSERT(list->items[1].id==1);
    listPrune(list,5);
    CU_ASSERT(list->size==0);
}

int main()
{	
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("List tests", init_suite_success, clean_suite_success);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if
    (
        (NULL == CU_add_test(pSuite, "create a new empty list", list_create)) ||
        (NULL == CU_add_test(pSuite, "add item to list", list_add)) ||
         (NULL == CU_add_test(pSuite, "item are sorted", list_sort)) ||
        (NULL == CU_add_test(pSuite, "old items removed", list_prune))
    )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all the tests */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    /* Clean up registry and return */
    CU_cleanup_registry();
    return CU_get_error();

}

