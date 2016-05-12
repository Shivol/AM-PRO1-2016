//
// Лабораторная работа №15. Двусвязный список
// test_llist.cpp
//
#include <cassert>
#include "llist.h"
#include "test_tlist.h"
#include "test_llist.h"

llist *get_array_list(const llist::datatype *array, size_t length)
{
    assert(array != nullptr);
    llist *arr_list = new llist[length];

    for (size_t i = 0; i < length; i++) {
        arr_list[i].data = array[i];
        arr_list[i].next = &arr_list[i+1];
        arr_list[i].prev = &arr_list[i-1];
    }
    arr_list[0].prev = nullptr;
    arr_list[length - 1].next = nullptr;

    return arr_list;
}

bool test_get_list_list()
{
    return true;
}

bool test_llist_find()
{
    return true;
}

bool test_llist_full()
{
    return test_get_list_list() &&
        test_llist_find();
}