//
// Лабораторная работа №15. Двусвязный список
// test_llist.h
//
#pragma once
#include "llist.h"

// Тест функции чтения списка из файла
bool test_get_llist_from_file();

// Функция получения массива-списка для двусвязного списка
// Входные параметры:
//     array - массив значений элементов списка;
//     length - количество значений.
// Возвращает массив элементов llist.
llist *get_array_llist(const llist::datatype *array, size_t length);

// Тест функции
// llist *get_array_llist(const llist::datatype *array, size_t length)
// Проверка структуры полученного списка и значений.
bool test_get_array_llist();

// Тест шаблонной функции
// template <typename List, typename List_Data> List *find(const List *begin, List_Data x)
// Проверка существующих и не существующих элементов.
bool test_llist_find();

// Тестирование всех функций из llist
bool test_llist_full();

// Шаблонная функция тестирования равенства содержимого линейного списка с массивом
// Входные параметры:
//     begin -  указатель на начало списка;
//     array - массив значений элементов списка;
//     length - количество значений.
// Возвращает true, если значения в списке равны значениям в массиве.
template <typename List, typename List_Data>
bool is_equal_test(const List *begin, List_Data *array, size_t length)
{
    size_t count = 0;
    while (begin != nullptr && count < length) {
        // совпадение результата с исходными данными
        assert(begin->data == array[count]);
        begin = begin->next;
        count++;
    }
    // совпадение количества результатов с исходным количеством
    assert(count == length);
    return true;
}