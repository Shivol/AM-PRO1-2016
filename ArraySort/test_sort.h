//
//  test_sort.hpp
//  array_sort
//
//  Created by Илья Лошкарёв on 06.03.16.
//  Copyright © 2016 Илья Лошкарёв. All rights reserved.
//

#ifndef test_sort_hpp
#define test_sort_hpp
#pragma once

#include "sort.h"

// Функция тестирования функций сортировки
// Параметры:
//     sort — указатель на функцию;
//     sort_name — имя тестируемой функции.
// Результат:
// true, если все тесты завершились удачно.
bool test_name_sort_int( sort_int sort, char* sort_name );

// Немного магии препроцессора и можно вызвать 
// функцию тестирования без указания имени тестируемой функции
#define test_sort_int(sort) test_name_sort_int(sort, #sort)

#endif /* test_sort_hpp */
