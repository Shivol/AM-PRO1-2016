//
// Лабораторная работа №15. Двусвязный список
// llist.h
//
#pragma once
#include "tlist.h"

// Узел двусвязного списка:
//     llist::datatype - тип данных списка;
//     data - значение в узле списка;
//     prev - указатель на предидущий элемент;
//     next - указатель на следующий элемент.
struct llist
{
    typedef int datatype;
    datatype data;
    llist *prev;
    llist *next;
};

// Функция создания двусвязного списка на основе односвязного.
// Входные параметры:
//     filename - имя файла данных.
// Выходные праметры:
//     end - указатель на конец списка.
// Возвращает указатель на первый элемент нового списка.
llist *get_list(const char *filename, llist *&end);

// Шаблонная функция удаления линейного списка.
// Входные параметры:
//     begin - указатель на начало списка.
// Выходное значение параметра begin равно nullptr.
template <typename List>
void delete_list(List *&begin)
{
    while (begin != nullptr) {
        List *t = begin;
        begin = begin->next;
        delete t;
    }
}

// Шаблонная функция вывода линейного списка на консоль.
// Входные параметры:
//     begin - указатель на начало списка.
template <typename List>
void print_list(const List *begin) 
{
    while (begin != nullptr) {
        cout << begin->data << ' ';
        begin = begin->next;
    }
    cout << endl;
}

// Шаблонная функция поиска элемента в линейном списке.
// Входные параметры:
//     begin - указатель на начало списка;
//     x - искомое значение.
// Возвращает указатель на первый элемент с заданным значением или
// nullptr, если элемента с таким значение в списке нет.
template <typename List, typename List_Data>
List *find(const List *begin, List_Data x)
{
    List *t = const_cast<List*>(begin);
    
    while (t != nullptr) {
        if (t->data == x)
            break;
        t = t->next;
    }
    return t;
}