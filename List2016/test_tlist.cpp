//
// Лабораторная работа №13. Динамические структуры данных. Списки
// test_tlist.cpp
//

#include <cassert>
#include <iostream>
#include "tlist.h"
#include "test_tlist.h"

array_list get_array_list(const tlist::datatype *array, size_t length)
{
    assert(array != nullptr);
    tlist *arr_list = new tlist[length];

    for (size_t i = 0; i < length; i++) {
        arr_list[i].data = array[i];
        arr_list[i].next = &arr_list[i+1];
    }
    arr_list[length - 1].next = nullptr;

    return arr_list;
}

bool test_find()
{
    int n = 6;
    tlist::datatype array[] = { 1,0,2,3,4,5 };
    array_list list = get_array_list(array, n);

    for (int i = 0; i < n; ++i) {
        tlist *p = find(list, array[i]);
        assert(p == &list[i]);
    }
    
    tlist *p = find(list, -1);
    assert(p == nullptr);

    delete[] list;
#ifdef _DEBUG
    std::cerr << "test find: OK" << std::endl;
#endif
    return true;

}