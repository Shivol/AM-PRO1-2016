//
// Лабораторная работа №15. Двусвязный список
// test_llist.h
//
#pragma once
#include "llist.h"

llist *get_array_list(const llist::datatype *array, size_t length)
{
    assert(array != nullptr);
    tlist *arr_list = new llist[length];

    for (size_t i = 0; i < length; i++) {
        arr_list[i].data = array[i];
        arr_list[i].next = &arr_list[i+1];
        arr_list[i].prev = &arr_list[i-1];
    }
    arr_list[0].prev = nullptr;
    arr_list[length - 1].next = nullptr;

    return arr_list;
}

bool test_get_list_list();

bool test_llist_find();

bool test_llist_full();