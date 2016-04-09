//
// Лабораторная работа №4. Динамические массивы.
//
#pragma once

#include <initializer_list>
// Инициализация динамического массива
// с помощь списка инициализации
// int *a = niti_with({1,2,3});
template <typename T>
T *init_with(std::initializer_list<T> list)
{
    T *a = new T[list.size()];
    int i = 0;
    for (auto l = list.begin(); l != list.end(); ++l)
        a[i++] = *l;
    return a;
}

bool test_find_zeros();

bool test_duplicate_between_zeros();

bool test_dynarr_full();
