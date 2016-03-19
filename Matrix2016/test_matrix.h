//
// Лабораторная раюота №7. Двумерные массивы
// test_matrix.h
//
// Тесты функций matrix.cpp

#pragma once

#include <iostream>
#include <fstream>
#include "matrix.h"

// Тестирование шаблона функции:
// template <typename T> 
// bool is_equal(const T a, const T b, const size_t m, const size_t n, const double precision = 0.0)
// Входнве данные:
//     fname - имя файла с тестовыми данными.
// Файл тестовых данных должен содержать как минимум две матрицы.
bool test_is_equal(const char* fname);