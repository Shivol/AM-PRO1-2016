//
//  sort.h
//  array_sort
//
//  Created by Илья Лошкарёв on 06.03.16.
//  Copyright © 2016 Илья Лошкарёв. All rights reserved.
//

#ifndef sort_h
#define sort_h
#pragma once

#include <cassert>

/* Объявление "функционального типа".
   Теперь указатель на функции вида
     void(int *, const size_t)
   можно передавать как sort_int
*/
typedef void(* const sort_int)(int *, const size_t);

// Шаблонный swap для указателей
// из func_l3
template <typename T>
void swap( T *a, T *b)
{
    // проверка нулевого указателя
    assert(a != nullptr);
    assert(b != nullptr);

    T tmp = *b;
    *b = *a;
    *a = tmp;
}

// Функция сортировки массива 
// алгоритмом быстрой сортировкаи
// Параметры:
//     a — массив для сортировки;
//     n — длна массива a.
void qsort(int *a, const size_t n);

// Функция вычисления времени работы функции сортировки
// Параметры:
//     sort — указатель на функцию сортировки;
//     a — массив для сортировки;
//     n — длна массива a.
// Возращаемое значение:
// время работы функции в секундах.
double sort_time_in_seconds_for( sort_int sort, int* a, const size_t n);

#endif /* sort_h */
