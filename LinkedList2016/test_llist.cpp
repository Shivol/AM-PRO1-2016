//
// Лабораторная работа №15. Двусвязный список
// test_llist.cpp
//
#include <cassert>
#include <iostream>
#include "llist.h"
#include "test_tlist.h"
#include "test_llist.h"

llist *get_array_llist(const llist::datatype *array, size_t length)
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
    test_get_array_list();
    tlist::datatype array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    size_t n = 10;
    tlist *tmplist = get_array_list(array, n);
    llist *end;
    llist *begin = get_list(tmplist, end);
    assert(end != nullptr);
    
    tlist *p1 = tmplist;
    llist *p2 = begin;
    while (p1 != nullptr) {
        assert(p1->data == p2->data);
        p1 = p1->next;
        p2 =p2->next;
    }

    delete[] tmplist;
    delete_list(begin);

#ifdef _DEBUG
    std::cerr << "test get_list(list): OK" << std::endl;
#endif
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