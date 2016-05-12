//
// Лабораторная работа №13. Динамические структуры данных. Списки
// test_llist.cpp
//

#include <cassert>
#include <iostream>

#include "crtdynmem.h"
#include "llist.h"
#include "test_llist.h"
#include "test_tlist.h"
#include "tlist.h"

llist *get_array_llist(const llist::datatype *array, size_t length)
{
    assert(array != nullptr);
    llist *arr_list = new llist[length];

    for (size_t i = 0; i < length; i++) {
        arr_list[i].data = array[i];
        arr_list[i].next = &arr_list[i + 1];
        arr_list[i].prev = &arr_list[i - 1];
    }
    arr_list[0].prev = nullptr;
    arr_list[length - 1].next = nullptr;

    return arr_list;
}

bool test_get_llist_from_file()
{
    size_t n = 10;
    const char *tmpname = "list.tmp";
    // получаем тестовые данные
    llist::datatype *array = create_test_data(tmpname, n);

    // читаем данные из файла
    llist *end;
    llist *list = get_list(tmpname, end);
    
    // проверяем равенство прочитанного с исходным
    is_equal_test(list, array, n);

    // удаляем временные данные    
    delete[] array;
    remove(tmpname);
    delete_list(list);
#ifdef _DEBUG
    std::cerr << "test get_llist(filename): OK" << std::endl;
#endif
    return true;
}

bool test_get_array_llist()
{
    int n = 5;
    llist::datatype *array = new llist::datatype[n];
    for (int i = 0; i<n; i++) {
        array[i] = rand();
    }
    llist *list = get_array_llist(array, n);

    llist *p = list;
    int i = 0;
    while (p->next!= nullptr && i < n) {
        // проверяем структуру списка
        assert(p == &list[i]);
        // проверяем значения в списке
        assert(p->data == array[i]);
        i++;
        p = p->next;
    }

    // проверяем количество значений в списке
    assert(i + 1 == n);

    // обратный проход
    while (p->prev != nullptr && i > 0) {
        // проверяем структуру списка
        assert(p == &list[i]);
        // проверяем значения в списке
        assert(p->data == array[i]);
        i--;
        p = p->prev;
    }

    delete[] list;  // т.к. это - массив элементов tlist
    delete[] array;
#ifdef _DEBUG
    std::cerr << "test get_array_llist: OK" << std::endl;
#endif
    return true;
}
bool test_llist_find()
{
    // проверяем, что используемая функция корректна
    test_get_array_llist();
    // создаём массив тестовых данных
    size_t  n = 10;
    llist::datatype array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    llist *list = get_array_llist(array, n);

    // проверяем поиск существующих элементов
    for (size_t i = 0; i < n; i++)
        assert(find(list, array[i]) == &list[i]);

    //проверяем поиск не существующих элементов
    assert(find(list, -1) == nullptr);

    delete[] list;
#ifdef _DEBUG
    std::cerr << "test find(llist): OK" << std::endl;
#endif
    return true;
}

bool test_llist_full()
{
    return test_get_llist_from_file() &&
        test_llist_find();
}
