//
// Лабораторная работа №2. Библиотека функций
// func_l2.cpp
//

#include <cmath>
#include "func_l2.h"

inline double sqr(double x)
{
    return x*x;
}

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(sqr(x2 - x1) + sqr(y2 - y1));  // здесь вместо вызова функции sqr
                                               // компилятор постарается подставить её возвращаемое значение
}